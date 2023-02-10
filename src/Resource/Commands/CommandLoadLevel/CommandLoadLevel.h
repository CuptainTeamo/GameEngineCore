#ifndef COMMAND_LOAD_LEVEL_H
#define COMMAND_LOAD_LEVEL_H

#include "StandardIncludes.h"
#include "core/Command/Command.h"
#include "Resource/Level/Level.h"

class CommandLoadLevel :public Command
{
public:
	CommandLoadLevel(Level* _level);
	virtual bool Execute(char _button);
	virtual void Undo();
	virtual void Redo();

	// accessors
	Level* GetLevel() { return m_level; }

private:
	Level* m_level;
};

#endif // !COMMAND_LOAD_LEVEL_H


