#include "PhysicsController.h"
#include "core/Renderer/Renderer.h"
#include "Particle/Particle.h"
#include "RigidBody/RigidBody.h"

PhysicsController::PhysicsController()
{
	m_gravity = -9.81f;
	m_force = glm::vec2{ 0, 0 };
	Particle::Pool = new ObjectPool<Particle>();
	RigidBody::Pool = new ObjectPool<RigidBody>();
}

PhysicsController::~PhysicsController()
{
	delete Particle::Pool;
	delete RigidBody::Pool;
}

void PhysicsController::Update(float _deltaTIme)
{
	for (int count = 0; count < m_particles.size(); count++)
	{
		Particle* p = m_particles[count];
		m_force.y = m_gravity;
		p->Update(_deltaTIme, m_force);
		if (!p->GetDead()) continue;
		p->Reset();
		Particle::Pool->ReleaseResource(p);
		m_particles.erase(m_particles.begin() + count);
		count--;
	}

	Point p = Renderer::Instance().GetWindowSize();
	glm::vec2 out;
	for (int count = 0; count < m_bodies.size(); count++)
	{
		RigidBody* b = m_bodies[count];
		m_force.y = m_gravity;
		b->Update(_deltaTIme, m_force);
		if (b->GetPosition().y >= 200)
		{
			glm::vec2 p = b->GetPosition();
			p.y = 200;
			b->SetPosition(p);
			b->SetVelocity(glm::vec2(0, 0));
		}
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

RigidBody* PhysicsController::AddRigidBody(glm::vec2 _position, glm::vec2 _direction, float _mass)
{
	RigidBody* body = RigidBody::Pool->GetResource();
	body->SetPosition(_position);
	body->SetVelocity(_direction);
	body->SetMass(_mass);
	m_bodies.push_back(body);
	return body;
}

void PhysicsController::Reflect(glm::vec2& _out, const glm::vec2& _incident, const glm::vec2& _normal)
{
	_out = _incident - 2.f * glm::dot(_incident, _normal) * _normal;
}

void PhysicsController::HandleCollision(RigidBody* _b1, RigidBody* _b2, float _distance)
{
	glm::vec2 x = _b1->GetPosition() - _b2->GetPosition();
	glm::vec2 v = _b1->GetVelocity() - _b2->GetVelocity();
	glm::vec2 v1 = _b1->GetVelocity();
	v1 -= (2 * _b2->GetMass() / (_b1->GetMass() + _b2->GetMass())) * (glm::dot(v, x) / ((float)pow((glm::length(x)), 2))) * x;
	_b1->SetVelocity(v1);

	x *= -1;
	v *= -1;
	glm::vec2 v2 = _b2->GetVelocity();
	v2 -= (2 * _b1->GetMass() / (_b1->GetMass() + _b2->GetMass())) * (glm::dot(v, x) / ((float)pow((glm::length(x)), 2))) * x;
	_b2->SetVelocity(v2);
}

string PhysicsController::ToString()
{
	string retVal = "Particles: ";
	retVal += to_string(m_particles.size());
	retVal += " RigidBodies: ";
	retVal += to_string(m_bodies.size());
	return retVal;
}
