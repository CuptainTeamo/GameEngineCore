#include <iostream>
#include "src/core/FileController/FileController.h"
#include "src/core/StackAllocator/StackAllocator.h"

int main()
{
	FileController* fc = &FileController::Instance();
	StackAllocator* sa = new StackAllocator();
	sa->AllocateStack(10000);

	int fs1 = fc->GetFileSize("src/core/StackAllocator/StackAllocator.h");
	unsigned char* file1 = sa->GetMemory(fs1);
	fc->ReadFile("src/core/StackAllocator/StackAllocator.h", file1, fs1);
	cout << file1 << endl;

	int fs2 = fc->GetFileSize("src/core/FileController/FileController.h");
	unsigned char* file2 = sa->GetMemory(fs2);
	fc->ReadFile("src/core/FileController/FileController.h", file2, fs2);
	sa->Mark();
	cout << file2 << endl;

	int fs3 = fc->GetFileSize("src/core/Singleton/Singleton.h");
	unsigned char* file3 = sa->GetMemory(fs3);
	fc->ReadFile("src/core/Singleton/Singleton.h", file3, fs3);
	cout << file3 << endl;

	cout << "Byte used: " << sa->GetByteUsed() << file1 << endl;
	sa->FreeToMarker();
	cout << file1 << endl;
	cout << "Byte used: " << sa->GetByteUsed() << file1 << endl;
	delete sa;
}

