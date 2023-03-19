//Uwaga! Co najmniej C++17!!!
//Project-> ... Properties->Configuration Properties->General->C++ Language Standard == ISO C++ 17 Standard (/std:c++17)

#include "SFML/Graphics.hpp"
#include "ShareTechMono-Regular.h"
#include <numeric>
#include <memory>
#include <iostream>
#include <cmath>


//Tak – dobrze państwo widzą – TO jest zmienna globalna! Czytanie i przetwarzanie fontów w SFML jest bardzo kosztowne. Dlatego zrobimy to raz. 
//Co nie zmienia faktu, że można by to zrobić bez zmiennej globalnej i to całkiem ładnie. Jak? To już dla Państwa :-)
std::shared_ptr<sf::Font> font;

class hexagon : public sf::Drawable
{
protected:
    sf::Vector2f left_top, right_bottom, center;
    sf::Vector2f p[6]; // Kolejność punktów opisana w pliku PDF do laboratorium.
public:
    void Set_Borders(sf::Vector2f _left_top, sf::Vector2f _right_bottom);
    void Draw_Border(sf::RenderTarget& target, sf::RenderStates states, sf::String name) const;
    bool rhombus(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p, float& alpha, float& beta) const;
private:
    float d_coefficient(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p) const;
};
//Trochę matematyki jeszcze nikomu nie zaszkodziło. Więc dwie kolejne metody to czysta matematyka.
float hexagon::d_coefficient(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p) const
{
    float A = p0.y - p1.y;
    float B = p1.x - p0.x;
    float C = p0.x * (p1.y - p0.y) - p0.y * (p1.x - p0.x);

    return 2 * ((A * p.x + B * p.y + C) / sqrt(A * A + B * B)) / sqrt(3.0f);
}

bool hexagon::rhombus(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p, float& alpha, float& beta) const
{
    float L = sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y));
    sf::Vector2f p3(0.5f * (p0.x - p1.x) + 0.5f * sqrt(3.0f) * (p1.y - p0.y) + p0.x, 0.5f * sqrt(3.0f) * (p0.x - p1.x) - 0.5f * (p1.y - p0.y) + p0.y);

    beta = -d_coefficient(p0, p1, p) / L;
    alpha = d_coefficient(p0, p3, p) / L;

    if ((alpha > 1.0f) || (beta > 1.0f) || (alpha < 0.0f) || (beta < 0.0f)) return false; else return true;
}

void hexagon::Set_Borders(sf::Vector2f _left_top, sf::Vector2f _right_bottom)
{
    left_top = _left_top;
    right_bottom = _right_bottom;
    float a = ((right_bottom.y - left_top.y) / 2.0f + 0.5f) - 20.0f;
    center = left_top + sf::Vector2f((right_bottom.x - left_top.x) / 2.0f + 0.5f, (right_bottom.y - left_top.y) / 2.0f + 0.5f + 10);

    p[0] = center - sf::Vector2f( 0.0f, a);
    p[1] = center - sf::Vector2f(0.5f * sqrt(3.0f) * a, 0.5f * a);
    p[2] = center - sf::Vector2f(0.5f * sqrt(3.0f) * a, -0.5f * a);
    p[3] = center + sf::Vector2f(0.0f, a);
    p[4] = center + sf::Vector2f(0.5f * sqrt(3.0f) * a, 0.5f * a);
    p[5] = center + sf::Vector2f(0.5f * sqrt(3.0f) * a, -0.5f * a);
}

void hexagon::Draw_Border(sf::RenderTarget& target, sf::RenderStates states, sf::String name) const
{
    sf::ConvexShape convex;
    convex.setPointCount(6);
    for (int i = 0; i < 6; i++)
    {
        convex.setPoint(i, p[i]);
    }
    convex.setFillColor(sf::Color::Transparent);
    convex.setOutlineColor(sf::Color::Black);
    convex.setOutlineThickness(1);
    target.draw(convex, states);
    
    sf::Text text;
    text.setFont(*font);
    text.setString(name);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(left_top.x + 20, left_top.y + 20);
    target.draw(text, states);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(right_bottom.x - left_top.x - 30, right_bottom.y - left_top.y - 10));
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(left_top.x + 20, left_top.y + 20);
    target.draw(rectangle, states);
}

class hexagon_RGB : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

void hexagon_RGB::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}
class hexagon_CMY : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

void hexagon_CMY::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //Tu trzeba narysować sześciokąt CMY.
    sf::VertexArray vertices(sf::Triangles, 6 * 3);
    for (int i = 0; i < 6; i++)
    {
        vertices[3 * i].position = p[i];
        vertices[3 * i + 1].position = p[(i + 1) % 6];
        vertices[3 * i + 2].position = center;
    }
    vertices[0].color = sf::Color::Cyan;
    vertices[1].color = sf::Color::Blue;
    vertices[2].color = sf::Color::Black;
    vertices[3].color = sf::Color::Blue;
    vertices[4].color = sf::Color::Magenta;
    vertices[5].color = sf::Color::Black;
    vertices[6].color = sf::Color::Magenta;
    vertices[7].color = sf::Color::Red;
    vertices[8].color = sf::Color::Black;
    vertices[9].color = sf::Color::Red;
    vertices[10].color = sf::Color::Yellow;
    vertices[11].color = sf::Color::Black;
    vertices[12].color = sf::Color::Yellow;
    vertices[13].color = sf::Color::Green;
    vertices[14].color = sf::Color::Black;
    vertices[15].color = sf::Color::Green;
    vertices[16].color = sf::Color::Cyan;
    vertices[17].color = sf::Color::Black;
    target.draw(vertices, states);
    Draw_Border(target, states, "CMY");
}

class hexagon_HSL : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

void hexagon_HSL::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //Tu trzeba narysować sześciokąt HSL.
    sf::VertexArray vertices(sf::Triangles, 6 * 3);
    for (int i = 0; i < 6; i++)
    {
        vertices[3 * i].position = p[i];
        vertices[3 * i + 1].position = p[(i + 1) % 6];
        vertices[3 * i + 2].position = center;
    }
    vertices[0].color = sf::Color::Red;
    vertices[1].color = sf::Color::Yellow;
    vertices[2].color = sf::Color::White;
    vertices[3].color = sf::Color::Yellow;
    vertices[4].color = sf::Color::Green;
    vertices[5].color = sf::Color::White;
    vertices[6].color = sf::Color::Green;
    vertices[7].color = sf::Color::Cyan;
    vertices[8].color = sf::Color::White;
    vertices[9].color = sf::Color::Cyan;
    vertices[10].color = sf::Color::Blue;
    vertices[11].color = sf::Color::White;
    vertices[12].color = sf::Color::Blue;
    vertices[13].color = sf::Color::Magenta;
    vertices[14].color = sf::Color::White;
    vertices[15].color = sf::Color::Magenta;
    vertices[16].color = sf::Color::Red;
    vertices[17].color = sf::Color::White;
    target.draw(vertices, states);
    Draw_Border(target, states, "HSL");
}

class hexagon_HSB : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

void hexagon_HSB::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //Tu trzeba narysować sześciokąt HSB.

    Draw_Border(target, states, "HSB");
}

int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 600), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
 
 hexagon_RGB h_RGB;
 hexagon_CMY h_CMY;
 hexagon_HSL h_HSL;
 hexagon_HSB h_HSB;

 sf::Clock frame_clock, around_half_secound_clock;
 sf::Int64 mean_frames_time = 0;
 std::vector<sf::Int64> frame_times;
 sf::Text text;
sf::RectangleShape slider;
slider.setFillColor(sf::Color(128, 128, 128));
 font = std::make_shared<sf::Font>();
 font->loadFromMemory(&(ShareTechMono_Regular_ttf[0]), ShareTechMono_Regular_ttf.size());
 text.setFont(*font);
 text.setCharacterSize(21);
 text.setFillColor(sf::Color::Black);

 //Nie mogę uniknąć tych "magic numbers" bo bym zdradził w ten sposób co ma być w sf::Event::Resize. A tego byśmy nie chcieli - prawda? :-D
 text.setPosition(sf::Vector2f(window.getSize().x - 120, window.getSize().y - 50));
 h_RGB.Set_Borders(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(300.0f,294.0f));
 h_CMY.Set_Borders(sf::Vector2f(300.0f, 0.0f), sf::Vector2f(600.0f, 294.0f));
 h_HSL.Set_Borders(sf::Vector2f(0.0f, 294.0f), sf::Vector2f(300.0f, 588.0f));
 h_HSB.Set_Borders(sf::Vector2f(300.0f, 294.0f), sf::Vector2f(600.0f, 588.0f));
 slider.setSize(sf::Vector2f(50, 450));
 slider.setPosition(sf::Vector2f(window.getSize().x - 120,70)); 
 around_half_secound_clock.restart();

 while (window.isOpen())
 {
  sf::Event event;
  window.clear(sf::Color::White);

  frame_clock.restart(); // Start pomiaru czasu.

  while (window.pollEvent(event))
  {
      if (event.type == sf::Event::Closed) window.close();
      else if (event.type == sf::Event::Resized)
      {
          // Tu trzeba obsłużyć zdarzenia: zmianę rozmiaru okna oraz klikanie w „suwaczek”.
          window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
          // resize hexagons but leave 1/4th of the window clear on the right side
        window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        h_RGB.Set_Borders(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(event.size.width / 2 -100, event.size.height / 2));
        h_CMY.Set_Borders(sf::Vector2f(event.size.width / 2 -100, 0.0f), sf::Vector2f(event.size.width-200, event.size.height / 2));
        h_HSL.Set_Borders(sf::Vector2f(0.0f, event.size.height / 2), sf::Vector2f(event.size.width / 2 -100, event.size.height -10));
        h_HSB.Set_Borders(sf::Vector2f(event.size.width / 2 -100, event.size.height / 2), sf::Vector2f(event.size.width -200, event.size.height-10));
        text.setPosition(sf::Vector2f(event.size.width - 120, event.size.height - 50));
        slider.setSize(sf::Vector2f(50, event.size.height/4*3));
        slider.setPosition(sf::Vector2f(event.size.width - 120,event.size.height/8));
      }
      if(event.type == sf::Event::MouseButtonPressed)
      {
          if(event.mouseButton.button == sf::Mouse::Left)
          {
              // check if the mouse is in the slider
              if(event.mouseButton.x > slider.getPosition().x && event.mouseButton.x < slider.getPosition().x + slider.getSize().x && event.mouseButton.y > slider.getPosition().y && event.mouseButton.y < slider.getPosition().y + slider.getSize().y)
              {
                  // if it is, change the brightness of the hexagons
                  float brightness = (event.mouseButton.y - slider.getPosition().y) / slider.getSize().y;               
              }
          }
      }
  }
  //create a grey rectangle above the 'text' and name it slider which scales with the window so it is always in the same place relative to the window
    //sf::RectangleShape slider;
    //slider.setSize(sf::Vector2f(50,500));
  window.draw(slider);
  window.draw(h_RGB);
  window.draw(h_CMY);
  window.draw(h_HSL);
  window.draw(h_HSB);  
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