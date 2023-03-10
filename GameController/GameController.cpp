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
	AssetController::Instance().Initialize(100000000);
	Renderer* r = &Renderer::Instance();
	Timing* t = &Timing::Instance();
	r->Initialize();
	r->EnumerateDisplayModes();
	r->ChangeDisplayMode(&r->GetResolutions()[111]);

	TTFont* font = new TTFont();
	font->Initialize(20);

	
	SpriteSheet::Pool = new ObjectPool<SpriteSheet>();
	SpriteAnim::Pool = new ObjectPool<SpriteAnim>();
	SpriteSheet* sheet = SpriteSheet::Pool->GetResource();
	sheet->Load("Assets/Textures/Warrior.tga");
	sheet->SetSize(17, 6, 69, 44);
	sheet->AddAnimation(EN_AN_IDLE, 0, 6, 6.0f);
	sheet->AddAnimation(EN_AN_RUN, 6, 8, 6.0f);

	RenderTarget* rt = new RenderTarget();
	rt->Create(NATIVE_XRES, NATIVE_YRES);

	while (m_sdlEvent.type != SDL_QUIT)
	{
		t->Tick();
		rt->Start();
		r->SetDrawColor(Color(255, 255, 255, 255));
		r->ClearScreen();
		r->RenderTexture(sheet, sheet->Update(EN_AN_RUN, t->GetDeltaTime()), Rect(0, 150, 69 * 3, 150 + 44 * 3));

		std::string s = "Frame number: " + std::to_string(sheet->GetCurrentClip(EN_AN_RUN));
		font->Write(r->GetRenderer(), s.c_str(), SDL_Color{ 0, 255, 0 }, SDL_Point{ 250, 200 });

		std::string fps = "Frames Per Second: " + std::to_string(t->GetFPS());
		font->Write(r->GetRenderer(), fps.c_str(), SDL_Color{ 0, 0, 255 }, SDL_Point{ 0, 0 });

		rt->Stop();
		r->SetDrawColor(Color(0, 0, 0, 255));
		r->ClearScreen();
		rt->Render(t->GetDeltaTime());
		SDL_RenderPresent(r->GetRenderer());

		t->CapFPS();
	}

	delete rt;
	delete SpriteAnim::Pool;
	delete SpriteSheet::Pool;

	font->Shutdown();
	r->Shutdown();
}
