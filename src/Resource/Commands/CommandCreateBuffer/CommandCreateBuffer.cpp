#include "CommandCreateBuffer.h"

CommandCreateBuffer::CommandCreateBuffer(Level* _level)
{
	m_level = _level;
}

void CommandCreateBuffer::Execute(char _button)
{
	// add chunk
	m_level->CreateImageBuffer();

}

void CommandCreateBuffer::Undo()
{

	// Undo is remove
	m_level->DeleteImageBuffer();

}

void CommandCreateBuffer::Redo()
{
	// Not Redoable
	
}
