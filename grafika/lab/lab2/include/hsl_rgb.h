#include "SFML/Graphics.hpp"
class RGB
{
public:
	unsigned R;
	unsigned G;
	unsigned B;
	sf::Color color;

	RGB(unsigned r, unsigned g, unsigned b) : R(r), G(g), B(b), color(r, g, b) {}
	bool Equals(RGB rgb)
	{
		return (R == rgb.R) && (G == rgb.G) && (B == rgb.B);
	}
};

class HSL
{
public:
	int H;
	float S;
	float L;

	HSL(int h, float s, float l) : H(h), S(s), L(l) {}
	bool Equals(HSL hsl)
	{
		return (H == hsl.H) && (S == hsl.S) && (L == hsl.L);
	}
};

static float HueToRGB(float v1, float v2, float vH) {
	if (vH < 0)
		vH += 1;

	if (vH > 1)
		vH -= 1;

	if ((6 * vH) < 1)
		return (v1 + (v2 - v1) * 6 * vH);

	if ((2 * vH) < 1)
		return v2;

	if ((3 * vH) < 2)
		return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);

	return v1;
}

static RGB HSLToRGB(HSL hsl) {
	unsigned r = 0;
	unsigned g = 0;
	unsigned b = 0;

	if (hsl.S == 0)
	{
		r = g = b = (unsigned)(hsl.L * 255);
	}
	else
	{
		float v1, v2;
		float hue = (float)hsl.H / 360;

		v2 = (hsl.L < 0.5) ? (hsl.L * (1 + hsl.S)) : ((hsl.L + hsl.S) - (hsl.L * hsl.S));
		v1 = 2 * hsl.L - v2;

		r = (unsigned char)(255 * HueToRGB(v1, v2, hue + (1.0f / 3)));
		g = (unsigned char)(255 * HueToRGB(v1, v2, hue));
		b = (unsigned char)(255 * HueToRGB(v1, v2, hue - (1.0f / 3)));
	}

	return RGB(r, g, b);
}