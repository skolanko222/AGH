#include "SFML/Graphics.hpp"
#include <numeric>
#include <iostream>
#include <memory>
#include <cmath>

#define max(X,Y) ((X)>(Y)? (X):(Y))
#define min(X,Y) ((X)<(Y)? (X):(Y))

class hexagon : public sf::Drawable
{
protected:
    sf::Vector2f left_top, right_bottom, center;
    sf::Vector2f p[6]; // Kolejność punktów opisana w pliku PDF do laboratorium.
public:
    void Set_Borders(sf::Vector2f _left_top, sf::Vector2f _right_bottom); // oblicza pozycję sześciokątów
    void Draw_Border(sf::RenderTarget& target, sf::RenderStates states, sf::String name) const;
    bool rhombus(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p, float& alpha, float& beta) const;
    double sliderParam;
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

    p[0] = center - sf::Vector2f(0.0f, a);
    p[1] = center - sf::Vector2f(0.5f * sqrt(3.0f) * a, 0.5f * a);
    p[2] = center - sf::Vector2f(0.5f * sqrt(3.0f) * a, -0.5f * a);
    p[3] = center + sf::Vector2f(0.0f, a);
    p[4] = center + sf::Vector2f(0.5f * sqrt(3.0f) * a, 0.5f * a);
    p[5] = center + sf::Vector2f(0.5f * sqrt(3.0f) * a, -0.5f * a);
}

void hexagon::Draw_Border(sf::RenderTarget& target, sf::RenderStates states, sf::String name) const
{
    //Rysowanie obramowania sześciokąta.
    sf::Text text;
    text.setFont(*font);
	sf::VertexArray lines(sf::LinesStrip, 7);
	for(int i = 0; i < 7; i++) 
	{
		lines[i].color = sf::Color::Black;
		lines[i].position = p[i % 6];
	}
	target.draw(lines, states);
    text.setString(name[0]);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(p[0].x - 5 , p[0].y - 25);
    target.draw(text, states);
    text.setString(name[1]);
    text.setPosition(p[2].x - 15, p[2].y - 10);
    target.draw(text, states);
    text.setString(name[2]);
    text.setPosition(p[4].x + 5, p[4].y - 10);
    target.draw(text, states);
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
    vertices[0].color = sf::Color(255*sliderParam, 0, 0);
    vertices[1].color = sf::Color(255*sliderParam, 255*sliderParam, 0);
    vertices[2].color = sf::Color(255*sliderParam, 255*sliderParam, 255*sliderParam);
    vertices[3].color = sf::Color(255*sliderParam, 255*sliderParam, 0);
    vertices[4].color = sf::Color(0, 255*sliderParam, 0);
    vertices[5].color = sf::Color(255*sliderParam, 255*sliderParam, 255*sliderParam);
    vertices[6].color = sf::Color(0, 255*sliderParam, 0);
    vertices[7].color = sf::Color(0, 255*sliderParam, 255*sliderParam);
    vertices[8].color = sf::Color(255*sliderParam, 255*sliderParam, 255*sliderParam);
    vertices[9].color = sf::Color(0, 255*sliderParam, 255*sliderParam);
    vertices[10].color = sf::Color(0, 0, 255*sliderParam);
    vertices[11].color = sf::Color(255*sliderParam, 255*sliderParam, 255*sliderParam);
    vertices[12].color = sf::Color(0, 0, 255*sliderParam);
    vertices[13].color = sf::Color(255*sliderParam, 0, 255*sliderParam);
    vertices[14].color = sf::Color(255*sliderParam, 255*sliderParam, 255*sliderParam);
    vertices[15].color = sf::Color(255*sliderParam, 0, 255*sliderParam);
    vertices[16].color = sf::Color(255*sliderParam, 0, 0);
    vertices[17].color = sf::Color(255*sliderParam, 255*sliderParam, 255*sliderParam);
    target.draw(vertices, states);
    Draw_Border(target, states, "RGB");
}

class hexagon_CMY : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    static sf::Color HSB_RGB(float h,float s,float v);
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
    vertices[0].color = sf::Color(0,255,255,255*sliderParam);
    vertices[1].color = sf::Color(0,0,255,255*sliderParam);
    vertices[2].color = sf::Color(0,0,0,255*sliderParam);
    vertices[3].color = sf::Color(0,0,255,255*sliderParam);
    vertices[4].color = sf::Color(255,0,255,255*sliderParam);
    vertices[5].color = sf::Color(0,0,0,255*sliderParam);
    vertices[6].color = sf::Color(255,0,255,255*sliderParam);
    vertices[7].color = sf::Color(255,0,0,255*sliderParam);
    vertices[8].color = sf::Color(0,0,0,255*sliderParam);
    vertices[9].color = sf::Color(255,0,0,255*sliderParam);
    vertices[10].color = sf::Color(255,255,0,255*sliderParam);
    vertices[11].color = sf::Color(0,0,0,255*sliderParam);
    vertices[12].color = sf::Color(255,255,0,255*sliderParam);
    vertices[13].color = sf::Color(0,255,0,255*sliderParam);
    vertices[14].color = sf::Color(0,0,0,255*sliderParam);
    vertices[15].color = sf::Color(0,255,0,255*sliderParam);
    vertices[16].color = sf::Color(0,255,255,255*sliderParam);
    vertices[17].color = sf::Color(0,0,0,255*sliderParam);
    target.draw(vertices, states);
    Draw_Border(target, states, "CMY");
}
class hexagon_HSL : public hexagon
{
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    static float Hue_2_RGB(float v1, float v2, float vH) {
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
    static sf::Color HSL_RGB(float h, float s, float l) {
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
};
void hexagon_HSL::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    float dif = (p[2].y - p[1].y)/6.;
    //std::cout << dif << std::endl;
    sf::VertexArray top(sf::Quads, 4);
    top[0].position = p[0];
    top[1].position = p[1];
    top[2].position = center;
    top[3].position = p[5];
    std::vector<sf::VertexArray> vertices;
    std::vector<sf::VertexArray> vertices2;
    for (int i = 0; i < 6; i++)
    {
        sf::VertexArray temp(sf::Quads, 4);
        temp[0].position = sf::Vector2f(p[1].x,p[1].y + dif*i);
        temp[1].position = sf::Vector2f(center.x,center.y + dif*i);
        temp[2].position = sf::Vector2f(center.x,center.y + dif*(i+1));
        temp[3].position = sf::Vector2f(p[1].x,p[1].y + dif*(i+1));

        vertices.push_back(temp);
    }
    vertices[0][0].color = sf::Color(255,0,0,255*sliderParam);
    vertices[0][1].color = sf::Color(255,0,0,255*sliderParam);
    vertices[0][2].color = sf::Color(255,0,255,255*sliderParam);
    vertices[0][3].color = sf::Color(255,0,255,255*sliderParam);
    vertices[1][0].color = sf::Color(255,0,255,255*sliderParam);
    vertices[1][1].color = sf::Color(255,0,255,255*sliderParam);
    vertices[1][2].color = sf::Color(0,0,255,255*sliderParam);
    vertices[1][3].color = sf::Color(0,0,255,255*sliderParam);
    vertices[2][0].color = sf::Color(0,0,255,255*sliderParam);
    vertices[2][1].color = sf::Color(0,0,255,255*sliderParam);
    vertices[2][2].color = sf::Color(0,255,255,255*sliderParam);
    vertices[2][3].color = sf::Color(0,255,255,255*sliderParam);
    vertices[3][0].color = sf::Color(0,255,255,255*sliderParam);
    vertices[3][1].color = sf::Color(0,255,255,255*sliderParam);
    vertices[3][2].color = sf::Color(0,255,0,255*sliderParam);
    vertices[3][3].color = sf::Color(0,255,0,255*sliderParam);
    vertices[4][0].color = sf::Color(0,255,0,255*sliderParam);
    vertices[4][1].color = sf::Color(0,255,0,255*sliderParam);
    vertices[4][2].color = sf::Color(255,255,0,255*sliderParam);
    vertices[4][3].color = sf::Color(255,255,0,255*sliderParam);
    vertices[5][0].color = sf::Color(255,255,0,255*sliderParam);
    vertices[5][1].color = sf::Color(255,255,0,255*sliderParam);
    vertices[5][2].color = sf::Color(255,0,0,255*sliderParam);
    vertices[5][3].color = sf::Color(255,0,0,255*sliderParam);
    
    for(auto a : vertices)
        target.draw(a, states);
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
sf::Color hexagon_CMY::HSB_RGB(float h,float s,float v) {
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



