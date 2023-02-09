#ifndef COMMAND_LOAD_LEVEL_H
#define COMMAND_LOAD_LEVEL_H

#include "StandardIncludes.h"
#include "core/Command/Command.h"
#include "Resource/Level/Level.h"

class CommandLoadLevel :public Command
{
public:
	CommandLoadLevel(Level* _level);
	virtual void Execute(char _button);
	virtual void Undo();
	virtual void Redo();

	// accessors
	Level* GetLevel() { return m_level; }

private:
	Level* m_level;
	bool undoable = false;
	bool redoable = false;
};

#endif // !COMMAND_LOAD_LEVEL_H


