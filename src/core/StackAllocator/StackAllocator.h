#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

class StackAllocator
{
public:
	//Construcotr/Destructor
	StackAllocator();
	virtual ~StackAllocator();

	// getter/setter
	unsigned char* GetMarker();
	int GetByteUsed();

	// methods
	void AllocateStack(unsigned int _stackSizeByte);
	unsigned char* GetMemory(unsigned int _sizeByte);
	void Mark();
	void FreeToMarker();
	void ClearMemory();

private:
	unsigned char* m_marker;
	unsigned char* m_stackStart;
	unsigned char* m_stackEnd;
	unsigned char* m_stackPosition;
};

#endif