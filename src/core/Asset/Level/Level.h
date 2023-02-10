#ifndef LEVEL_H
#define LEVEL_H

#include "core/Resource/Resource.h"

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
	//vector<Unit*> m_units;
};

#endif // !LEVEL_H

