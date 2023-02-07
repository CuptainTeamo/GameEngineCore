#include "Level.h"

StackAllocator* Level::ImageBuffer = nullptr;

Level::Level()
{
	// initialize everything in the sub members
	AssetController::Instance().Initialize(50000000);
	FileChunk::Pool = new ObjectPool<FileChunk>();

	m_fileChunks.clear();
	m_chunkIndex = 0;
	m_usedBufferSize = 0;

	string filePath = "";
	// for each unit, create new unit, assign value, and push to units
	for (int count = 0; count < 7; count++)
	{
		filePath = "chunk" + to_string(count) + ".bin";
		FileChunk* fileChunk = FileChunk::Pool->GetResource();
		fileChunk->AssignNonDefaultValues(filePath);
		m_fileChunks.push_back(fileChunk);
	}
}

Level::~Level()
{
	m_fileChunks.clear();
	delete FileChunk::Pool;
	AssetController::Instance().Clear();
	if (Level::ImageBuffer != nullptr)
	{
		Level::ImageBuffer->ClearMemory();
	}
	Level::ImageBuffer = nullptr;
	m_chunkIndex = 0;
	m_usedBufferSize = 0;
}

void Level::AssignNonDefaultValues()
{
	Resource::AssignNonDefaultValues();
}

void Level::CreateImageBuffer()
{
	if (Level::ImageBuffer != nullptr)
	{
		cout << "Image Buffer already exists" << endl;
		return;
	}
	int bufferSize = 0;
	for (auto chunk : m_fileChunks)
	{
		bufferSize += chunk->GetFileChunk()->GetDataSize();
	}
	ImageBuffer = new StackAllocator();
	Level::ImageBuffer->AllocateStack(bufferSize);
}

void Level::DeleteImageBuffer()
{
	if (Level::ImageBuffer == nullptr)
	{
		cout << "No Image Buffer to be deleted." << endl;
		return;
	}
	delete ImageBuffer;
	ImageBuffer = nullptr;
	cout << "Delete Successfully" << endl;
}

int Level::LoadChunkToLevel(unsigned int _index, unsigned int _usedBufferSize)
{
	int dataSize = m_fileChunks[_index]->GetFileChunk()->GetDataSize();
	byte* startPosition = Level::ImageBuffer->GetStartPosition() + _usedBufferSize;
	memcpy(startPosition, m_fileChunks[_index]->GetFileChunk()->GetData(), dataSize);
	return dataSize;
}

void Level::AddChunk()
{
	if (Level::ImageBuffer == nullptr)
	{
		cout << "No Image Buffer Created. Please use [C] to create Image Buffer first" << endl;
		return;
	}
	// else if, no more chunk to add
	// to do


	// copy data
	m_usedBufferSize += LoadChunkToLevel(m_chunkIndex, m_usedBufferSize);
	m_chunkIndex++;
	SaveImage();
}

void Level::RemoveChunk()
{
	if (m_chunkIndex == 0)
	{
		cout << "There is no chunk in the buffer, please [A]dd chunks first." << endl;
		return;
	}
	int dataSize = m_fileChunks[(m_chunkIndex - 1)]->GetFileChunk()->GetDataSize();
	byte* start0Pos = Level::ImageBuffer->GetStartPosition() + m_usedBufferSize - dataSize;

	// reset rest memory to 0
	memset(start0Pos, 0, dataSize);

	m_chunkIndex--;
	m_usedBufferSize -= dataSize;
	SaveImage();
}

void Level::SaveImage()
{
	ofstream writeStream("NewImage.tga", ios::out | ios::binary);
	writeStream.write(reinterpret_cast<char*>(Level::ImageBuffer->GetStartPosition()), Level::ImageBuffer->GetStackSize());
	writeStream.close();
}

void Level::SaveLevel()
{
	ofstream writeStream("level.bin", ios::out | ios::binary);
	Serialize(writeStream);
	writeStream.close();
	cout << "Level Saved: " << typeid(Level).name() << endl;
	cout << endl;
}

void Level::LoadLevel()
{
	ifstream readStream("level.bin", ios::out | ios::binary);
	Deserialize(readStream);
	readStream.close();

	Level::ImageBuffer->ResetMemory();
	// using loaded data to load assets to level
	int bufferSize = 0;
	int loadedChunk = 0;
	while (loadedChunk < m_chunkIndex) {
		bufferSize += LoadChunkToLevel(loadedChunk, bufferSize);
		loadedChunk++;
	}
	SaveImage();
	cout << "Loaded Level: " << endl;
	cout << endl;

}

void Level::Serialize(ostream& _stream)
{
	_stream.write(reinterpret_cast<char*>(&m_chunkIndex), sizeof(m_chunkIndex));
	_stream.write(reinterpret_cast<char*>(&m_usedBufferSize), sizeof(m_usedBufferSize));
	
	/*
	// Store the number of elements in vector
	int numberOfChunks = m_fileChunks.size();
	_stream.write(reinterpret_cast<char*>(&numberOfChunks), sizeof(numberOfChunks));

	// for each element in vector, save them by pointer
	for (int count = 0; count < numberOfChunks; count++)
	{
		SerializePointer(_stream, m_fileChunks[count]);
	}
	*/
	Resource::Serialize(_stream);

}

void Level::Deserialize(istream& _stream)
{
	_stream.read(reinterpret_cast<char*>(&m_chunkIndex), sizeof(m_chunkIndex));
	_stream.read(reinterpret_cast<char*>(&m_usedBufferSize), sizeof(m_usedBufferSize));
	// Already loaded default assets, no need to load assets
	// load assets to level
	for (int count = 0; count < m_chunkIndex; count++)
	{

	}
	Resource::Deserialize(_stream);
}

void Level::ToString()
{
	cout << "LEVEL" << endl;
	//cout << "MapSizeX: " << m_mapSizeX << endl;
	//cout << "MapSizeY: " << m_mapSizeY << endl;
	//cout << "GameTime: " << m_gameTime << endl;
	for (int count = 0; count < m_fileChunks.size(); count++)
	{
		m_fileChunks[count]->ToString();
	}
	Resource::ToString();
}
