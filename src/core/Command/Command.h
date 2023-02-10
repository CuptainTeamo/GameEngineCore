#ifndef COMMAND_INTERFACE_H
#define COMMAND_INTERFACE_H

#include "StandardIncludes.h"

class Command
{
public:
	virtual ~Command() {}
	virtual bool Execute(char _button) = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
	bool undoable = false;
	bool redoable = false;
};

#endif // !COMMAND_INTERFACE_H

