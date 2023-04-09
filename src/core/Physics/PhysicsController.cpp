#include "PhysicsController.h"
#include "core/Renderer/Renderer.h"

PhysicsController::PhysicsController()
{
	m_gravity = -9.81f;
	m_force = glm::vec2{ 0, 0 };
	Particle::Pool = new ObjectPool<Particle>();
}

PhysicsController::~PhysicsController()
{
	delete Particle::Pool;
}

void PhysicsController::Update(float _deltaTIme)
{
	for (int count = 0; count < m_particles.size(); count++)
	{
		Particle* p = m_particles[count];
		m_force.y = p->GetMass() * m_gravity;
		p->Update(_deltaTIme, m_force);
		if (!p->GetDead()) continue;
		p->Reset();
		Particle::Pool->ReleaseResource(p);
		m_particles.erase(m_particles.begin() + count);
		count--;
	}
}

Particle* PhysicsController::AddParticle(glm::vec2 _position, float _lifeTime)
{
	Particle* particle = Particle::Pool->GetResource();
	particle->SetPosition(_position);
	particle->SetLifeTime(_lifeTime);
	particle->SetMass(1);
	m_particles.push_back(particle);
	return particle;
}

string PhysicsController::ToString()
{
	string retVal = "Particles: ";
	retVal
		+= to_string(m_particles.size());
	return retVal;
}
