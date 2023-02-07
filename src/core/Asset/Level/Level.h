#ifndef LEVEL_H
#define LEVEL_H

#include "../Unit/Unit.h"

class Level :public Resource
{
public:
	// Cons/Dest
	Level();
	virtual ~Level();

	// Methods
	void Serialize(ostream& _stream) override;
	void Deserialize(istream& _stream) override;
	void ToString() override;
	void AssignNonDefaultValues() override;

private:
	int m_mapSizeX;
	int m_mapSizeY;
	float m_gameTime;
	Unit* m_unit;
};

#endif // !LEVEL_H

