#include "StackAllocator.h"
#include "StandardIncludes.h"

StackAllocator::StackAllocator()
{
	ClearMemory();
}

StackAllocator::~StackAllocator()
{
	ClearMemory();
}

unsigned char* StackAllocator::GetMarker()
{
	return m_marker;
}

int StackAllocator::GetByteUsed()
{
	return (m_stackPosition-m_stackStart);
}

void StackAllocator::AllocateStack(unsigned int _stackSizeByte)
{
	m_stackStart = new unsigned char[_stackSizeByte];
	memset(m_stackStart, 0, _stackSizeByte);
	m_stackPosition = m_stackStart;
	m_stackEnd = m_stackStart + _stackSizeByte;
}

unsigned char* StackAllocator::GetMemory(unsigned int _sizeByte)
{
	unsigned char* hold = m_stackPosition;
	if (m_stackPosition + _sizeByte <= m_stackEnd)
	{
		m_stackPosition += _sizeByte;
		return hold;
	}
	return nullptr;
	// not enough room
}

void StackAllocator::Mark()
{
	m_marker = m_stackPosition;
}

void StackAllocator::FreeToMarker()
{
	//two methods

	// first only set the value of marked position to 0
	m_stackPosition = m_marker;
	*m_stackPosition = 0;

	// second, set all rest memory to 0
	//unsigned int size = m_stackPosition - m_marker;
	//m_stackPosition = m_marker;
	//memset(m_stackPosition, 0, size);
}

void StackAllocator::ClearMemory()
{
	// delete all stack black
	if (m_stackStart != nullptr)
	{
		delete m_stackStart;
	}

	// reset all pointer in the stack
	m_marker = nullptr;
	m_stackStart = nullptr;
	m_stackPosition = nullptr;
	m_stackEnd = nullptr;

}
