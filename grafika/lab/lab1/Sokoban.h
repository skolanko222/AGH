#pragma once
#include "Sokoban.cpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cmath>
#include <iostream>

enum class Field { VOID, FLOOR, WALL, BOX, PARK, PLAYER, NONE};

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
	void refresh()
	{
		for(short i = 0; i < map_last.size(); i++)
			for(short j = 0; j < map_last[0].size(); j++)
				map_last[i][j] = Field::NONE;
	}

private:
	std::vector<std::vector<Field>> map;
    std::vector<std::vector<Field>> map_last;
	sf::Vector2f shift; //środek
	sf::Vector2f tile_size; //rozmiar kwadratu
	sf::Vector2i player_position;
	std::vector<sf::Vector2i> park_positions;
	void move_player(int dx, int dy);

};