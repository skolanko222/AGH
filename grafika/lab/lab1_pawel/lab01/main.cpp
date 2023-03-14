#include "SFML/Graphics.hpp"
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

enum class Field { VOID, FLOOR, WALL, BOX, PARK, PLAYER };

class Sokoban : public sf::Drawable
{
public:
	void LoadMapFromFile(std::string fileName);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void SetDrawParameters(sf::Vector2u draw_area_size);
	void Move_Player_Left();
	void Move_Player_Right();
	void Move_Player_Up();
	void Move_Player_Down();
	bool Is_Victory() const;

private:
	std::vector<std::vector<Field>> map;
	sf::Vector2f shift, tile_size;
	sf::Vector2i player_position;
	std::vector<sf::Vector2i> park_positions;

	void move_player(int dx, int dy);
};

void Sokoban::LoadMapFromFile(std::string fileName)
{
	std::string str;
	std::vector<std::string> vos;

	std::ifstream in(fileName.c_str());
	while (std::getline(in, str)) { vos.push_back(str); }
	in.close();

	map.clear();
	map.resize(vos.size(), std::vector<Field>(vos[0].size()));
	for (auto [row, row_end, y] = std::tuple{ vos.cbegin(), vos.cend(), 0 }; row != row_end; ++row, ++y)
		for (auto [element, end, x] = std::tuple{ row->begin(), row->end(), 0 }; element != end; ++element, ++x)
			switch (*element)
			{
			case 'X': map[y][x] = Field::WALL; break;
			case '*': map[y][x] = Field::VOID; break;
			case ' ': map[y][x] = Field::FLOOR; break;
			case 'B': map[y][x] = Field::BOX; break;
			case 'P': map[y][x] = Field::PARK; park_positions.push_back(sf::Vector2i(x, y));  break;
			case 'S': map[y][x] = Field::PLAYER; player_position = sf::Vector2i(x, y);  break;
			}
}

void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Texture tex;
	sf::Sprite sprit;

	for (int y = 0; y < map.size(); ++y)
		for (int x = 0; x < map[y].size(); ++x)
		{
			switch (map[y][x]) {
			case Field::WALL:
				tex.loadFromFile("wall.png");
				break;
			case Field::VOID:
				tex.loadFromFile("void.png");
				break;
			case Field::FLOOR:
				tex.loadFromFile("floor.png");
				break;
			case Field::BOX:
				tex.loadFromFile("box.png");
				break;
			case Field::PARK:
				tex.loadFromFile("park.png");
				break;
			case Field::PLAYER:
				tex.loadFromFile("player2.png");
				break;
			}
			sprit.setTexture(tex);
			sprit.setPosition(x * tile_size.x + shift.x, y * tile_size.y + shift.y);
			sprit.setScale(sf::Vector2f(tile_size.x / tex.getSize().x, tile_size.y / tex.getSize().y));
		}
}

void Sokoban::SetDrawParameters(sf::Vector2u draw_area_size)
{
	this->tile_size = sf::Vector2f(
		std::min(std::floor((float)draw_area_size.x / (float)map[0].size()), std::floor((float)draw_area_size.y / (float)map.size())),
		std::min(std::floor((float)draw_area_size.x / (float)map[0].size()), std::floor((float)draw_area_size.y / (float)map.size()))
	);
	this->shift = sf::Vector2f(
		((float)draw_area_size.x - this->tile_size.x * map[0].size()) / 2.0f,
		((float)draw_area_size.y - this->tile_size.y * map.size()) / 2.0f
	);
}

void Sokoban::Move_Player_Left()
{
	move_player(-1, 0);
}

void Sokoban::Move_Player_Right()
{
	move_player(1, 0);
}

void Sokoban::Move_Player_Up()
{
	move_player(0, -1);
}

void Sokoban::Move_Player_Down()
{
	move_player(0, 1);
}

void Sokoban::move_player(int dx, int dy)
{
	bool allow_move = false; // Pesymistyczne za��my, �e gracz nie mo�e si� poruszy�.
	sf::Vector2i new_pp(player_position.x + dx, player_position.y + dy); //Potencjalna nowa pozycja gracza.
	Field fts = map[new_pp.y][new_pp.x]; //Element na miejscu na kt�re gracz zamierza przej��.
	Field ftsa; //Element na miejscu ZA miejscem na kt�re gracz zamierza przej��. :-D

	//Gracz mo�e si� poruszy� je�li pole na kt�rym ma stan�� to pod�oga lub miejsce na skrzynki.
	if (fts == Field::FLOOR || fts == Field::PARK) allow_move = true;
	//Je�li pole na kt�re chce si� poruszy� gracz zawiera skrzynk� to mo�e si� on poruszy� jedynie je�li kolejne pole jest puste lub zawiera miejsce na skrzynk�  - bo wtedy mo�e przepchn�� skrzynk�.
	if (fts == Field::BOX)
	{
		ftsa = map[new_pp.y + dy][new_pp.x + dx];
		if(ftsa == Field::FLOOR || ftsa == Field::PARK)
		{
			allow_move = true;
			//Przepychamy skrzynk�.
			map[new_pp.y + dy][new_pp.x + dx] = Field::BOX;
			//Oczywi�cie pole na kt�rym sta�a skrzynka staje si� teraz pod�og�.
			map[new_pp.y][new_pp.x] = Field::FLOOR;
		}
	}

	if (allow_move)
	{
		//Przesuwamy gracza.
		map[player_position.y][player_position.x] = Field::FLOOR;
		player_position = new_pp;
		map[player_position.y][player_position.x] = Field::PLAYER;
	}

	//Niestety w czasie ruchu mog�y �ucierpie� miejsca na skrzynk�. ;-(
	for (auto park_position : park_positions) if (map[park_position.y][park_position.x] == Field::FLOOR) map[park_position.y][park_position.x] = Field::PARK;
}

bool Sokoban::Is_Victory() const
{
	//Tym razem dla odmiany optymistycznie zak�adamy, �e gracz wygra�.
	//No ale je�li na kt�rymkolwiek miejscu na skrzynki nie ma skrzynki to chyba za�o�enie by�o zbyt optymistyczne... : -/
	for (auto park_position : park_positions) if (map[park_position.y][park_position.x] != Field::BOX) return false;
	return true;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GFK Lab 01", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	Sokoban sokoban;

	sokoban.LoadMapFromFile("plansza1.txt");
	sokoban.SetDrawParameters(window.getSize());

	sf::Clock clock;

	sf::Font font;
	font.loadFromFile("timer.ttf");
	
	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(window.getSize().x/20);
	text.setPosition(0, 0);

	while (window.isOpen())
	{
		sf::Event event;

		sf::Time elapsed = clock.getElapsedTime();
		std::cout << "FPS: " << 1./elapsed.asSeconds() << '\n';
		std::string result = std::to_string((int)elapsed.asSeconds());
		text.setString(result);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::Resized)
			{
				float width = static_cast<float>(event.size.width);
				float height = static_cast<float>(event.size.height);
				window.setView(sf::View(sf::FloatRect(0, 0, width, height)));
				sokoban.SetDrawParameters(window.getSize());
				
				text.setCharacterSize(std::max((height/20),(width/20)));
				
			}
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
					sokoban.Move_Player_Left();
					break;
				case sf::Keyboard::Right:
					sokoban.Move_Player_Right();
					break;
				case sf::Keyboard::Up:
					sokoban.Move_Player_Up();
					break;
				case sf::Keyboard::Down:
					sokoban.Move_Player_Down();
					break;
				}
			}
			if (sokoban.Is_Victory()) {
				sf::Text win;
				win.setFont(font);
				win.setFillColor(sf::Color::White);
				win.setCharacterSize(64);
				win.setPosition(0, 0);
				win.setString("Gratulacje!");
				window.clear(sf::Color(79, 78, 75));
				window.draw(sokoban);
				window.draw(win);
				window.display();
				window.close();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}			
		}
		window.clear(sf::Color(79, 78, 75));
		window.draw(sokoban);
		window.draw(text);
		window.display();
	}

	return 0;
}