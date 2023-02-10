#ifndef COMMAND_ADD_CHUNK_H
#define COMMAND_ADD_CHUNK_H

#include "StandardIncludes.h"
#include "core/Command/Command.h"
#include "Resource/Level/Level.h"

class CommandAddChunk :public Command
{
public:
	CommandAddChunk(Level* _level);
	virtual bool Execute(char _button);
	virtual void Undo();
	virtual void Redo();
protected:
	Level* m_level;
};

#endif // !COMMAND_ADD_CHUNK_H

