#ifndef SOUND_EFFECT_H
#define SOUND_EFFECT_H

#include "core/Asset/Asset.h"
#include "core/Resource/Resource.h"

class SoundEffect :public Resource
{
public:
	// cons/dest
	SoundEffect();
	virtual ~SoundEffect();

	// Methods
	void Serialize(ostream& _stream) override;
	void Deserialize(istream& _stream) override;
	void ToString() override;
	void AssignNonDefaultValues() override;

	// members
	static ObjectPool<SoundEffect>* Pool;

private:
	Asset* m_effect;
};

#endif // !SOUND_EFFECT_H

