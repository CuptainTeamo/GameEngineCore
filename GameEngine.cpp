#include <iostream>
#include "src/core/FileController/FileController.h"

int main()
{
	FileController* fc = &FileController::Instance();
	cout << fc->GetCurDirectory() << endl;
	int fs = fc->GetFileSize("src/core/FileController/FileController.cpp");
	unsigned char* buffer = new unsigned char[fs];
	fc->ReadFileAsync("src/core/FileController/FileController.cpp", buffer, fs);
	while (!fc->GetFileReadDone())
	{
		cout << "Thread running....." << endl;
	}
	if (fc->GetFileReadSuccess())
	{
		cout << "File size " << fs << endl;
	}
	else
	{
		cout << "File read unsuccessful." << endl;
	}
	delete[] buffer;
}

