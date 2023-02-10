#include "CommandDeleteBuffer.h"

CommandDeleteBuffer::CommandDeleteBuffer(Level* _level)
{
	m_level = _level;
	undoable = true;
	redoable = false;
	m_chunkIndex = 0;
}

bool CommandDeleteBuffer::Execute(char _button)
{
	m_chunkIndex = m_level->GetIndex();
	// Delete buffer
	return m_level->DeleteImageBuffer();

}

void CommandDeleteBuffer::Undo()
{
	// Undo is Create
	m_level->CreateImageBuffer();

	// load deleted image chunk to buffer
	int bufferSize = 0;
	int loadedChunk = 0;
	while (loadedChunk < m_chunkIndex) {
		bufferSize += m_level->LoadChunkToLevel(loadedChunk, bufferSize);
		loadedChunk++;
	}
	m_level->SaveImage();
}

void CommandDeleteBuffer::Redo()
{
	// not redoable
}
