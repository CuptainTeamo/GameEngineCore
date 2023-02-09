#include "CommandDeleteBuffer.h"

CommandDeleteBuffer::CommandDeleteBuffer(Level* _level)
{
	m_level = _level;
}

void CommandDeleteBuffer::Execute(char _button)
{
	// Delete buffer
	m_level->DeleteImageBuffer();

}

void CommandDeleteBuffer::Undo()
{

	// Undo is Create
	m_level->CreateImageBuffer();

}

void CommandDeleteBuffer::Redo()
{
	// not redoable
}
