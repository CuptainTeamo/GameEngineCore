#include "GameController.h"
#include "core/Renderer/Renderer.h"

GameController::GameController()
{
	m_sdlEvent = {};
}

GameController::~GameController()
{
}

void GameController::RunGame()
{
	AssetController::Instance().Initialize(100000000);
	Renderer* r = &Renderer::Instance();
	r->Initialize(800, 600);
	Point ws = r->GetWindowSize();

	Texture::Pool = new ObjectPool<Texture>();
	Texture* texture = Texture::Pool->GetResource();
	texture->Load("Assets/Textures/Warrior.tga");

	while (m_sdlEvent.type != SDL_QUIT)
	{
		SDL_PollEvent(&m_sdlEvent);
		r->SetDrawColor(Color(255, 255, 255, 255));
		r->ClearScreen();
		for (unsigned int count = 0; count < 6; count++)
		{
			unsigned int xPos = count * 69;
			r->RenderTexture(texture, Rect(xPos, 0, xPos + 69, 44), Rect(xPos, 100, xPos + 69 * 2, 100 + 44 * 2));
		}
		SDL_RenderPresent(r->GetRenderer());
	}

	delete Texture::Pool;
	r->Shutdown();
}
