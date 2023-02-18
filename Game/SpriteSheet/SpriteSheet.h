#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "core/Graphics/SpriteAnim/SpriteAnim.h"
#include "../Texture/Texture.h"
#include "core/Graphics/BasicStructs.h"

enum AnimationNames
{
	EN_AN_IDLE = 0,
	EN_AN_RUN,
	EN_AN_DEATH
};

class SpriteSheet :public Texture
{
public:
	// cons/dest
	SpriteSheet();
	virtual ~SpriteSheet();

	// Methods
	void Serialize(ostream& _stream) override;
	void Deserialize(istream& _stream) override;
	void ToString() override;

	void SetSize(byte _rows, byte _columns, byte _clipSizeX, byte _clipSizeY);
	void AddAnimation(AnimationNames _name, short _clipStart, short _clipCount, float _clipSpeed);
	Rect Update(AnimationNames _name);

	// Members
	static ObjectPool<SpriteSheet>* Pool;
private:
	byte m_rows;
	byte m_columns;
	byte m_clipSizeX;
	byte m_clipSizeY;
	map<AnimationNames, SpriteAnim*> m_animations;
};
#endif // !SPRITESHEET_H

