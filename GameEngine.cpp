#include <iostream>
#include "src/core/FileController/FileController.h"

int main()
{
	FileController* fc = &FileController::Instance();
	cout << fc->GetCurDirectory() << endl;
	int fs = fc->GetFileSize("src/core/FileController/FileController.h");
	unsigned char* buffer = new unsigned char[fs];
	if (fc->ReadFile("src/core/FileController/FileController.h", buffer, fs))
	{
		cout << "File read operation successful." << endl;
	}
	delete[] buffer;
}

