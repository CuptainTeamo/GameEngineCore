#include "FileController.h"

FileController::FileController()
{
	m_handle = nullptr;
	m_readSuccess = false;
	m_thread = {};
}

FileController::~FileController()
{
}

string FileController::GetCurDirectory()
{
	char buff[FILENAME_MAX];
	M_ASSERT(GetCurrentDir(buff, FILENAME_MAX) != nullptr, "Could not get current directory.");
	return string(buff);
}

int FileController::GetFileSize(string _filePath)
{
	m_handle = nullptr;
	M_ASSERT(fopen_s(&m_handle, _filePath.c_str(), "rb") == 0, "Could not open file.");
	if (m_handle != nullptr)
	{
		M_ASSERT(fseek(m_handle, 0, SEEK_END) == 0, "Could not seek to end of file.");
		int fileSize = ftell(m_handle); // current position
		M_ASSERT(fileSize != -1L, "Could not determine file size");
		M_ASSERT(fclose(m_handle) == 0, "Could not close file.");
		return fileSize;
	}
	return -1;
}

bool FileController::ReadFile(string _filePath, unsigned char* _buffer, unsigned int _bufferSize)
{
	m_handle = nullptr;
	m_readSuccess = false;
	M_ASSERT(fopen_s(&m_handle, _filePath.c_str(), "rb") == 0, "Could not open file.");
	if (m_handle != nullptr)
	{
		M_ASSERT(fread(_buffer, 1, _bufferSize, m_handle) == _bufferSize, "All bytes not read from file.");
		M_ASSERT(ferror(m_handle) == 0, "Error reading from file."); // error got
		M_ASSERT(fclose(m_handle) == 0, "Could not close file.");
		m_readSuccess = true;
	}
	if (m_thread.joinable())
	{
		m_thread.detach();
	}
	return false;
}

void FileController::ReadFileAsync(string _filePath, unsigned char* _buffer, unsigned int _bufferSize)
{
	m_thread = thread(&FileController::ReadFile, this, _filePath, _buffer, _bufferSize);
}

bool FileController::GetFileReadDone()
{
	return (!m_thread.joinable());
}

bool FileController::GetFileReadSuccess()
{
	return m_readSuccess;
}
