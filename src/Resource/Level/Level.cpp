#include "Level.h"

Level::Level()
{
	// initialize everything in the sub members
	AssetController::Instance().Initialize(50000000);
	FileChunk::Pool = new ObjectPool<FileChunk>();

	m_fileChunks.clear();
}

Level::~Level()
{
	m_fileChunks.clear();
	delete FileChunk::Pool;
	AssetController::Instance().Clear();
}

void Level::AssignNonDefaultValues()
{
	string filePath = "";
	// for each unit, create new unit, assign value, and push to units
	for (int count = 0; count < 7; count++)
	{
		filePath = "chunk" + to_string(count) + ".bin";
		FileChunk* fileChunk = FileChunk::Pool->GetResource();
		fileChunk->AssignNonDefaultValues(filePath);
		m_fileChunks.push_back(fileChunk);
	}

	Resource::AssignNonDefaultValues();
}

void Level::Serialize(ostream& _stream)
{
	//_stream.write(reinterpret_cast<char*>(&m_mapSizeX), sizeof(m_mapSizeX));
	//_stream.write(reinterpret_cast<char*>(&m_mapSizeY), sizeof(m_mapSizeY));
	//_stream.write(reinterpret_cast<char*>(&m_gameTime), sizeof(m_gameTime));
	
	// Store the number of elements in vector
	int numberOfChunks = m_fileChunks.size();
	_stream.write(reinterpret_cast<char*>(&numberOfChunks), sizeof(numberOfChunks));

	// for each element in vector, save them by pointer
	for (int count = 0; count < numberOfChunks; count++)
	{
		SerializePointer(_stream, m_fileChunks[count]);
	}
	Resource::Serialize(_stream);

}

void Level::Deserialize(istream& _stream)
{
	//_stream.read(reinterpret_cast<char*>(&m_mapSizeX), sizeof(m_mapSizeX));
	//_stream.read(reinterpret_cast<char*>(&m_mapSizeY), sizeof(m_mapSizeY));
	//_stream.read(reinterpret_cast<char*>(&m_gameTime), sizeof(m_gameTime));

	// Read the number of elements in vector first
	int numberOfChunks;
	_stream.read(reinterpret_cast<char*>(&numberOfChunks), sizeof(numberOfChunks));
	// using number to iterate the rest file to get each unit
	for (int count = 0; count < numberOfChunks; count++)
	{
		//Always need object first, then write file in
		// create empty object
		//   Unit* unit = Unit::Pool->GetResource();
		FileChunk* fileChunk;
		// Deserialize to write file into object
		DeserializePointer(_stream, fileChunk);
		m_fileChunks.push_back(fileChunk);
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
