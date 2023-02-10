#ifndef RENDERER_H
#define RENDERER_H

#include "StandardIncludes.h"

struct Color
{
	Color(byte _r, byte _g, byte _b, byte _a)
	{
		R = _r;
		G = _g;
		B = _b;
		A = _a;
	}

	byte R;
	byte G;
	byte B;
	byte A;
};

struct Point
{
	Point(unsigned int _x, unsigned int _y)
	{
		X = _x;
		Y = _y;
	}

	unsigned int X;
	unsigned int Y;
};

struct Rect
{
	Rect(unsigned int _x1, unsigned int _y1, unsigned int _x2, unsigned int _y2)
	{
		X1 = _x1;
		Y1 = _y1;
		X2 = _x2;
		Y2 = _y2;
	}

	unsigned int X1;
	unsigned int Y1;
	unsigned int X2;
	unsigned int Y2;
};

class Renderer :public Singleton<Renderer>
{
public:
	Renderer();
	virtual ~Renderer();

	// accessors
	SDL_Window* GetWindow() { return m_window; }
	SDL_Renderer* GetRenderer() { return m_renderer; }

	// methods
	void Initialize(int _xResolution, int _yResolution);
	void SetDrawColor(Color _color);
	void ClearScreen();
	void Shutdown();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Rect* m_destRect;
};
#endif // !RENDERER_H

