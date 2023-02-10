#include "CommandCreateBuffer.h"

CommandCreateBuffer::CommandCreateBuffer(Level* _level)
{
	m_level = _level;
	undoable = true;
	redoable = false;
}

bool CommandCreateBuffer::Execute(char _button)
{
	// add chunk
	return m_level->CreateImageBuffer();

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
