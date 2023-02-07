#include "FileChunk.h"

ObjectPool<FileChunk>* FileChunk::Pool = nullptr;

FileChunk::FileChunk()
{
	m_fileChunk = nullptr;
}

FileChunk::~FileChunk()
{
}

void FileChunk::AssignNonDefaultValues(string _filePath)
{
	m_fileChunk = AssetController::Instance().GetAsset(_filePath);
}

void FileChunk::Serialize(ostream& _stream)
{
	SerializeAsset(_stream, m_fileChunk);
}

void FileChunk::Deserialize(istream& _stream)
{
	DeserializeAsset(_stream, m_fileChunk);
}

void FileChunk::ToString()
{
}
