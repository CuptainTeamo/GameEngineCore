#ifndef UNIT_H
#define UNIT_H

#include "core/Resource/Resource.h"
#include "../SoundEffect/SoundEffect.h"

class Unit :public Resource
{
public:
	// Cons/Dest
	Unit();
	virtual ~Unit();

	// Methods
	void Serialize(ostream& _stream) override;
	void Deserialize(istream& _stream) override;
	void ToString() override;
	void AssignNonDefaultValues() override;

	// members
	static ObjectPool<Unit>* Pool;

private:
	SoundEffect* m_soundEffect;
};

#endif // !UNIT_H

