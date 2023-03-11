#ifndef RENDERER_H
#define RENDERER_H

#include "StandardIncludes.h"
#include "../Game/Texture/Texture.h"

class Asset;

class Renderer :public Singleton<Renderer>
{
public:
	Renderer();
	virtual ~Renderer();

	// Accessors
	SDL_Window* GetWindow() { return m_window; }
	SDL_Renderer* GetRenderer() { return m_renderer; }
	SDL_Texture* GetSDLTexture(Texture* _texture);
	vector<SDL_DisplayMode>& GetResolutions() { return m_resolutions; }

	// methods
	void Initialize();
	void ChangeDisplayMode(SDL_DisplayMode* _mode);
	void EnumerateDisplayModes();
	Point GetWindowSize();
	void SetDrawColor(Color _color);
	void ClearScreen();
	void SetViewport(Rect _viewport);
	void RenderPoint(Point _postion);
	void RenderLine(Rect _points);
	void RenderRectangle(Rect _rect);
	void RenderFillRectangle(Rect _rect);
	void RenderTexture(Texture* _texture, Point _point);
	void RenderTexture(Texture* _texture, Rect _rect);
	void RenderTexture(Texture* _texture, Rect _srcRect, Rect _destRect);
	void RenderTexture(SDL_Texture* _texture, Rect _srcRect, Rect _destRect, double _angle);
	void Shutdown();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Rect m_srcRect;
	SDL_Rect m_destRect;
	SDL_Surface* m_surface;
	SDL_Rect m_viewPort;
	map<string, SDL_Texture*> m_textures;
	vector<SDL_DisplayMode> m_resolutions;
};
#endif // !RENDERER_H

