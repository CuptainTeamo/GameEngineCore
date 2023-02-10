#include "CommandSaveLevel.h"

CommandSaveLevel::CommandSaveLevel(Level* _level)
{
	m_level = _level;
	undoable = false;
	redoable = false;
}

bool CommandSaveLevel::Execute(char _button)
{
	// Delete buffer
	return m_level->SaveLevel();

}

void CommandSaveLevel::Undo()
{
	// Not Undoable
}

void CommandSaveLevel::Redo()
{
	// Not Redoable
}
