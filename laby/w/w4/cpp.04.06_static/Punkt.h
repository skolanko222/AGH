#ifndef _PUNKT_H_
#define _PUNKT_H_

class Punkt
{
public:
	Punkt();
	Punkt(float x, float y);
	~Punkt();

	void SetX(float x);
	void SetY(float y);
	float GetX() const;
	float GetY() const;
	static int GetN()
	{	 return n;	}

	static void SetN(int value)
	{
		// _x = value; //B£¥D
		n = value;
	}
private:
	float _x;
	float _y;
	static int n; //tylko deklaracja, nie definicja

};
/////////////////////////////////////////////////////////////////////////
inline void Punkt::SetX(float x)
{
	_x = x;
	//n = x; //ALE TO NIE JEST BLAD
}
/////////////////////////////////////////////////////////////////////////
inline void Punkt::SetY(float y)
{
	_y = y;
}
#endif //_PUNKT_H_