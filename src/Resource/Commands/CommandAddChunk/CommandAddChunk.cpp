#include "CommandAddChunk.h"

CommandAddChunk::CommandAddChunk(Level* _level)
{
	m_level = _level;
}

void CommandAddChunk::Execute(char _button)
{
	// add chunk
	m_level->AddChunk();

}

void CommandAddChunk::Undo()
{

	// Undo is remove
	m_level->RemoveChunk();

}

void CommandAddChunk::Redo()
{
	// Redo is same with itself
	m_level->AddChunk();
}
