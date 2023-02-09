#include "CommandRemoveChunk.h"

CommandRemoveChunk::CommandRemoveChunk(Level* _level)
{
	m_level = _level;
}

void CommandRemoveChunk::Execute(char _button)
{
	// if add chunk
	m_level->RemoveChunk();
}

void CommandRemoveChunk::Undo()
{
	// Undo Remove 
	// Add chunk
	m_level->AddChunk();
}

void CommandRemoveChunk::Redo()
{
	// Redo is itself
	m_level->RemoveChunk();
}