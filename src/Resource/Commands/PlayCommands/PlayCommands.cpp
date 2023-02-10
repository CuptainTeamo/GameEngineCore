#include "PlayCommands.h"
#include "Resource/Level/Level.h"
#include "../CommandAddChunk/CommandAddChunk.h"
#include "../CommandSaveLevel/CommandSaveLevel.h"
#include "../CommandLoadLevel/CommandLoadLevel.h"
#include "../CommandRemoveChunk/CommandRemoveChunk.h"
#include "../CommandCreateBuffer/CommandCreateBuffer.h"
#include "..//CommandDeleteBuffer/CommandDeleteBuffer.h"

PlayCommands::PlayCommands()
{
	m_level = new Level();
	m_level->AssignNonDefaultValues();
	m_undoCommands.clear();
	m_redoCommands.clear();
	m_undoed = false;
}

PlayCommands::~PlayCommands()
{
	delete m_level;

	// delete commands
	// todo 
}

void PlayCommands::HandleInput(char _button)
{
	m_undoed = false;
	Command* playCommand = nullptr;
	if (_button == 'A') playCommand = new CommandAddChunk(m_level);
	else if (_button == 'S') playCommand = new CommandSaveLevel(m_level);
	else if (_button == 'R') playCommand = new CommandRemoveChunk(m_level);
	else if (_button == 'C') playCommand = new CommandCreateBuffer(m_level);
	else if (_button == 'D') playCommand = new CommandDeleteBuffer(m_level);
	else if (_button == 'L')
	{
		delete m_level;
		m_level = new Level();
		playCommand = new CommandLoadLevel(m_level);
	}
	else if (_button == 'Z') { Undo(); return; }
	else if (_button == 'Y') { Redo(); return; }
	
	// logic
	// new not s command will clean the redo commands
	// S command will only be execute, wont add to lists
	if (playCommand != nullptr) // not undo/redo commands
	{

		// Only deal with redo/undo when command run successfully
		if (playCommand->Execute(_button))
		{

			// skip Save command
			// save command should not effect undo function
			if (_button != 'S')
			{

				// when add new command
				// there will not be any command to redo
				m_redoCommands.clear();

				m_undoCommands.push_back(playCommand);

				// if command is not undable -> load
				// clear undocommands list
				if (playCommand->undoable == false)
				{
					cout << "This Command is Undoable!" << endl;
					cout << "Set available undo and redo commands to 0" << endl;
					m_undoCommands.clear();
				}
			}

		}

	}
}

void PlayCommands::Undo()
{
	if (m_undoCommands.size() > 0)
	{
		Command* lastCommand = m_undoCommands.back();
		lastCommand->Undo();
		cout << "Command Undo" << endl;
		m_redoCommands.push_back(lastCommand);
		m_undoCommands.pop_back();
		m_undoed = true;

		if (lastCommand->redoable == false)
		{
			cout << "This command is not redoable, set available redoable commands to 0" << endl;
			m_redoCommands.clear();
		}
	}
	else
	{
		cout << "No available Undo commands!" << endl;
	}
}

// to do list
void PlayCommands::Redo()
{
	if (m_redoCommands.size() > 0)
	{
		m_undoed = true;
		Command* undoCommand = m_redoCommands.back();
		undoCommand->Undo();
		cout << "Command Redo" << endl;
		m_undoCommands.push_back(undoCommand);
		m_undoCommands.pop_back();
	}
	else
	{
		cout << "No available Redo commands!" << endl;
	}

}
