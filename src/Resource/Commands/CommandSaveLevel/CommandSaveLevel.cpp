#include "CommandSaveLevel.h"

CommandSaveLevel::CommandSaveLevel(Level* _level)
{
	m_level = _level;
}

void CommandSaveLevel::Execute(char _button)
{
	// Delete buffer
	m_level->SaveLevel();

}

void CommandSaveLevel::Undo()
{

	// Not Undoable

}

void CommandSaveLevel::Redo()
{
	// Not Redoable
}
