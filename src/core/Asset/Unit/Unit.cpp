#include "Unit.h"

ObjectPool<Unit>* Unit::Pool = nullptr;

Unit::Unit()
{
	m_soundEffect = nullptr;
}

Unit::~Unit()
{
}

void Unit::AssignNonDefaultValues()
{
	m_soundEffect = SoundEffect::Pool->GetResource();
	m_soundEffect->AssignNonDefaultValues();
	Resource::AssignNonDefaultValues();
}

void Unit::Serialize(ostream& _stream)
{
	SerializePointer(_stream, m_soundEffect);
	Resource::Serialize(_stream);
}

void Unit::Deserialize(istream& _stream)
{
	DeserializePointer(_stream, m_soundEffect);
	Resource::Deserialize(_stream);
}

void Unit::ToString()
{
	cout << "UNIT" << endl;
	m_soundEffect->ToString();
	Resource::ToString();
}
