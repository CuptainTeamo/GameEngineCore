#include "CommandAddChunk.h"

CommandAddChunk::CommandAddChunk(Level* _level)
{
	m_level = _level;
	m_chunkIndex = 0;
	m_chunkIndexBefore = 0;
	m_usedBufferSize = 0;
	m_usedBufferSizeBefore = 0;
}

void CommandAddChunk::Execute(char _button)
{
	m_chunkIndexBefore = m_level->GetIndex();
	m_usedBufferSizeBefore = m_level->GetUsedBufferSize();
	

	// Execute!
	// if add chunk
	m_level->AddChunk();

}

void CommandAddChunk::Undo()
{

	// Undo is remove
	m_level->RemoveChunk();
	cout << "undo" << endl;

}
