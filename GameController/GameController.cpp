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

	Texture::Pool = new ObjectPool<Texture>();
	Texture* texture = Texture::Pool->GetResource();
	texture->Load("Assets/Textures/Emoji.tga");
	while (m_sdlEvent.type != SDL_QUIT)
	{
		SDL_PollEvent(&m_sdlEvent);
		r->SetDrawColor(Color(255, 0, 0, 255));
		r->ClearScreen();
		r->RenderTexture(texture, Point(10, 10));
		SDL_RenderPresent(r->GetRenderer());
	}

	delete Texture::Pool;
	r->Shutdown();
}
