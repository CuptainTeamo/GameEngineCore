#include "PlayCommands.h"
#include "Resource/Level/Level.h"
#include "../CommandAddChunk/CommandAddChunk.h"
#include "../CommandRemoveChunk/CommandRemoveChunk.h"

PlayCommands::PlayCommands()
{
	m_level = new Level();
	m_level->AssignNonDefaultValues();
}

PlayCommands::~PlayCommands()
{
	delete m_level;
}

void PlayCommands::HandleInput(char _button)
{
	Command* playCommand = nullptr;
	if (_button == 'A') playCommand = new CommandAddChunk(m_level);
	else if (_button == 'R') playCommand = new CommandRemoveChunk(m_level);
	else if (_button == 'Z') { Undo(); return; }
	else if (_button == 'Y') { Redo(); return; }

	if (playCommand != nullptr)
	{
		playCommand->Execute(_button);
		m_undoCommands.push_back(playCommand);
	}
}

void PlayCommands::Undo()
{
	Command* lastCommand = m_undoCommands.back();
	lastCommand->Undo();
	cout << "Command Undo" << endl;
	m_redoCommands.push_back(lastCommand);
	m_undoCommands.pop_back();
}

// to do list
void PlayCommands::Redo()
{
	Command* undoCommand = m_redoCommands.back();
	// lastCommand->Undo();
	cout << "Command Redo" << endl;
	m_undoCommands.push_back(undoCommand);
	m_undoCommands.pop_back();
}
