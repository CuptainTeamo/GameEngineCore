#include "CommandRemoveChunk.h"

CommandRemoveChunk::CommandRemoveChunk(Level* _level)
{
	m_level = _level;
	m_chunkIndex = 0;
	m_chunkIndexBefore = 0;
	m_usedBufferSize = 0;
	m_usedBufferSizeBefore = 0;
}

void CommandRemoveChunk::Execute(char _button)
{
	m_chunkIndexBefore = m_level->GetIndex();
	m_usedBufferSizeBefore = m_level->GetUsedBufferSize();


	// Execute!
	// if add chunk
	m_level->RemoveChunk();
}

void CommandRemoveChunk::Undo()
{
	// Undo Remove 
	// Add chunk
	m_level->AddChunk();
}
