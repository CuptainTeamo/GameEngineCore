#ifndef COMMAND_INTERFACE_H
#define COMMAND_INTERFACE_H

#include "StandardIncludes.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void Execute(char _button) = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
};

#endif // !COMMAND_INTERFACE_H

