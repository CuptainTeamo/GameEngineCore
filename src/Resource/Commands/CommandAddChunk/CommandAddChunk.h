#ifndef COMMAND_ADD_CHUNK_H
#define COMMAND_ADD_CHUNK_H

#include "StandardIncludes.h"
#include "core/Command/Command.h"
#include "Resource/Level/Level.h"

class CommandAddChunk :public Command
{
public:
	CommandAddChunk(Level* _level);
	virtual void Execute(char _button);
	virtual void Undo();
private:
	Level* m_level;
	int m_chunkIndexBefore;
	int m_usedBufferSizeBefore;
	int m_chunkIndex;
	int m_usedBufferSize;
};

#endif // !COMMAND_ADD_CHUNK_H

