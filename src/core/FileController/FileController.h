#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include "StandardIncludes.h"

class FileController : public Singleton<FileController>
{
public:
	FileController();
	virtual ~FileController();

	string GetCurDirectory();
	int GetFileSize(string _filePath);
	bool ReadFile(string _filePath, unsigned char* _buffer, unsigned int _bufferSize);
	void ReadFileAsync(string _filePath, unsigned char* _buffer, unsigned int _bufferSize);

	bool GetFileReadDone();
	bool GetFileReadSuccess();

private:
	FILE* m_handle;
	thread m_thread;
	bool m_readSuccess;
};

#endif
