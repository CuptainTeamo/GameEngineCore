#ifndef COMMAND_REMOVE_CHUNK_H
#define COMMAND_REMOVE_CHUNK_H

#include "StandardIncludes.h"
#include "core/Command/Command.h"
#include "Resource/Level/Level.h"

class CommandRemoveChunk :public Command
{
public:
	CommandRemoveChunk(Level* _level);
	virtual bool Execute(char _button);
	virtual void Undo();
	virtual void Redo();
private:
	Level* m_level;
};

#endif // !COMMAND_REMOVE_CHUNK_H

