#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

class Slider : public sf::Drawable
{
private:
	float sliderX; // zawsze OFFSET/2 od prawej krawędzi
	float sliderY;

	const double sliderHeight = 275;
	const double sliderWidth = 25;

	const double sliderLineLen = 10;

	bool isSliding;

	sf::RectangleShape* sliderBounds;
	sf::Vertex* sliderGradient;

	double currLinesPosition = 0.5;

	sf::VertexArray* line;
	void setLine()
	{
		(*line)[0].position = sf::Vector2f(sliderX - 2 * sliderLineLen, sliderY + sliderHeight * currLinesPosition);
		(*line)[1].position = sf::Vector2f(sliderX + sliderWidth + 1 * sliderLineLen + sliderLineLen, sliderY + sliderHeight * currLinesPosition);
	}

public:
	Slider(float width = DEFAULT_WIDTH, float height = DEFAULT_HEIGHT)
	{
		sliderX = width - OFFSET/2.;
		sliderY = height/2. - sliderHeight/2.;
		isSliding = false;

		sliderGradient = new sf::Vertex[4]();
		
		sliderBounds = new sf::RectangleShape(sf::Vector2f(sliderWidth, sliderHeight));

		line = new sf::VertexArray(sf::LinesStrip, 2);
		(*line)[0].color = sf::Color::Black;
		(*line)[1].color = sf::Color::Black;
		
		setParams(width,height);

	}	
	void setParams(float width = DEFAULT_WIDTH, float height = DEFAULT_HEIGHT)
	{
		sliderX = width - OFFSET/2.;
		sliderY = height/2. - sliderHeight/2.;

		sliderGradient[0] = sf::Vertex(sf::Vector2f(sliderX, sliderY), sf::Color::Black);
		sliderGradient[1] = sf::Vertex(sf::Vector2f(sliderX + sliderWidth, sliderY), sf::Color::Black);
		sliderGradient[2] = sf::Vertex(sf::Vector2f(sliderX + sliderWidth, sliderY + sliderHeight), sf::Color::White);
		sliderGradient[3] = sf::Vertex(sf::Vector2f(sliderX, sliderY + sliderHeight), sf::Color::White);

		sliderBounds->setPosition(sf::Vector2f(sliderX, sliderY));
		sliderBounds->setFillColor(sf::Color::Transparent);
		sliderBounds->setOutlineColor(sf::Color::Blue);
		sliderBounds->setOutlineThickness(2);
		setLine();
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{

		target.draw(sliderGradient, 4, sf::Quads);
		target.draw(*sliderBounds);
		target.draw(*line);
	};

	float leftButtonPressed(sf::Vector2i pos)
	{
		if (pos.x <= sliderX || pos.x >= sliderX + sliderWidth) return currLinesPosition;
		if (pos.y <= sliderY || pos.y >= sliderY + sliderHeight) return currLinesPosition;

		isSliding = true;

		currLinesPosition = (pos.y - sliderY) / sliderHeight;

		if (currLinesPosition > 1) currLinesPosition = 0.999;
		if (currLinesPosition <= 0) currLinesPosition = 0.001;

		setLine();

		return currLinesPosition;
	};
	~Slider()
	{
		delete sliderBounds;
		delete[] sliderGradient;
		delete line;

	};
};