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
	unsigned char* GetStartPosition() { return m_stackStart; }
	unsigned char* GetEndPoistion() { return m_stackEnd; }
	int GetStackSize() { return(m_stackEnd - m_stackStart); }


	// methods
	void AllocateStack(unsigned int _stackSizeByte);
	unsigned char* GetMemory(unsigned int _sizeByte);
	void Mark();
	void FreeToMarker();
	void ClearMemory();
	void ResetMemory();

private:
	unsigned int m_stackSize;
	unsigned char* m_marker;
	unsigned char* m_stackStart;
	unsigned char* m_stackEnd;
	unsigned char* m_stackPosition;
};

#endif