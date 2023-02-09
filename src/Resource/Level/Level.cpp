#include "Level.h"

Level::Level()
{
	// initialize everything in the sub members
	AssetController::Instance().Initialize(50000000);
	FileChunk::Pool = new ObjectPool<FileChunk>();

	// initialize all values
	m_fileChunks.clear();
	m_chunkIndex = 0;
	m_usedBufferSize = 0;
	m_sizeOfBuffer = 0;
	m_iamgeBuffer = nullptr;
}

Level::~Level()
{
	m_fileChunks.clear();
	delete FileChunk::Pool;
	AssetController::Instance().Clear();
	if (m_iamgeBuffer != nullptr)
	{
		delete m_iamgeBuffer;
	}
	m_iamgeBuffer = nullptr;
	m_sizeOfBuffer = 0;
	m_chunkIndex = 0;
	m_usedBufferSize = 0;
}

// Load chunk 0-6 assets
void Level::AssignNonDefaultValues()
{
	//load default assets
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

// Create the Image Buffer by C
// Undoable but not redoable
void Level::CreateImageBuffer()
{
	if (m_iamgeBuffer != nullptr)
	{
		cout << "Image Buffer already exists" << endl;
		return;
	}
	int bufferSize = 0;
	for (auto chunk : m_fileChunks)
	{
		bufferSize += chunk->GetFileChunk()->GetDataSize();
	}
	m_iamgeBuffer = new unsigned char[bufferSize];
	memset(m_iamgeBuffer, 0, bufferSize);
	m_sizeOfBuffer = bufferSize;

	SaveImage();
}

// Delete Image Buffer by D
// Un doable, not re doable
void Level::DeleteImageBuffer()
{
	if (m_iamgeBuffer == nullptr)
	{
		cout << "No Image Buffer to be deleted." << endl;
		return;
	}
	delete m_iamgeBuffer;
	m_iamgeBuffer = nullptr;
	cout << "Delete Successfully" << endl;
}

// The function to place asset to level Image Buffer
// return the data chunk size
int Level::LoadChunkToLevel(unsigned int _index, unsigned int _usedBufferSize)
{
	int dataSize = m_fileChunks[_index]->GetFileChunk()->GetDataSize();
	byte* startPosition = m_iamgeBuffer + _usedBufferSize;
	memcpy(startPosition, m_fileChunks[_index]->GetFileChunk()->GetData(), dataSize);
	return dataSize;
}

// Add Chunk by A
// Use LoadChunkToLevel function to add chunk to Image Buffer
// Modify the members in level
// Save Image
void Level::AddChunk()
{
	if (m_iamgeBuffer == nullptr)
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

// Remove Chunk by D
// From Image Buffer
// Modify the members in level
// Save Image
void Level::RemoveChunk()
{
	if (m_chunkIndex == 0)
	{
		cout << "There is no chunk in the buffer, please [A]dd chunks first." << endl;
		return;
	}
	int dataSize = m_fileChunks[(m_chunkIndex - 1)]->GetFileChunk()->GetDataSize();
	
	// Calculate the position in Image buffer should start reset to 0
	byte* start0Pos = m_iamgeBuffer + m_usedBufferSize - dataSize;

	// reset rest memory to 0
	memset(start0Pos, 0, dataSize);

	m_chunkIndex--;
	m_usedBufferSize -= dataSize;
	SaveImage();
}

// Called by other funtion to Save Image
void Level::SaveImage()
{
	ofstream writeStream("NewImage.tga", ios::out | ios::binary);
	writeStream.write(reinterpret_cast<char*>(m_iamgeBuffer), m_sizeOfBuffer);
	writeStream.close();
}

// Save Level by S
// Call Serialize function to serialize data
// Output file level.bin
void Level::SaveLevel()
{
	ofstream writeStream("level.bin", ios::out | ios::binary);
	Serialize(writeStream);
	writeStream.close();
	cout << "Level Saved: " << typeid(Level).name() << endl;
	cout << endl;
}

// Lave Level by L
// Call Deserialize function to Deserialize data
// Iutput file level.bin
// Load assets to Image Buffer by data loaded
// Save Image
void Level::LoadLevel()
{
	ifstream readStream("level.bin", ios::out | ios::binary);
	Deserialize(readStream);
	readStream.close();

	CreateImageBuffer();
	// Reset Image Buffer for loading data
	memset(m_iamgeBuffer, 0, m_sizeOfBuffer);

	// using LoadChunk funtion to add chunks to Image Buffer
	int bufferSize = 0;
	int loadedChunk = 0;
	while (loadedChunk < m_chunkIndex) {
		bufferSize += LoadChunkToLevel(loadedChunk, bufferSize);
		loadedChunk++;
	}

	// Save Image
	SaveImage();
	cout << "Loaded Level: " << endl;
	cout << endl;

}

// Used by Save function
// Save members data
void Level::Serialize(ostream& _stream)
{
	_stream.write(reinterpret_cast<char*>(&m_chunkIndex), sizeof(m_chunkIndex));
	_stream.write(reinterpret_cast<char*>(&m_sizeOfBuffer), sizeof(m_sizeOfBuffer));
	_stream.write(reinterpret_cast<char*>(&m_usedBufferSize), sizeof(m_usedBufferSize));
	
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

// Used by Load function
// Load members data
// use members data to place assets to Image Buffer
void Level::Deserialize(istream& _stream)
{
	_stream.read(reinterpret_cast<char*>(&m_chunkIndex), sizeof(m_chunkIndex));
	_stream.read(reinterpret_cast<char*>(&m_sizeOfBuffer), sizeof(m_sizeOfBuffer));
	_stream.read(reinterpret_cast<char*>(&m_usedBufferSize), sizeof(m_usedBufferSize));
	int numberOfChunks;
	_stream.read(reinterpret_cast<char*>(&numberOfChunks), sizeof(numberOfChunks));
	for (int count = 0; count < numberOfChunks; count++)
	{
		FileChunk* fileChunk;
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
