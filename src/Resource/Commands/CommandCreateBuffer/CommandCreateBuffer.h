#ifndef COMMAND_CREATE_BUFFER_H
#define COMMAND_CREATE_BUFFER_H

#include "StandardIncludes.h"
#include "core/Command/Command.h"
#include "Resource/Level/Level.h"

class CommandCreateBuffer :public Command
{
public:
	CommandCreateBuffer(Level* _level);
	virtual void Execute(char _button);
	virtual void Undo();
	virtual void Redo();
private:
	Level* m_level;
	bool undoable = true;
	bool redoable = false;
};

#endif // !COMMAND_CREATE_BUFFER_H


