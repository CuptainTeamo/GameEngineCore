#include "CommandLoadLevel.h"

CommandLoadLevel::CommandLoadLevel(Level* _level)
{
	m_level = _level;
}

void CommandLoadLevel::Execute(char _button)
{
	m_level->LoadLevel();

}

void CommandLoadLevel::Undo()
{

	// Not Undoable

}

void CommandLoadLevel::Redo()
{
	// Not Redoable
}
