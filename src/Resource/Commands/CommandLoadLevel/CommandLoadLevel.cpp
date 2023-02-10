#include "CommandLoadLevel.h"

CommandLoadLevel::CommandLoadLevel(Level* _level)
{
	m_level = _level;
	undoable = false;
	redoable = false;
}

bool CommandLoadLevel::Execute(char _button)
{
	return m_level->LoadLevel();

}

void CommandLoadLevel::Undo()
{
	// Not Undoable
}

void CommandLoadLevel::Redo()
{
	// Not Redoable
}
