#include "GameController.h"
#include "core/Renderer/Renderer.h"
#include "../Game/SpriteSheet/SpriteSheet.h"
#include "core/Graphics/Fonts/TTFont.h"
#include "core/Timing/Timing.h"
#include "core/Renderer/RenderTarget.h"
#include <sstream>

GameController::GameController()
{
	m_sdlEvent = {};
}

GameController::~GameController()
{
}

void GameController::RunGame()
{
	// AssetController::Instance().Initialize(100000000);
	Renderer* r = &Renderer::Instance();
	Timing* t = &Timing::Instance();
	r->Initialize();
	r->EnumerateDisplayModes();

	TTFont* font = new TTFont();
	font->Initialize(20);

	/*
	SpriteSheet::Pool = new ObjectPool<SpriteSheet>();
	SpriteAnim::Pool = new ObjectPool<SpriteAnim>();
	SpriteSheet* sheet = SpriteSheet::Pool->GetResource();
	sheet->Load("Assets/Textures/Warrior.tga");
	sheet->SetSize(17, 6, 69, 44);
	sheet->AddAnimation(EN_AN_IDLE, 0, 6, 6.0f);
	sheet->AddAnimation(EN_AN_RUN, 6, 8, 6.0f);

	sheet->SetBlendMode(SDL_BLENDMODE_BLEND);
	sheet->SetBlendAlpha(128);

	Point ws = r->GetWindowSize();
	RenderTarget* rt = new RenderTarget();
	rt->Create(ws.X, ws.Y);
	*/

	while (m_sdlEvent.type != SDL_QUIT)
	{
		t->Tick();
		// rt->Start();

		// SDL_PollEvent(&m_sdlEvent);
		r->SetDrawColor(Color(255, 255, 255, 255));
		r->ClearScreen();
		//r->RenderTexture(sheet, sheet->Update(EN_AN_IDLE, t->GetDeltaTime()), Rect(0, 0, 69 * 3, 44 * 3));
		//r->RenderTexture(sheet, sheet->Update(EN_AN_RUN, t->GetDeltaTime()), Rect(0, 150, 69 * 3, 150 + 44 * 3));

		//std::string s = "Frame number: " + std::to_string(sheet->GetCurrentClip(EN_AN_IDLE));
		//font->Write(r->GetRenderer(), s.c_str(), SDL_Color{0, 255, 0}, SDL_Point{250, 50});

		//s = "Frame number: " + std::to_string(sheet->GetCurrentClip(EN_AN_RUN));
		//font->Write(r->GetRenderer(), s.c_str(), SDL_Color{ 0, 255, 0 }, SDL_Point{ 250, 200 });

		std::string fps = "Frames Per Second: " + std::to_string(t->GetFPS());
		font->Write(r->GetRenderer(), fps.c_str(), SDL_Color{ 0, 0, 255 }, SDL_Point{ 0, 0 });

		//std::string deltaTime = "DeltaTime: " + std::to_string(t->GetDeltaTime());
		//font->Write(r->GetRenderer(), deltaTime.c_str(), SDL_Color{ 0, 0, 255 }, SDL_Point{ 250, 0 });

		//rt->Stop();
		//r->SetDrawColor(Color(0, 0, 0, 255));
		//r->ClearScreen();
		//rt->Render(t->GetDeltaTime());

		vector<SDL_DisplayMode> modes = r->GetResolutions();
		for (int count = 0; count < modes.size(); count++)
		{
			stringstream s;
			s << modes[count].w << "x" << modes[count].h << " " << modes[count].refresh_rate << "hz";
			font->Write(r->GetRenderer(), s.str().c_str(), SDL_Color{ 255, 128, 0 }, SDL_Point{ 0, 20 + count * 20 });
		}
		SDL_RenderPresent(r->GetRenderer());

		t->CapFPS();
	}

	// delete rt;
	//delete SpriteAnim::Pool;
	//delete SpriteSheet::Pool;

	font->Shutdown();
	r->Shutdown();
}
