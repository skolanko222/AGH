//Uwaga! Co najmniej C++17!!!
//Project-> ... Properties->Configuration Properties->General->C++ Language Standard == ISO C++ 17 Standard (/std:c++17)
#define OFFSET 200

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

#define DEFAULT_SLIDER_HEIGHRT 40

#include "SFML/Graphics.hpp"
#include "ShareTechMono-Regular.h"
#include "slider.h"
#include "things.h"
#include <numeric>
#include <iostream>
#include <memory>
#include <cmath>


//Tak – dobrze państwo widzą – TO jest zmienna globalna! Czytanie i przetwarzanie fontów w SFML jest bardzo kosztowne. Dlatego zrobimy to raz. 
//Co nie zmienia faktu, że można by to zrobić bez zmiennej globalnej i to całkiem ładnie. Jak? To już dla Państwa :-)
std::shared_ptr<sf::Font> font;

int main()
{
 sf::RenderWindow window(sf::VideoMode(DEFAULT_WIDTH, DEFAULT_HEIGHT), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
 
 hexagon_RGB h_RGB;
 hexagon_CMY h_CMY;
 hexagon_HSL h_HSL;
 hexagon_HSB h_HSB;

 sf::Clock frame_clock, around_half_secound_clock;
 sf::Int64 mean_frames_time = 0;
 std::vector<sf::Int64> frame_times;
 sf::Text text;

 font = std::make_shared<sf::Font>();
 font->loadFromMemory(&(ShareTechMono_Regular_ttf[0]), ShareTechMono_Regular_ttf.size());
 text.setFont(*font);
 text.setCharacterSize(21);
 text.setFillColor(sf::Color::Black);

 //Nie mogę uniknąć tych "magic numbers" bo bym zdradził w ten sposób co ma być w sf::Event::Resize. A tego byśmy nie chcieli - prawda? :-D
 text.setPosition(10, 10);
 h_RGB.Set_Borders(sf::Vector2f(0.0f, 294.0f), sf::Vector2f(300.0f,294.0f));
 h_CMY.Set_Borders(sf::Vector2f(300.0f, 0.0f), sf::Vector2f(600.0f, 294.0f));
 h_HSL.Set_Borders(sf::Vector2f(0.0f, 294.0f), sf::Vector2f(300.0f, 588.0f));
 h_HSB.Set_Borders(sf::Vector2f(300.0f, 294.0f), sf::Vector2f(600.0f, 588.0f));

 around_half_secound_clock.restart();
 Slider right_slider(DEFAULT_WIDTH,DEFAULT_HEIGHT);

 while (window.isOpen())
 {
  sf::Event event;
  window.clear(sf::Color::White);

  frame_clock.restart(); // Start pomiaru czasu.

  while (window.pollEvent(event))
  {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
   if (event.type == sf::Event::Closed) window.close();
	else if(event.type == sf::Event::Resized)
	  {
        float width = static_cast<float>(event.size.width);
        float height = static_cast<float>(event.size.height);
        window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        
        h_RGB.Set_Borders(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(min(width - OFFSET,height)/2.,min(width - OFFSET,height)/2.));
        h_CMY.Set_Borders(sf::Vector2f(min(width - OFFSET,height) /2., 0.0f), sf::Vector2f(width/2.+min(width - OFFSET,height)/2., min(width - OFFSET,height)/2.));
        
        h_HSL.Set_Borders(sf::Vector2f(0.0f, min(width - OFFSET,height)/2.), sf::Vector2f(min(width - OFFSET,height)/2.,min(width - OFFSET,height)));
        h_HSB.Set_Borders(sf::Vector2f(min(width - OFFSET,height) /2., min(width - OFFSET,height)/2.), sf::Vector2f(width/2.+ min(width - OFFSET,height)/2., min(width - OFFSET,height)));
        
        right_slider.setParams(width,height);
 
	  }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        double a = right_slider.leftButtonPressed(mouse_pos); // parametr do kolorów
        std::cout << a << std::endl;
    }

      // Tu trzeba obsłużyć zdarzenia: zmianę rozmiaru okna oraz klikanie w „suwaczek”. 
  }

  window.draw(h_RGB);
  window.draw(h_CMY);
  window.draw(h_HSL);
  window.draw(h_HSB);
  // Pewnie tu gdzieś wypadało by dorysować jeszcze suwaczek... 
  window.draw(right_slider);
  text.setString(std::to_string(mean_frames_time)+ "us");
  window.draw(text);

  // Pomiar czasu uśrednimy w okresie około 1/2 sekundy.
  frame_times.push_back(frame_clock.getElapsedTime().asMicroseconds());
  if (around_half_secound_clock.getElapsedTime().asSeconds() >= 0.5f && frame_times.size() >=1)
  {
      mean_frames_time = (sf::Int64)((float)std::reduce(frame_times.begin(), frame_times.end()) / (float)frame_times.size());
      frame_times.clear();
      around_half_secound_clock.restart();
  }

  frame_clock.restart(); // Stop pomiaru czasu.
  window.display();
 }

 //Hmmm ... :-/
 font.reset();
 
 return 0;
}