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

	// Methods
	int GetChunksSize() { return m_fileChunks.size(); }
	int GetIndex() { return m_chunkIndex; }
	void CreateImageBuffer();
	void DeleteImageBuffer();

	// return data size for the chunk
	int LoadChunkToLevel(unsigned int _index, unsigned int _usedBufferSize);

	// Funtional Methods
	void AddChunk();
	void RemoveChunk();
	void SaveImage();

	// Save/Read
	void SaveLevel();
	void LoadLevel();

	// Members
	static StackAllocator* ImageBuffer;

private:
	vector<FileChunk*> m_fileChunks;
	int m_chunkIndex;
	int m_usedBufferSize;
};

#endif // !LEVEL_H

