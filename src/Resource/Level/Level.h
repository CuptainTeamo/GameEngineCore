#ifndef LEVEL_H
#define LEVEL_H

#include "../FileChunk/FileChunk.h"

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
	vector<FileChunk*> m_fileChunks;
};

#endif // !LEVEL_H

