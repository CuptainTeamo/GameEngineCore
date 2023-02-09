#ifndef COMMAND_SAVE_LEVEL_H
#define COMMAND_SAVE_LEVEL_H

#include "StandardIncludes.h"
#include "core/Command/Command.h"
#include "Resource/Level/Level.h"

class CommandSaveLevel :public Command
{
public:
	CommandSaveLevel(Level* _level);
	virtual void Execute(char _button);
	virtual void Undo();
	virtual void Redo();
private:
	Level* m_level;
	bool undoable = false;
	bool redoable = false;
};

#endif // !COMMAND_SAVE_LEVEL_H

