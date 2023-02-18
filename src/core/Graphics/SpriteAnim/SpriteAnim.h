#ifndef SPRITEANIM_H
#define SPRITEANIM_H

#include "StandardIncludes.h"
#include "core/Resource/Resource.h"

class SpriteAnim :public Resource
{
public:
	//Cons/Dest
	SpriteAnim();
	virtual ~SpriteAnim();

	// Accessors
	short GetClipCurrent() { return (short)m_clipCurrent; }

	//Methods
	virtual void Serialize(ostream& _stream);
	virtual void Deserialize(istream& _stream);
	virtual void ToString();

	void ClearMemory();
	void Create(short _clipStart, short _clipCount, float _clipSpeed);
	void Update();

	//Members
	static ObjectPool<SpriteAnim>* Pool;

private:
	short m_clipStart;
	short m_clipCount;
	short m_clipEnd;
	float m_clipCurrent;
	float m_clipSpeed;
};

#endif // !SPRITEANIM_H

