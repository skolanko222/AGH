//Uwaga! Co najmniej C++17!!!
//Project-> ... Properties->Configuration Properties->General->C++ Language Standard == ISO C++ 17 Standard (/std:c++17)

#include "SFML/Graphics.hpp"
#include "ShareTechMono-Regular.h"
#include <numeric>
#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>
#include <initializer_list>

//Tak – dobrze państwo widzą – TO jest zmienna globalna! Czytanie i przetwarzanie fontów w SFML jest bardzo kosztowne. Dlatego zrobimy to raz. 
//Co nie zmienia faktu, że można by to zrobić bez zmiennej globalnej i to całkiem ładnie. Jak? To już dla Państwa :-)
std::shared_ptr<sf::Font> font;
double slid_position=0.01;

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
    //hexagonals
    sf::VertexArray lines(sf::LinesStrip, 7);
	for(int i = 0; i < 7; i++) 
	{
		lines[i].color = sf::Color::Black;
	    lines[i].position = p[i%6];
    }
	target.draw(lines, states);

    //text
    sf::Text clr_text;
    clr_text.setFont(*font);
    clr_text.setCharacterSize(21);
    clr_text.setFillColor(sf::Color::Black);
    clr_text.setString(name);
    clr_text.setPosition(sf::Vector2f(left_top.x+20.0, left_top.y+15.0));
    target.draw(clr_text, states);
    
    //square
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(right_bottom.x - left_top.x - 10.0, right_bottom.y - left_top.y - 10.0));
    square.setFillColor(sf::Color::Transparent);
    square.setOutlineColor(sf::Color::Black);
    square.setOutlineThickness(1);
    square.setPosition(left_top.x +8 , left_top.y+8);
    target.draw(square, states);

    //letters
    sf::Text first_l;
    sf::Text second_l;
    sf::Text third_l;
    first_l.setFont(*font);
    second_l.setFont(*font);
    third_l.setFont(*font);
    first_l.setCharacterSize(21);
    second_l.setCharacterSize(21);
    third_l.setCharacterSize(21);
    first_l.setFillColor(sf::Color::Black);
    second_l.setFillColor(sf::Color::Black);
    third_l.setFillColor(sf::Color::Black);
    first_l.setString(name[0]);
    second_l.setString(name[1]);
    third_l.setString(name[2]);
    first_l.setPosition(sf::Vector2f(p[0].x-5.0, p[0].y-25.0));
    second_l.setPosition(sf::Vector2f(p[2].x-15.0, p[2].y-15.0));
    third_l.setPosition(sf::Vector2f(p[4].x+2, p[4].y-17.0));
    target.draw(first_l, states);
    target.draw(second_l, states);
    target.draw(third_l, states);
}

class hexagon_RGB : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

void hexagon_RGB::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //Tu trzeba narysować sześciokąt RGB.
    sf::VertexArray rhombus1(sf::Quads, 5);
    sf::VertexArray rhombus2(sf::Quads, 5);
    sf::VertexArray rhombus3(sf::Quads, 5);

    rhombus1[0].position=p[0];
    rhombus1[1].position=p[1];
    rhombus1[2].position=center;
    rhombus1[3].position=p[5];
    rhombus1[4].position=p[0];

    rhombus2[0].position=p[2];
    rhombus2[1].position=p[3];
    rhombus2[2].position=center;
    rhombus2[3].position=p[1];
    rhombus2[4].position=p[2];

    rhombus3[0].position=p[4];
    rhombus3[1].position=p[5];
    rhombus3[2].position=center;
    rhombus3[3].position=p[3];
    rhombus3[4].position=p[4];

    rhombus1[0].color=sf::Color(255-255*slid_position,0,0);
    rhombus1[1].color=sf::Color(255-255*slid_position,255-255*slid_position,0);
    rhombus1[2].color=sf::Color(255-255*slid_position,255-255*slid_position,255-255*slid_position);
    rhombus1[3].color=sf::Color(255-255*slid_position,0,255-255*slid_position);
    rhombus1[4].color=sf::Color(255-255*slid_position,0,0);
    
    rhombus2[0].color=sf::Color(0,255-255*slid_position,0);
    rhombus2[1].color=sf::Color(0,255-255*slid_position,255-255*slid_position);
    rhombus2[2].color=sf::Color(255-255*slid_position,255-255*slid_position,255-255*slid_position);
    rhombus2[3].color=sf::Color(255-255*slid_position,255-255*slid_position,0);
    rhombus2[4].color=sf::Color(0,255-255*slid_position,0);
    
    rhombus3[0].color=sf::Color(0,0,255-255*slid_position);
    rhombus3[1].color=sf::Color(255-255*slid_position,0,255-255*slid_position);
    rhombus3[2].color=sf::Color(255-255*slid_position,255-255*slid_position,255-255*slid_position);
    rhombus3[3].color=sf::Color(0,255-255*slid_position,255-255*slid_position);
    rhombus3[4].color=sf::Color(0,0,255-255*slid_position);


    target.draw(rhombus1, states);
    target.draw(rhombus2, states);
    target.draw(rhombus3, states);

    Draw_Border(target, states, "RGB");
}

class hexagon_CMY : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

void hexagon_CMY::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //Tu trzeba narysować sześciokąt CMY.
    sf::VertexArray rhombus1(sf::Quads, 5);
    sf::VertexArray rhombus2(sf::Quads, 5);
    sf::VertexArray rhombus3(sf::Quads, 5);

    rhombus1[0].position=p[0];
    rhombus1[1].position=p[1];
    rhombus1[2].position=center;
    rhombus1[3].position=p[5];
    rhombus1[4].position=p[0];

    rhombus2[0].position=p[2];
    rhombus2[1].position=p[3];
    rhombus2[2].position=center;
    rhombus2[3].position=p[1];
    rhombus2[4].position=p[2];

    rhombus3[0].position=p[4];
    rhombus3[1].position=p[5];
    rhombus3[2].position=center;
    rhombus3[3].position=p[3];
    rhombus3[4].position=p[4];

    rhombus1[0].color=sf::Color(0,255,255,255-255*slid_position);
    rhombus1[1].color=sf::Color(0,0,255,255-255*slid_position);
    rhombus1[2].color=sf::Color(0,0,0,255-255*slid_position);
    rhombus1[3].color=sf::Color(0,255,0,255-255*slid_position);
    rhombus1[4].color=sf::Color(0,255,255,255-255*slid_position);
    
    rhombus2[0].color=sf::Color(255,0,255,255-255*slid_position);
    rhombus2[1].color=sf::Color(255,0,0,255-255*slid_position);
    rhombus2[2].color=sf::Color(0,0,0,255-255*slid_position);
    rhombus2[3].color=sf::Color(0,0,255,255-255*slid_position);
    rhombus2[4].color=sf::Color(255,0,255,255-255*slid_position);
    
    rhombus3[0].color=sf::Color(255,255,0,255-255*slid_position);
    rhombus3[1].color=sf::Color(0,255,0,255-255*slid_position);
    rhombus3[2].color=sf::Color(0,0,0,255-255*slid_position);
    rhombus3[3].color=sf::Color(255,0,0,255-255*slid_position);
    rhombus3[4].color=sf::Color(255,255,0,255-255*slid_position);


    target.draw(rhombus1, states);
    target.draw(rhombus2, states);
    target.draw(rhombus3, states);

    Draw_Border(target, states, "CMY");
}

class hexagon_HSL : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

int RGB_hue(float r, float g, float b) 
{
    float R=r/255.0;
    float G=g/255.0;
    float B=b/255.0;
    float max = std::max({R,G,B});
    float min = std::min({R,G,B});
    int hue = 0;
    if(max==R)
    {
        hue = (G-B)/(max-min);
    }
    else if(max==G)
    {
        hue = 2.0 + (B-R)/(max-min);
    }
    else
    {
        hue = 4.0 + (R-G)/(max-min);
    }
    hue*=60;
    if(hue < 0)
        hue+=360;
    return hue;
}

sf::Color HSL_RGB(int h, float s, float l) 
{
    float chroma = (1 - fabs(2*l-1))*s;
    int h_prim = h/60;
    float x = chroma * (1 - fabs(h_prim % 2 -1));
    float r1, r2, r3;
    if(h_prim>=0 && h_prim <1)
    {
        r1=chroma;
        r2=x;
        r3=0;
    }
    else if(h_prim>=1 && h_prim <2)
    {
        r1=x;
        r2=chroma;
        r3=0;
    }
    else if(h_prim>=2 && h_prim <3)
    {
        r1=0;
        r2=chroma;
        r3=x;
    }
    else if(h_prim>=3 && h_prim <4)
    {
        r1=0;
        r2=x;
        r3=chroma;
    }
    else if(h_prim>=4 && h_prim <5)
    {
        r1=x;
        r2=0;
        r3=chroma;
    }
    else
    {
        r1=chroma;
        r2=0;
        r3=x;
    }
    float m = l- chroma/2;
    return(sf::Color((r1+m)*255, (r2+m)*255, (r3+m)*255));
}

sf::Color HSB_RGB(float h,float s,float v) 
{
   
}


void hexagon_HSL::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //Tu trzeba narysować sześciokąt HSL.
    sf::VertexArray rhombus1(sf::Quads, 5);

    sf::VertexArray sqr11(sf::Quads, 5);
    sqr11[0].position=sf::Vector2f(p[1].x,p[1].y);
    sqr11[0].color=sf::Color(HSL_RGB(RGB_hue(255,0,0),1,0));
    sqr11[1].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6);
    sqr11[1].color=sf::Color(HSL_RGB(RGB_hue(255,0,255),1,0));
    sqr11[2].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6);
    sqr11[2].color=sf::Color(HSL_RGB(RGB_hue(255,0,255),1,0.65-0.65*slid_position));
    sqr11[3].position=sf::Vector2f(center.x,center.y);
    sqr11[3].color=sf::Color(HSL_RGB(RGB_hue(255,0,0),1,0.65-0.65*slid_position));
    sqr11[4].position=sf::Vector2f(p[1].x,p[1].y);
    sqr11[4].color=sf::Color(HSL_RGB(RGB_hue(255,0,0),1,0));

    sf::VertexArray sqr12(sf::Quads, 5);
    sqr12[0].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6);
    sqr12[0].color=sf::Color(255,0,255);
    sqr12[1].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*2);
    sqr12[1].color=sf::Color(0,0,255);
    sqr12[2].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*2);
    sqr12[2].color=sf::Color(0,0,255);
    sqr12[3].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6);
    sqr12[3].color=sf::Color(255,0,255);
    sqr12[4].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6);
    sqr12[4].color=sf::Color(255,0,255);

    sf::VertexArray sqr13(sf::Quads, 5);
    sqr13[0].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*2);
    sqr13[0].color=sf::Color(0,0,255);
    sqr13[1].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*3);
    sqr13[1].color=sf::Color(0,255,255);
    sqr13[2].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*3);
    sqr13[2].color=sf::Color(0,255,255);
    sqr13[3].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*2);
    sqr13[3].color=sf::Color(0,0,255);
    sqr13[4].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*2);
    sqr13[4].color=sf::Color(0,0,255);

    sf::VertexArray sqr14(sf::Quads, 5);
    sqr14[0].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*3);
    sqr14[0].color=sf::Color(0,255,255);
    sqr14[1].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*4);
    sqr14[1].color=sf::Color(0,255,0);
    sqr14[2].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*4);
    sqr14[2].color=sf::Color(0,255,0);
    sqr14[3].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*3);
    sqr14[3].color=sf::Color(0,255,255);
    sqr14[4].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*3);
    sqr14[4].color=sf::Color(0,255,255);

    sf::VertexArray sqr15(sf::Quads, 5);
    sqr15[0].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*4);
    sqr15[0].color=sf::Color(0,255,0);
    sqr15[1].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*5);
    sqr15[1].color=sf::Color(255,255,0);
    sqr15[2].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*5);
    sqr15[2].color=sf::Color(255,255,0);
    sqr15[3].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*4);
    sqr15[3].color=sf::Color(0,255,0);
    sqr15[4].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*4);
    sqr15[4].color=sf::Color(0,255,0);

    sf::VertexArray sqr16(sf::Quads, 5);
    sqr16[0].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*5);
    sqr16[0].color=sf::Color(255,255,0);
    sqr16[1].position=sf::Vector2f(p[1].x,p[1].y+p[2].y-p[1].y);
    sqr16[1].color=sf::Color(255,0,0);
    sqr16[2].position=sf::Vector2f(center.x,center.y+p[2].y-p[1].y);
    sqr16[2].color=sf::Color(255,0,0);
    sqr16[3].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*5);
    sqr16[3].color=sf::Color(255,255,0);
    sqr16[4].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*5);
    sqr16[4].color=sf::Color(255,255,0);

    sf::VertexArray sqr21(sf::Quads, 5);
    sqr21[0].position=sf::Vector2f(p[5].x,p[5].y);
    sqr21[0].color=sf::Color(255,0,0);
    sqr21[1].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6);
    sqr21[1].color=sf::Color(255,0,255);
    sqr21[2].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6);
    sqr21[2].color=sf::Color(255,0,255);
    sqr21[3].position=sf::Vector2f(center.x,center.y);
    sqr21[3].color=sf::Color(255,0,0);
    sqr21[4].position=sf::Vector2f(p[5].x,p[5].y);
    sqr21[4].color=sf::Color(255,0,0);

    sf::VertexArray sqr22(sf::Quads, 5);
    sqr22[0].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6);
    sqr22[0].color=sf::Color(255,0,255);
    sqr22[1].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*2);
    sqr22[1].color=sf::Color(0,0,255);
    sqr22[2].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*2);
    sqr22[2].color=sf::Color(0,0,255);
    sqr22[3].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6);
    sqr22[3].color=sf::Color(255,0,255);
    sqr22[4].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6);
    sqr22[4].color=sf::Color(255,0,255);

    sf::VertexArray sqr23(sf::Quads, 5);
    sqr23[0].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*2);
    sqr23[0].color=sf::Color(0,0,255);
    sqr23[1].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*3);
    sqr23[1].color=sf::Color(0,255,255);
    sqr23[2].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*3);
    sqr23[2].color=sf::Color(0,255,255);
    sqr23[3].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*2);
    sqr23[3].color=sf::Color(0,0,255);
    sqr23[4].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*2);
    sqr23[4].color=sf::Color(0,0,255);

    sf::VertexArray sqr24(sf::Quads, 5);
    sqr24[0].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*3);
    sqr24[0].color=sf::Color(0,255,255);
    sqr24[1].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*4);
    sqr24[1].color=sf::Color(0,255,0);
    sqr24[2].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*4);
    sqr24[2].color=sf::Color(0,255,0);
    sqr24[3].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*3);
    sqr24[3].color=sf::Color(0,255,255);
    sqr24[4].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*3);
    sqr24[4].color=sf::Color(0,255,255);

    sf::VertexArray sqr25(sf::Quads, 5);
    sqr25[0].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*4);
    sqr25[0].color=sf::Color(0,255,0);
    sqr25[1].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*5);
    sqr25[1].color=sf::Color(255,255,0);
    sqr25[2].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*5);
    sqr25[2].color=sf::Color(255,255,0);
    sqr25[3].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*4);
    sqr25[3].color=sf::Color(0,255,0);
    sqr25[4].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*4);
    sqr25[4].color=sf::Color(0,255,0);

    sf::VertexArray sqr26(sf::Quads, 5);
    sqr26[0].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*5);
    sqr26[0].color=sf::Color(255,255,0);
    sqr26[1].position=sf::Vector2f(p[5].x,p[5].y+p[4].y-p[5].y);
    sqr26[1].color=sf::Color(255,0,0);
    sqr26[2].position=sf::Vector2f(center.x,center.y+p[4].y-p[5].y);
    sqr26[2].color=sf::Color(255,0,0);
    sqr26[3].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*5);
    sqr26[3].color=sf::Color(255,255,0);
    sqr26[4].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*5);
    sqr26[4].color=sf::Color(255,255,0);

    rhombus1[0].position=p[0];
    rhombus1[1].position=p[1];
    rhombus1[2].position=center;
    rhombus1[3].position=p[5];
    rhombus1[4].position=p[0];

    rhombus1[0].color=sf::Color(HSL_RGB(RGB_hue(255,0,0),1,0));
    rhombus1[1].color=sf::Color(HSL_RGB(RGB_hue(255,0,0),1,0));
    rhombus1[2].color=sf::Color(HSL_RGB(RGB_hue(255,0,0),1,0.65-0.65*slid_position));
    rhombus1[3].color=sf::Color(HSL_RGB(RGB_hue(255,0,0),1,0.65-0.65*slid_position));
    rhombus1[4].color=sf::Color(HSL_RGB(RGB_hue(255,0,0),1,0));

    target.draw(rhombus1, states);
    target.draw(sqr11, states);
    target.draw(sqr12, states);
    target.draw(sqr13, states);
    target.draw(sqr14, states);
    target.draw(sqr15, states);
    target.draw(sqr16, states);
    target.draw(sqr21, states);
    target.draw(sqr22, states);
    target.draw(sqr23, states);
    target.draw(sqr24, states);
    target.draw(sqr25, states);
    target.draw(sqr26, states);

    
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
    sf::VertexArray rhombus1(sf::Quads, 5);

    sf::VertexArray sqr11(sf::Quads, 5);
    sqr11[0].position=sf::Vector2f(p[1].x,p[1].y);
    sqr11[0].color=sf::Color(255,0,0);
    sqr11[1].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6);
    sqr11[1].color=sf::Color(255,0,255);
    sqr11[2].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6);
    sqr11[2].color=sf::Color(255,0,255);
    sqr11[3].position=sf::Vector2f(center.x,center.y);
    sqr11[3].color=sf::Color(255,0,0);
    sqr11[4].position=sf::Vector2f(p[1].x,p[1].y);
    sqr11[4].color=sf::Color(255,0,0);

    sf::VertexArray sqr12(sf::Quads, 5);
    sqr12[0].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6);
    sqr12[0].color=sf::Color(255,0,255);
    sqr12[1].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*2);
    sqr12[1].color=sf::Color(0,0,255);
    sqr12[2].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*2);
    sqr12[2].color=sf::Color(0,0,255);
    sqr12[3].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6);
    sqr12[3].color=sf::Color(255,0,255);
    sqr12[4].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6);
    sqr12[4].color=sf::Color(255,0,255);

    sf::VertexArray sqr13(sf::Quads, 5);
    sqr13[0].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*2);
    sqr13[0].color=sf::Color(0,0,255);
    sqr13[1].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*3);
    sqr13[1].color=sf::Color(0,255,255);
    sqr13[2].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*3);
    sqr13[2].color=sf::Color(0,255,255);
    sqr13[3].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*2);
    sqr13[3].color=sf::Color(0,0,255);
    sqr13[4].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*2);
    sqr13[4].color=sf::Color(0,0,255);

    sf::VertexArray sqr14(sf::Quads, 5);
    sqr14[0].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*3);
    sqr14[0].color=sf::Color(0,255,255);
    sqr14[1].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*4);
    sqr14[1].color=sf::Color(0,255,0);
    sqr14[2].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*4);
    sqr14[2].color=sf::Color(0,255,0);
    sqr14[3].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*3);
    sqr14[3].color=sf::Color(0,255,255);
    sqr14[4].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*3);
    sqr14[4].color=sf::Color(0,255,255);

    sf::VertexArray sqr15(sf::Quads, 5);
    sqr15[0].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*4);
    sqr15[0].color=sf::Color(0,255,0);
    sqr15[1].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*5);
    sqr15[1].color=sf::Color(255,255,0);
    sqr15[2].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*5);
    sqr15[2].color=sf::Color(255,255,0);
    sqr15[3].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*4);
    sqr15[3].color=sf::Color(0,255,0);
    sqr15[4].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*4);
    sqr15[4].color=sf::Color(0,255,0);

    sf::VertexArray sqr16(sf::Quads, 5);
    sqr16[0].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*5);
    sqr16[0].color=sf::Color(255,255,0);
    sqr16[1].position=sf::Vector2f(p[1].x,p[1].y+p[2].y-p[1].y);
    sqr16[1].color=sf::Color(255,0,0);
    sqr16[2].position=sf::Vector2f(center.x,center.y+p[2].y-p[1].y);
    sqr16[2].color=sf::Color(255,0,0);
    sqr16[3].position=sf::Vector2f(center.x,center.y+(p[2].y-p[1].y)/6*5);
    sqr16[3].color=sf::Color(255,255,0);
    sqr16[4].position=sf::Vector2f(p[1].x,p[1].y+(p[2].y-p[1].y)/6*5);
    sqr16[4].color=sf::Color(255,255,0);

    sf::VertexArray sqr21(sf::Quads, 5);
    sqr21[0].position=sf::Vector2f(p[5].x,p[5].y);
    sqr21[0].color=sf::Color(255,0,0);
    sqr21[1].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6);
    sqr21[1].color=sf::Color(255,0,255);
    sqr21[2].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6);
    sqr21[2].color=sf::Color(255,0,255);
    sqr21[3].position=sf::Vector2f(center.x,center.y);
    sqr21[3].color=sf::Color(255,0,0);
    sqr21[4].position=sf::Vector2f(p[5].x,p[5].y);
    sqr21[4].color=sf::Color(255,0,0);

    sf::VertexArray sqr22(sf::Quads, 5);
    sqr22[0].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6);
    sqr22[0].color=sf::Color(255,0,255);
    sqr22[1].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*2);
    sqr22[1].color=sf::Color(0,0,255);
    sqr22[2].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*2);
    sqr22[2].color=sf::Color(0,0,255);
    sqr22[3].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6);
    sqr22[3].color=sf::Color(255,0,255);
    sqr22[4].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6);
    sqr22[4].color=sf::Color(255,0,255);

    sf::VertexArray sqr23(sf::Quads, 5);
    sqr23[0].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*2);
    sqr23[0].color=sf::Color(0,0,255);
    sqr23[1].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*3);
    sqr23[1].color=sf::Color(0,255,255);
    sqr23[2].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*3);
    sqr23[2].color=sf::Color(0,255,255);
    sqr23[3].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*2);
    sqr23[3].color=sf::Color(0,0,255);
    sqr23[4].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*2);
    sqr23[4].color=sf::Color(0,0,255);

    sf::VertexArray sqr24(sf::Quads, 5);
    sqr24[0].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*3);
    sqr24[0].color=sf::Color(0,255,255);
    sqr24[1].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*4);
    sqr24[1].color=sf::Color(0,255,0);
    sqr24[2].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*4);
    sqr24[2].color=sf::Color(0,255,0);
    sqr24[3].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*3);
    sqr24[3].color=sf::Color(0,255,255);
    sqr24[4].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*3);
    sqr24[4].color=sf::Color(0,255,255);

    sf::VertexArray sqr25(sf::Quads, 5);
    sqr25[0].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*4);
    sqr25[0].color=sf::Color(0,255,0);
    sqr25[1].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*5);
    sqr25[1].color=sf::Color(255,255,0);
    sqr25[2].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*5);
    sqr25[2].color=sf::Color(255,255,0);
    sqr25[3].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*4);
    sqr25[3].color=sf::Color(0,255,0);
    sqr25[4].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*4);
    sqr25[4].color=sf::Color(0,255,0);

    sf::VertexArray sqr26(sf::Quads, 5);
    sqr26[0].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*5);
    sqr26[0].color=sf::Color(255,255,0);
    sqr26[1].position=sf::Vector2f(p[5].x,p[5].y+p[4].y-p[5].y);
    sqr26[1].color=sf::Color(255,0,0);
    sqr26[2].position=sf::Vector2f(center.x,center.y+p[4].y-p[5].y);
    sqr26[2].color=sf::Color(255,0,0);
    sqr26[3].position=sf::Vector2f(center.x,center.y+(p[4].y-p[5].y)/6*5);
    sqr26[3].color=sf::Color(255,255,0);
    sqr26[4].position=sf::Vector2f(p[5].x,p[5].y+(p[4].y-p[5].y)/6*5);
    sqr26[4].color=sf::Color(255,255,0);

    rhombus1[0].position=p[0];
    rhombus1[1].position=p[1];
    rhombus1[2].position=center;
    rhombus1[3].position=p[5];
    rhombus1[4].position=p[0];

    rhombus1[0].color=sf::Color(255,0,0);
    rhombus1[1].color=sf::Color(255,0,0);
    rhombus1[2].color=sf::Color(255,0,0);
    rhombus1[3].color=sf::Color(255,0,0);
    rhombus1[4].color=sf::Color(255,0,0);

    target.draw(rhombus1, states);
    target.draw(sqr11, states);
    target.draw(sqr12, states);
    target.draw(sqr13, states);
    target.draw(sqr14, states);
    target.draw(sqr15, states);
    target.draw(sqr16, states);
    target.draw(sqr21, states);
    target.draw(sqr22, states);
    target.draw(sqr23, states);
    target.draw(sqr24, states);
    target.draw(sqr25, states);
    target.draw(sqr26, states);

    

    Draw_Border(target, states, "HSB");
}

class slider : public sf::Drawable
{
    private:
        sf::Vector2f position_slider;
        double height=350.0;
        double width=50.0;

        sf::VertexArray *button;
        double button_position =0.01;

        sf::RectangleShape* border;
	    sf::Vertex* colour;

        void set_button()
        {
            (*button)[0].position=sf::Vector2f(position_slider.x, position_slider.y + height - button_position*height);
            (*button)[1].position=sf::Vector2f(position_slider.x + width, position_slider.y + height - button_position*height);
        }
    public:
        slider(double wwidth=350.0, double wheight=50.0)
        {
            button =  new sf::VertexArray(sf::LinesStrip, 2);
            (*button)[0].color = sf::Color::Black;
		    (*button)[1].color = sf::Color::Black;
            border = new sf::RectangleShape(sf::Vector2f(width, height));
            colour = new sf::Vertex[4]();
        }

        ~slider()
        {
            delete button;
            delete border;
            delete [] colour;
        }

        void set_slider(double wwidth, double wheight)
        {
            position_slider.x=wwidth-wwidth/7;
            position_slider.y=wheight/5;
            width=wwidth/20;
            height=wheight/2;
            colour[0] = sf::Vertex(sf::Vector2f(position_slider.x, position_slider.y), sf::Color::Black);
		    colour[1] = sf::Vertex(sf::Vector2f(position_slider.x + width, position_slider.y), sf::Color::Black);
		    colour[2] = sf::Vertex(sf::Vector2f(position_slider.x + width, position_slider.y + height), sf::Color::White);
		    colour[3] = sf::Vertex(sf::Vector2f(position_slider.x, position_slider.y + height), sf::Color::White);

		    border->setPosition(sf::Vector2f(position_slider.x, position_slider.y));
            border->setSize(sf::Vector2f(width, height));
		    border->setFillColor(sf::Color::Transparent);
		    border->setOutlineColor(sf::Color::Black);
		    border->setOutlineThickness(1);
		    
            set_button();
        }

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(colour, 4, sf::Quads);
		    target.draw(*border);
		    target.draw(*button);
        }

        double clicked(sf::Vector2i mouse_position)
        {
            if (mouse_position.x <= position_slider.x || mouse_position.x >= position_slider.x + width) 
			    return button_position;
		    if (mouse_position.y <= position_slider.y || mouse_position.y >= position_slider.y + height) 
			    return button_position;
		    button_position = 1- ((mouse_position.y - position_slider.y) / height);
            set_button();
            return button_position;
        }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

    slider slid;
 
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
    text.setPosition(window.getSize().x-70, window.getSize().y-30);
    h_RGB.Set_Borders(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(300.0f,294.0f));
    h_CMY.Set_Borders(sf::Vector2f(300.0f, 0.0f), sf::Vector2f(600.0f, 294.0f));
    h_HSL.Set_Borders(sf::Vector2f(0.0f, 294.0f), sf::Vector2f(300.0f, 588.0f));
    h_HSB.Set_Borders(sf::Vector2f(300.0f, 294.0f), sf::Vector2f(600.0f, 588.0f));
    slid.set_slider(window.getSize().x, window.getSize().y);

    around_half_secound_clock.restart();

    while (window.isOpen())
    {
        

        
        text.setString(std::to_string(mean_frames_time)+ "us");
        sf::Event event;

        frame_clock.restart(); // Start pomiaru czasu.

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::Resized)
            {
                float width = static_cast<float>(event.size.width);
                float height = static_cast<float>(event.size.height);
                window.setView(sf::View(sf::FloatRect(0, 0, width, height)));
        
                h_RGB.Set_Borders(sf::Vector2f(0.0f,                       0.0f),                           sf::Vector2f(std::min(width ,height)/2., std::min(width ,height)/2.));
                h_CMY.Set_Borders(sf::Vector2f(std::min(width ,height)/2., 0.0f),                           sf::Vector2f(std::min(width ,height),    std::min(width ,height)/2.));
                h_HSL.Set_Borders(sf::Vector2f(0.0f,                       std::min(width ,height)/2.),     sf::Vector2f(std::min(width ,height)/2., std::min(width ,height)));
                h_HSB.Set_Borders(sf::Vector2f(std::min(width ,height)/2., std::min(width ,height)/2.),     sf::Vector2f(std::min(width ,height),    std::min(width ,height)));
                slid.set_slider(window.getSize().x, window.getSize().y);
                text.setPosition(window.getSize().x-70, window.getSize().y-30);

                window.clear(sf::Color::White);
                window.draw(h_RGB);
                window.draw(h_CMY);
                window.draw(h_HSL);
                window.draw(h_HSB);
                window.draw(text);
                window.draw(slid);
                window.display();
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
                slid_position=slid.clicked(sf::Mouse::getPosition(window));
                //std::cout<<slid_position<<std::endl;
                                
                window.clear(sf::Color::White);
                window.draw(h_RGB);
                window.draw(h_CMY);
                window.draw(h_HSL);
                window.draw(h_HSB);
                window.draw(text);
                window.draw(slid);
                window.display();
            }
            // Tu trzeba obsłużyć zdarzenia: zmianę rozmiaru okna oraz klikanie w „suwaczek”. 
        }

        // Pomiar czasu uśrednimy w okresie około 1/2 sekundy.
        frame_times.push_back(frame_clock.getElapsedTime().asMicroseconds());
        if (around_half_secound_clock.getElapsedTime().asSeconds() >= 0.5f && frame_times.size() >=1)
        {
            mean_frames_time = (sf::Int64)((float)std::reduce(frame_times.begin(), frame_times.end()) / (float)frame_times.size());
            frame_times.clear();
            
            around_half_secound_clock.restart();
            window.clear(sf::Color::White);
            window.draw(h_RGB);
            window.draw(h_CMY);
            window.draw(h_HSL);
            window.draw(h_HSB);
            // Pewnie tu gdzieś wypadało by dorysować jeszcze suwaczek... 
            window.draw(text);
            window.draw(slid);
            window.display();
         }

    frame_clock.restart(); // Stop pomiaru czasu.
    }

    //Hmmm ... :-/
    font.reset();
 
    return 0;
}