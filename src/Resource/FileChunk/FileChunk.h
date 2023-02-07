#ifndef FILE_CHUNK_H
#define FILE_CHUNK_H

#include "core/Resource/Resource.h"
#include "core/Asset/Asset.h"

class FileChunk :public Resource
{
public:
	// Cons/Dest
	FileChunk();
	virtual ~FileChunk();

	// Methods
	void Serialize(ostream& _stream) override;
	void Deserialize(istream& _stream) override;
	void ToString() override;
	void AssignNonDefaultValues(string _filePath);

	// Accessors
	Asset* GetFileChunk() { return m_fileChunk; }

	// members
	static ObjectPool<FileChunk>* Pool;
private:
	Asset* m_fileChunk;
};

#endif // !FILE_CHUNK_H

