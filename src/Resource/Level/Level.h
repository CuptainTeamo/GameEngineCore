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
	int GetUsedBufferSize() { return m_usedBufferSize; }

	// Main functions / logic functions
	void CreateImageBuffer();
	void DeleteImageBuffer();
	void AddChunk();
	void RemoveChunk();
	// Save/Read
	void SaveLevel();
	void LoadLevel();

	// helper functions
	void SaveImage();
	// return data size for the chunk
	int LoadChunkToLevel(unsigned int _index, unsigned int _usedBufferSize);

private:
	vector<FileChunk*> m_fileChunks;
	int m_chunkIndex;

	// iamge buffer
	int m_sizeOfBuffer;
	int m_usedBufferSize;
	byte* m_iamgeBuffer;
};

#endif // !LEVEL_H

