#ifndef COMMADN_DELETE_BUFFER_H
#define COMMADN_DELETE_BUFFER_H

#include "StandardIncludes.h"
#include "core/Command/Command.h"
#include "Resource/Level/Level.h"

class CommandDeleteBuffer :public Command
{
public:
	CommandDeleteBuffer(Level* _level);
	virtual bool Execute(char _button);
	virtual void Undo();
	virtual void Redo();
private:
	Level* m_level;
	int m_chunkIndex;

};

#endif // !COMMADN_DELETE_BUFFER_H


