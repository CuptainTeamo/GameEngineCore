#ifndef HEROINE_H
#define HEROINE_H

#include "HeroineState/HeroineState.h"
#include "core/Physics/RigidBody/RigidBody.h"

class SpriteSheet;

class Heroine
{
public:
	// Constructor / Destructors
	Heroine();
	virtual ~Heroine();

	// Accessors
	HeroineState* GetStatate() { return m_state; }
	void SetState(HeroineState* _state) { m_state = _state; }
	SpriteSheet* GetAnimations() { return m_animations; }
	Rect* GetSrcRect() { return &m_srcRect; }
	RigidBody* GetRigidBody() { return m_rigidBody; }

	// Methods
	virtual void HandleInput(SDL_Event _event, float _deltaTime);
	virtual void Update(float _deltaTime);
	virtual void Render(Renderer* _renderer);

private:
	HeroineState* m_state;
	RigidBody* m_rigidBody;
	SpriteSheet* m_animations;
	Rect m_srcRect;
};

#endif // !HEROINE_H

