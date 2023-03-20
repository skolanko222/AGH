//Uwaga! Co najmniej C++17!!!
//Project-> ... Properties->Configuration Properties->General->C++ Language Standard == ISO C++ 17 Standard (/std:c++17)

#include "SFML/Graphics.hpp"
#include "ShareTechMono-Regular.h"
#include <numeric>
#include <iostream>
#include <cmath>
#include <memory>

float brightness=1.0f;
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
    sf::VertexArray vertices(sf::Triangles, 6 * 3);
    for (int i = 0; i < 6; i++)
    {
        vertices[3 * i].position = p[i];
        vertices[3 * i + 1].position = p[(i + 1) % 6];
        vertices[3 * i + 2].position = center;
    }
    sf::Text text;
    text.setFont(*font);
    text.setString("R");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(p[0].x - 30, p[0].y - 15);
    target.draw(text, states);
    text.setString("G");
    text.setPosition(p[2].x - 15, p[2].y - 10);
    target.draw(text, states);
    text.setString("B");
    text.setPosition(p[4].x + 10, p[4].y - 10);
    target.draw(text, states);
    vertices[0].color = sf::Color(255*brightness, 0, 0);
    vertices[1].color = sf::Color(255*brightness, 255*brightness, 0);
    vertices[2].color = sf::Color(255*brightness, 255*brightness, 255*brightness);
    vertices[3].color = sf::Color(255*brightness, 255*brightness, 0);
    vertices[4].color = sf::Color(0, 255*brightness, 0);
    vertices[5].color = sf::Color(255*brightness, 255*brightness, 255*brightness);
    vertices[6].color = sf::Color(0, 255*brightness, 0);
    vertices[7].color = sf::Color(0, 255*brightness, 255*brightness);
    vertices[8].color = sf::Color(255*brightness, 255*brightness, 255*brightness);
    vertices[9].color = sf::Color(0, 255*brightness, 255*brightness);
    vertices[10].color = sf::Color(0, 0, 255*brightness);
    vertices[11].color = sf::Color(255*brightness, 255*brightness, 255*brightness);
    vertices[12].color = sf::Color(0, 0, 255*brightness);
    vertices[13].color = sf::Color(255*brightness, 0, 255*brightness);
    vertices[14].color = sf::Color(255*brightness, 255*brightness, 255*brightness);
    vertices[15].color = sf::Color(255*brightness, 0, 255*brightness);
    vertices[16].color = sf::Color(255*brightness, 0, 0);
    vertices[17].color = sf::Color(255*brightness, 255*brightness, 255*brightness);
    target.draw(vertices, states);
    Draw_Border(target, states, "RGB");
}
class hexagon_CMY : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

void hexagon_CMY::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::VertexArray vertices(sf::Triangles, 6 * 3);
    for (int i = 0; i < 6; i++)
    {
        vertices[3 * i].position = p[i];
        vertices[3 * i + 1].position = p[(i + 1) % 6];
        vertices[3 * i + 2].position = center;
    }
    sf::Text text;
    text.setFont(*font);
    text.setString("C");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(p[0].x - 30, p[0].y - 15);
    target.draw(text, states);
    text.setString("M");
    text.setPosition(p[2].x - 15, p[2].y - 10);
    target.draw(text, states);
    text.setString("Y");
    text.setPosition(p[4].x + 10, p[4].y - 10);
    target.draw(text, states);
    vertices[0].color = sf::Color(0,255,255,255*brightness);
    vertices[1].color = sf::Color(0,0,255,255*brightness);
    vertices[2].color = sf::Color(0,0,0,255*brightness);
    vertices[3].color = sf::Color(0,0,255,255*brightness);
    vertices[4].color = sf::Color(255,0,255,255*brightness);
    vertices[5].color = sf::Color(0,0,0,255*brightness);
    vertices[6].color = sf::Color(255,0,255,255*brightness);
    vertices[7].color = sf::Color(255,0,0,255*brightness);
    vertices[8].color = sf::Color(0,0,0,255*brightness);
    vertices[9].color = sf::Color(255,0,0,255*brightness);
    vertices[10].color = sf::Color(255,255,0,255*brightness);
    vertices[11].color = sf::Color(0,0,0,255*brightness);
    vertices[12].color = sf::Color(255,255,0,255*brightness);
    vertices[13].color = sf::Color(0,255,0,255*brightness);
    vertices[14].color = sf::Color(0,0,0,255*brightness);
    vertices[15].color = sf::Color(0,255,0,255*brightness);
    vertices[16].color = sf::Color(0,255,255,255*brightness);
    vertices[17].color = sf::Color(0,0,0,255*brightness);
    target.draw(vertices, states);
    Draw_Border(target, states, "CMY");
}

class hexagon_HSL : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
float Hue_2_RGB(float v1, float v2, float vH) {
    if (vH < 0) {
        vH += 1;
    }
    if (vH > 1) {
        vH -= 1;
    }
    if (6 * vH < 1) {
        return v1 + (v2 - v1) * 6 * vH;
    }
    if (2 * vH < 1) {
        return v2;
    }
    if (3 * vH < 2) {
        return v1 + (v2 - v1) * (2.0 / 3.0 - vH) * 6;
    }
    return v1;
}
sf::Color HSL_RGB(float h, float s, float l) {
    if (s == 0) {
        return sf::Color(l * 255, l * 255, l * 255);
    } 
    else {
        float var1,var2;
        if (l < 0.5) {
            var2 = l * (1 + s);
        }
        else {
            var2 = (l + s) - (s * l);
        }
        var1 = 2 * l - var2;
        return sf::Color(255 * Hue_2_RGB(var1, var2, h + (1.0 / 3.0)), 255 * Hue_2_RGB(var1, var2, h), 255 * Hue_2_RGB(var1, var2, h - (1.0 / 3.0)));
    }
}
sf::Color HSB_RGB(float h,float s,float v) {
    if (s == 0) {
        return sf::Color(v * 255, v * 255, v * 255);
    }
    else {
        float varh = h * 6;
        if (varh == 6) {
            varh = 0;
        }
        int var_i = static_cast<int>(varh);
        float var1 = v * (1 - s);
        float var2 = v * (1 - s * (varh - var_i));
        float var3 = v * (1 - s * (1 - (varh - var_i)));
        float var_r, var_g, var_b;
        if (var_i == 0) {
            var_r = v;
            var_g = var3;
            var_b = var1;
        }
        else if (var_i == 1) {
            var_r = var2;
            var_g = v;
            var_b = var1;
        }
        else if (var_i == 2) {
            var_r = var1;
            var_g = v;
            var_b = var3;
        }
        else if (var_i == 3) {
            var_r = var1;
            var_g = var2;
            var_b = v;
        }
        else if (var_i == 4) {
            var_r = var3;
            var_g = var1;
            var_b = v;
        }
        else {
            var_r = v;
            var_g = var1;
            var_b = var2;
        }
        return sf::Color(var_r * 255, var_g * 255, var_b * 255);
    }
}
void hexagon_HSL::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::VertexArray vertices(sf::Triangles, 6 * 3);
    for (int i = 0; i < 6; i++)
    {
        vertices[3 * i].position = p[i];
        vertices[3 * i + 1].position = p[(i + 1) % 6];
        vertices[3 * i + 2].position = center;
    }
    sf::Text text;
    text.setFont(*font);
    text.setString("H");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(p[0].x - 30, p[0].y - 15);
    target.draw(text, states);
    text.setString("S");
    text.setPosition(p[2].x - 15, p[2].y - 10);
    target.draw(text, states);
    text.setString("L");
    text.setPosition(p[4].x + 10, p[4].y - 10);
    target.draw(text, states);
    vertices[0].color = HSL_RGB(1.0, 0, 0 * brightness);
    vertices[1].color = HSL_RGB(1.0, 1, 0 * brightness);
    vertices[2].color = HSL_RGB(1.0, 1, brightness);
    vertices[3].color = HSL_RGB(1.0, 1, 0 * brightness);
    vertices[4].color = HSL_RGB(0.0, 1, 0 * brightness);
    vertices[5].color = HSL_RGB(1.0, 1, brightness);
    vertices[6].color = HSL_RGB(0.0, 1, 0 * brightness);
    vertices[7].color = HSL_RGB(0.0, 1, brightness);
    vertices[8].color = HSL_RGB(1.0, 1, brightness);
    vertices[9].color = HSL_RGB(0.0, 1, brightness);
    vertices[10].color = HSL_RGB(0.0, 0, brightness);
    vertices[11].color = HSL_RGB(1.0, 1, brightness);
    vertices[12].color = HSL_RGB(0, 0, brightness);
    vertices[13].color = HSL_RGB(1.0, 0, brightness);
    vertices[14].color = HSL_RGB(1.0, 1, brightness);
    vertices[15].color = HSL_RGB(1.0, 0, brightness);
    vertices[16].color = HSL_RGB(1.0, 0, 0 * brightness);
    vertices[17].color = HSL_RGB(1.0, 1, brightness);
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
    sf::VertexArray vertices(sf::Triangles, 6 * 3);
    for (int i = 0; i < 6; i++)
    {
        vertices[3 * i].position = p[i];
        vertices[3 * i + 1].position = p[(i + 1) % 6];
        vertices[3 * i + 2].position = center;
    }
    sf::Text text;
    text.setFont(*font);
    text.setString("H");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(p[0].x - 30, p[0].y - 15);
    target.draw(text, states);
    text.setString("S");
    text.setPosition(p[2].x - 15, p[2].y - 10);
    target.draw(text, states);
    text.setString("B");
    text.setPosition(p[4].x + 10, p[4].y - 10);
    target.draw(text, states);
    vertices[0].color = HSB_RGB(1, 0, 0 * brightness);
    vertices[1].color = HSB_RGB(1, 1, 0 * brightness);
    vertices[2].color = HSB_RGB(1, 1, brightness);
    vertices[3].color = HSB_RGB(1, 1, 0 * brightness);
    vertices[4].color = HSB_RGB(0, 1, 0 * brightness);
    vertices[5].color = HSB_RGB(1, 1, brightness);
    vertices[6].color = HSB_RGB(0, 1, 0 * brightness);
    vertices[7].color = HSB_RGB(0, 1, brightness);
    vertices[8].color = HSB_RGB(1, 1, brightness);
    vertices[9].color = HSB_RGB(0, 1, brightness);
    vertices[10].color = HSB_RGB(0, 0, brightness);
    vertices[11].color = HSB_RGB(1, 1, brightness);
    vertices[12].color = HSB_RGB(0, 0, brightness);
    vertices[13].color = HSB_RGB(1, 0, brightness);
    vertices[14].color = HSB_RGB(1, 1, brightness);
    vertices[15].color = HSB_RGB(1, 0, brightness);
    vertices[16].color = HSB_RGB(1, 0, 0 * brightness);
    vertices[17].color = HSB_RGB(1, 1, brightness);
    target.draw(vertices, states);
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
 sf::VertexArray slider(sf::Quads, 4);
 slider[0].position = sf::Vector2f(window.getSize().x-120, 70);
 slider[1].position = sf::Vector2f(window.getSize().x-70, 70);
 slider[2].position = sf::Vector2f(window.getSize().x-70, window.getSize().y-70);
 slider[3].position = sf::Vector2f(window.getSize().x-120, window.getSize().y-70);
 slider[0].color = sf::Color::Black;
 slider[1].color = sf::Color::Black;
 slider[2].color = sf::Color::White;
 slider[3].color = sf::Color::White;
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
 around_half_secound_clock.restart();

 while (window.isOpen())
 {
  sf::Event event;


  frame_clock.restart(); // Start pomiaru czasu.

  while (window.pollEvent(event))
  {
      if (event.type == sf::Event::Closed) window.close();
      else if (event.type == sf::Event::Resized)
      {
        window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        h_RGB.Set_Borders(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(event.size.width / 2 -100, event.size.height / 2));
        h_CMY.Set_Borders(sf::Vector2f(event.size.width / 2 -100, 0.0f), sf::Vector2f(event.size.width-200, event.size.height / 2));
        h_HSL.Set_Borders(sf::Vector2f(0.0f, event.size.height / 2), sf::Vector2f(event.size.width / 2 -100, event.size.height -10));
        h_HSB.Set_Borders(sf::Vector2f(event.size.width / 2 -100, event.size.height / 2), sf::Vector2f(event.size.width -200, event.size.height-10));
        text.setPosition(sf::Vector2f(event.size.width - 120, event.size.height - 50));
        slider[0].position = sf::Vector2f(event.size.width - 120, 70);
        slider[1].position = sf::Vector2f(event.size.width - 70, 70);
        slider[2].position = sf::Vector2f(event.size.width - 70, event.size.height - 50);
        slider[3].position = sf::Vector2f(event.size.width - 120, event.size.height - 50);
      }
      else if (event.type == sf::Event::MouseMoved)
      {
          if (event.mouseMove.x > slider[0].position.x && event.mouseMove.x < slider[1].position.x && event.mouseMove.y > slider[0].position.y && event.mouseMove.y < slider[2].position.y)
          {
                brightness = (event.mouseMove.y - slider[0].position.y) / (slider[2].position.y - slider[0].position.y);
                window.clear(sf::Color::White);
                window.draw(slider);
                window.draw(h_RGB);
                window.draw(h_CMY);
                window.draw(h_HSL);
                window.draw(h_HSB);  
                text.setString(std::to_string(mean_frames_time)+ "us");
                window.draw(text);
                window.display();
          }
      }
  }
  text.setString(std::to_string(mean_frames_time)+ "us");
  // Pomiar czasu uśrednimy w okresie około 1/2 sekundy.
  frame_times.push_back(frame_clock.getElapsedTime().asMicroseconds());
  if (around_half_secound_clock.getElapsedTime().asSeconds() >= 0.5f && frame_times.size() >=1)
  {
    mean_frames_time = (sf::Int64)((float)std::reduce(frame_times.begin(), frame_times.end()) / (float)frame_times.size());
    frame_times.clear();
    around_half_secound_clock.restart();
    window.clear(sf::Color::White);
    window.draw(slider);
    window.draw(h_RGB);
    window.draw(h_CMY);
    window.draw(h_HSL);
    window.draw(h_HSB);  
    window.draw(text);
    window.display();
  }

  frame_clock.restart(); // Stop pomiaru czasu.
 }
 //Hmmm ... :-/
 font.reset();
 
 return 0;
}