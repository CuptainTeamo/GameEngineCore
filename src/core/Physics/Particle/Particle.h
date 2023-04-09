#ifndef PARTICLE_H
#define PARTICLE_H

#include "../RigidBody/RigidBody.h"
#include "core/ObjectPool/ObjectPool.h"

class Particle :public RigidBody
{
public:
	// Constructors / Destructors
	Particle();
	virtual ~Particle();

	// Accessors
	float GetLifeTime() { return m_lifeTime; }
	void SetLifeTime(float _lifeTIme) { m_lifeTime = _lifeTIme; }
	float GetStartSize() { return m_startSize; }
	void SetStartSize(float _startSize) { m_startSize = _startSize; }
	float GetEndSize() { return m_endSize; }
	void SetEndSize(float _endSize) { m_endSize = _endSize; }
	float GetCurrentSize() { return m_currentSize; }
	void SetCurrentSize(float _currentSize) { m_currentSize = _currentSize; }

	// Methods
	void Update(float _deltaTime, glm::vec2 _force) override;
	void Reset() override;

	// Members
	static ObjectPool<Particle>* Pool;

private:
	// Members
	float m_currentTime;
	float m_lifeTime;
	float m_startSize;
	float m_endSize;
	float m_currentSize;
};

#endif // !PARTICLE_H

