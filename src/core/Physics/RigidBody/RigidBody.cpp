#include "RigidBody.h"

ObjectPool<RigidBody>* RigidBody::Pool;

RigidBody::RigidBody()
{
	Reset();
}

void RigidBody::Update(float _deltaTime, glm::vec2 _force)
{
	// Apply forces
	_force += m_wind + m_buoyancy;
	_force.y *= -1;
	if (m_mass < 1) m_acceleration = _force * m_mass;
	else m_acceleration = _force / m_mass;
	m_velocity += m_acceleration * _deltaTime;
	m_position += m_velocity * _deltaTime;

	// Calculating decays
	m_buoyancy -= m_buoyancyDecay * -_deltaTime;
	m_buoyancy.x = std::fmax(m_buoyancy.x, m_buoyancyMin.x);
	m_buoyancy.y = std::fmax(m_buoyancy.y, m_buoyancyMin.y);
}

void RigidBody::Reset()
{
	m_position = {};
	m_velocity = {};
	m_acceleration = {};
	m_buoyancy = {};
	m_buoyancyDecay = {};
	m_buoyancyMin = { 0, 0 };
	m_randomForce = { 0, 0 };
	m_wind = {};
	m_mass = 0;
	m_dead = false;
}
