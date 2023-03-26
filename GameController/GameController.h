#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"
#include "core/Sound/AudioController/AudioController.h"

class Renderer;
class TTFont;
class InputController;
class AudioController;
class SoundEffect;
class Song;
class WavDraw;

class GameController :public Singleton<GameController>
{
public:

	// Cons/Des
	GameController();
	virtual ~GameController();

	void RunGame();
	void Initialize();
	void HandleInput(SDL_Event _event);
	void ShutDown();

private:
	SDL_Event m_sdlEvent;
	Renderer* m_renderer;
	TTFont* m_fArial20;
	bool m_quit;
	InputController* m_input;
	AudioController* m_audio;
	WavDraw* m_wavDraw;
	SoundEffect* m_effects[MaxEffectChannels];
	float m_zoomY;
};

#endif // !GAME_CONTROLLER_H

