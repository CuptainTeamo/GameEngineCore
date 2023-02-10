#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"

class GameController :public Singleton<GameController>
{
public:

	// Cons/Des
	GameController();
	virtual ~GameController();

	void RunGame();

private:
	SDL_Event m_sdlEvent;
};

#endif // !GAME_CONTROLLER_H

