//Uwaga! Co najmniej C++17!!!
//Project-> ... Properties->Configuration Properties->General->C++ Language Standard = ISO C++ 17 Standard (/std:c++17)

#include <SFML/Graphics.hpp>
#include <fstream>
#include <cmath>
#include <iostream>

enum class Field { VOID, FLOOR, WALL, BOX, PARK, PLAYER, NONE};

class Sokoban : public sf::Drawable
{
public:
	Sokoban(sf::RenderWindow & w, std::string _font = "font.ttf"): window(w) {font.loadFromFile(_font); }
	void LoadMapFromFile(std::string fileName);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void SetDrawParameters(sf::Vector2u draw_area_size);
	void Move_Player_Left();
	void Move_Player_Right();
	void Move_Player_Up();
	void Move_Player_Down();
	bool Is_Victory() const;
	void refresh()
	{
		window.clear(sf::Color(80, 80, 80));
		for(short i = 0; i < map_last.size(); i++)
			for(short j = 0; j < map_last[0].size(); j++)
				map_last[i][j] = Field::NONE;
		
	}
	double time = 0.;
	double time_last = -1.;

private:
	std::vector<std::vector<Field>> map;
    std::vector<std::vector<Field>> map_last;
	sf::Vector2f shift; //środek
	sf::Vector2f tile_size; //rozmiar kwadratu
	sf::Vector2i player_position;
	std::vector<sf::Vector2i> park_positions;
	sf::Font font;
	Field timer_tile;
	sf::RenderWindow & window;
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
    map_last.resize(vos.size(), std::vector<Field>(vos[0].size()));
	for (auto [row, row_end, y] = std::tuple{ vos.cbegin(), vos.cend(), 0 }; row != row_end; ++row, ++y)
		for (auto [element, end, x] = std::tuple{ row->begin(), row->end(), 0 }; element != end; ++element, ++x)
        {
			switch (*element)
			{
			case 'X': map[y][x] = Field::WALL; break;
			case '*': map[y][x] = Field::VOID; break;
			case ' ': map[y][x] = Field::FLOOR; break;
			case 'B': map[y][x] = Field::BOX; break;
			case 'P': map[y][x] = Field::PARK; park_positions.push_back(sf::Vector2i(x,y));  break;
			case 'S': map[y][x] = Field::PLAYER; player_position = sf::Vector2i(x,y);  break;
            }
			map_last[y][x] = map[y][x];
        }
	timer_tile = map[0][0];
}

void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Tu niewątpliwie powinno coś być : -) Tu należy narysować wszystko. O tak jakoś :
	
	//Przydatna może być pętla :
	sf::Texture textura;
	sf::Sprite sprite;
	sf::Text timer;
	if((time - time_last) > 1)
	{	
		(const_cast<Sokoban *>(this))->map_last[0][0] = Field::NONE;
		std::cout << time_last - time << '\n';
		timer.setFont(font);
		timer.setFillColor(sf::Color::Red);
		timer.setCharacterSize(tile_size.x/2.);
		timer.setString(std::to_string(int(time)));
		target.draw(timer);
		window.clear(sf::Color(80, 80, 80));
		(const_cast<Sokoban *>(this))->time_last+=1;

	}
	for (int y = 0; y < map.size(); ++y)
		for (int x = 1; x < map[y].size()+1; ++x)
		{
            if(map_last[y][x] != map[y][x] )
            {
                switch (map[y][x])
                {
					case Field::WALL: textura.loadFromFile("wall.png"); break;
					case Field::VOID: textura.loadFromFile("void.png"); break;
					case Field::FLOOR: textura.loadFromFile("floor.png"); break;
					case Field::BOX: textura.loadFromFile("box.png"); break;
					case Field::PARK: textura.loadFromFile("park.png"); break;
					case Field::PLAYER: textura.loadFromFile("player.png"); break;
                }
                sprite.setTexture(textura);
                sprite.setPosition(x*tile_size.x, y*tile_size.y);
                sprite.setScale(sf::Vector2f(tile_size.x/textura.getSize().x,tile_size.y/textura.getSize().y));
                target.draw(sprite);
            }
		}
	target.draw(timer);
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
   	map_last = map;
	bool allow_move = false; // Pesymistyczne załóżmy, że gracz nie może się poruszyć.
	sf::Vector2i new_pp(player_position.x + dx,player_position.y + dy); //Potencjalna nowa pozycja gracza.
	Field fts = map[new_pp.y][new_pp.x]; //Element na miejscu na które gracz zamierza przejść.
	Field ftsa = map[new_pp.y + dy][new_pp.x + dx]; //Element na miejscu ZA miejscem na które gracz zamierza przejść. :-D
	
	//Gracz może się poruszyć jeśli pole na którym ma stanąć to podłoga lub miejsce na skrzynki.
	if (fts == Field::FLOOR || fts == Field::PARK) allow_move = true;
	//Jeśli pole na które chce się poruszyć gracz zawiera skrzynkę to może się on poruszyć jedynie jeśli kolejne pole jest puste lub zawiera miejsce na skrzynkę  - bo wtedy może przepchnąć skrzynkę.
	if (fts == Field::BOX && (ftsa == Field::FLOOR || ftsa == Field::PARK))
	{
		allow_move = true;
		//Przepychamy skrzynkę.
		map[new_pp.y + dy][new_pp.x + dx] = Field::BOX;
		//Oczywiście pole na którym stała skrzynka staje się teraz podłogą.
		map[new_pp.y][new_pp.x] = Field::FLOOR;
	}
	
	if (allow_move)
	{
		//Przesuwamy gracza.
		map[player_position.y][player_position.x] = Field::FLOOR;
		player_position = new_pp;
		map[player_position.y][player_position.x] = Field::PLAYER;
	}
	//															      \	
	//Niestety w czasie ruchu mogły „ucierpieć” miejsca na skrzynkę. :D
	for (auto park_position : park_positions) if (map[park_position.y][park_position.x] == Field::FLOOR) map[park_position.y][park_position.x] = Field::PARK;
}

bool Sokoban::Is_Victory() const
{
	//Tym razem dla odmiany optymistycznie zakładamy, że gracz wygrał.
	//No ale jeśli na którymkolwiek miejscu na skrzynki nie ma skrzynki to chyba założenie było zbyt optymistyczne... : -/
	for (auto park_position : park_positions) if (map[park_position.y][park_position.x] != Field::BOX) return false;
	return true;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "GFK Lab 01", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    Sokoban sokoban(window);

    sokoban.LoadMapFromFile("plansza.txt");
    sokoban.SetDrawParameters(window.getSize());
    sf::Clock clock;
	
    window.clear(sf::Color(80, 80, 80));
	window.draw(sokoban);

    while (window.isOpen())
    {
	    sf::Time currentTime = clock.restart();	
        sf::Event event;
		
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Resized)
            {
                float width = static_cast<float>(event.size.width);
                float height = static_cast<float>(event.size.height);
                window.setView(sf::View(sf::FloatRect(0, 0, width, height)));
                sokoban.SetDrawParameters(window.getSize());
				sokoban.refresh();

            }
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)  sokoban.Move_Player_Left();
                if (event.key.code == sf::Keyboard::Right) sokoban.Move_Player_Right();
                if (event.key.code == sf::Keyboard::Up)    sokoban.Move_Player_Up();
                if (event.key.code == sf::Keyboard::Down)  sokoban.Move_Player_Down();
				if (event.key.code == sf::Keyboard::R)  sokoban.LoadMapFromFile("plansza.txt");

                
            }
        }
		// if((sokoban.time - sokoban.time_last) > 1)
		// {
		//  	sokoban.time_last += 1.;
		//  	std::cout << sokoban.time - sokoban.time_last << '\n';
		// }
	
    window.draw(sokoban);
	window.display();
    if(sokoban.Is_Victory() == true)
    {
		sf::sleep(sf::seconds(2));

        window.close();
    }
	
    float fps = 1.0f/currentTime.asSeconds();
	std::cout << "fps: " << fps << "\n";
	std::cout << "timer: " << sokoban.time << "\n\n";
	sokoban.time += currentTime.asSeconds();
    }

 return 0;
}