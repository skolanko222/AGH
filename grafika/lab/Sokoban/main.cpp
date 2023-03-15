#include "SFML/Graphics.hpp"
#include <fstream>
#include <cmath>
#include <vector>
#include <iostream>

enum class Field {
	VOID, FLOOR, WALL, BOX, PARK, PLAYER, CLOUD
};

class Sokoban : public sf::Drawable {
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

void Sokoban::LoadMapFromFile(std::string fileName) {
	std::string str;
	std::vector<std::string> vos;

	std::ifstream in(fileName.c_str());
	while (std::getline(in, str)) { vos.push_back(str); }
	in.close();

	map.clear();
	map.resize(vos.size(), std::vector<Field>(vos[0].size()));
	for (auto [row, row_end, y] = std::tuple{ vos.cbegin(), vos.cend(), 0 }; row != row_end; ++row, ++y)
		for (auto [element, end, x] = std::tuple{ row->begin(), row->end(), 0 }; element != end; ++element, ++x)
			switch (*element) {
			case 'X':
				map[y][x] = Field::WALL;
				break;
			case '*':
				map[y][x] = Field::VOID;
				break;
			case ' ':
				map[y][x] = Field::FLOOR;
				break;
			case 'B':
				map[y][x] = Field::BOX;
				break;
			case 'P':
				map[y][x] = Field::PARK;
				park_positions.push_back(sf::Vector2i(x, y));
				break;
			case 'S':
				map[y][x] = Field::PLAYER;
				player_position = sf::Vector2i(x, y);
				break;
			case 'C':
				map[y][x] = Field::CLOUD;
				break;
			}
}

void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	// Tu niewątpliwie powinno coś być : -) Tu należy narysować wszystko. O tak jakoś :
	//target.draw(....);
	sf::Sprite sprite;
	sf::Texture texture;

	//Przydatna może być pętla :
	for (int y = 0; y < map.size(); ++y)
		for (int x = 0; x < map[y].size(); ++x) {
			//Teraz map[y][x] mówi nam CO mamy narysować.
			if (map[y][x] == Field::WALL)
				texture.loadFromFile("wall.png");
			else if (map[y][x] == Field::VOID)
				texture.loadFromFile("sky.png");
			else if (map[y][x] == Field::FLOOR)
				texture.loadFromFile("planks.png");
			else if (map[y][x] == Field::BOX)
				texture.loadFromFile("minecart.png");
			else if (map[y][x] == Field::PARK)
				texture.loadFromFile("park.png");
			else if (map[y][x] == Field::PLAYER)
				texture.loadFromFile("steve.png");
			else if (map[y][x] == Field::CLOUD)
				texture.loadFromFile("cloud.png");
			sprite.setTexture(texture);
			sprite.setPosition(x * tile_size.x + shift.x, y * tile_size.y + shift.y);
			sprite.setScale(sf::Vector2f(tile_size.x / texture.getSize().x, tile_size.y / texture.getSize().y));
			target.draw(sprite, states);
		}
	
}

void Sokoban::SetDrawParameters(sf::Vector2u draw_area_size) {
	this->tile_size = sf::Vector2f(
		std::min(floor((float)draw_area_size.x / (float)map[0].size()),
			floor((float)draw_area_size.y / (float)map.size())),
		std::min(floor((float)draw_area_size.x / (float)map[0].size()),
			floor((float)draw_area_size.y / (float)map.size()))
	);
	this->shift = sf::Vector2f(
		((float)draw_area_size.x - this->tile_size.x * map[0].size()) / 2.0f,
		((float)draw_area_size.y - this->tile_size.y * map.size()) / 2.0f
	);
}

void Sokoban::Move_Player_Left() {
	move_player(-1, 0);
}

void Sokoban::Move_Player_Right() {
	move_player(1, 0);
}

void Sokoban::Move_Player_Up() {
	move_player(0, -1);
}

void Sokoban::Move_Player_Down() {
	move_player(0, 1);
}

void Sokoban::move_player(int dx, int dy) {
	bool allow_move = false; // Pesymistyczne załóżmy, że gracz nie może się poruszyć.
	sf::Vector2i new_pp(player_position.x + dx, player_position.y + dy); //Potencjalna nowa pozycja gracza.
	Field fts = map[new_pp.y][new_pp.x]; //Element na miejscu na które gracz zamierza przejść.
	Field ftsa = map[new_pp.y + dy][new_pp.x + dx]; //Element na miejscu ZA miejscem na które gracz zamierza przejść. :-D

	//Gracz może się poruszyć jeśli pole na którym ma stanąć to podłoga lub miejsce na skrzynki.
	if (fts == Field::FLOOR || fts == Field::PARK) allow_move = true;
	//Jeśli pole na które chce się poruszyć gracz zawiera skrzynkę to może się on poruszyć jedynie jeśli kolejne pole jest puste lub zawiera miejsce na skrzynkę  - bo wtedy może przepchnąć skrzynkę.
	if (fts == Field::BOX && (ftsa == Field::FLOOR || ftsa == Field::PARK)) {
		allow_move = true;
		//Przepychamy skrzynkę.
		map[new_pp.y + dy][new_pp.x + dx] = Field::BOX;
		//Oczywiście pole na którym stała skrzynka staje się teraz podłogą.
		map[new_pp.y][new_pp.x] = Field::FLOOR;
	}

	if (allow_move) {
		//Przesuwamy gracza.
		map[player_position.y][player_position.x] = Field::FLOOR;
		player_position = new_pp;
		map[player_position.y][player_position.x] = Field::PLAYER;
	}

	//Niestety w czasie ruchu mogły „ucierpieć” miejsca na skrzynkę. ;-(
	for (auto park_position : park_positions) if (map[park_position.y][park_position.x] == Field::FLOOR)
		map[park_position.y][park_position.x] = Field::PARK;
}

bool Sokoban::Is_Victory() const {
	//Tym razem dla odmiany optymistycznie zakładamy, że gracz wygrał.
	//No ale jeśli na którymkolwiek miejscu na skrzynki nie ma skrzynki to chyba założenie było zbyt optymistyczne... : -/
	for (auto park_position : park_positions) if (map[park_position.y][park_position.x] != Field::BOX) return false;
	return true;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "GFK Lab 01",
		sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	Sokoban sokoban;

	sokoban.LoadMapFromFile("plansza.txt");
	sokoban.SetDrawParameters(window.getSize());

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Resized) {
				float width = static_cast<float>(event.size.width);
				float height = static_cast<float>(event.size.height);
				window.setView(sf::View(sf::FloatRect(0, 0, width, height)));
				sokoban.SetDrawParameters(window.getSize());
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Left)
					sokoban.Move_Player_Left();
				else if (event.key.code == sf::Keyboard::Right)
					sokoban.Move_Player_Right();
				else if (event.key.code == sf::Keyboard::Down)
					sokoban.Move_Player_Down();
				else if (event.key.code == sf::Keyboard::Up)
					sokoban.Move_Player_Up();
				else if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
			if (sokoban.Is_Victory()) {
				window.close();
				std::cout << "GAME OVER\nYOU WON!" << std::endl;
			}

			//Oczywiście tu powinny zostać jakoś obsłużone inne zdarzenia.Na przykład jak gracz naciśnie klawisz w lewo powinno pojawić się wywołanie metody :
			//sokoban.Move_Player_Left();
			//W dowolnym momencie mogą Państwo sprawdzić czy gracz wygrał:
			//sokoban.Is_Victory();
		}
		window.draw(sokoban);
		window.display();
	}

	return 0;
}