#ifndef PLAY_COMMANDS_H
#define PLAY_COMMANDS_H

#include "StandardIncludes.h"

class Command;
class Level;

class PlayCommands
{
public:
	PlayCommands();
	virtual ~PlayCommands();
	void HandleInput(char _button);
	void Undo();
	void Redo();

	// accessors
	Level* GetLevel() { return m_level; }
	int GetUndoNum() { return m_undoCommands.size(); }
	int GetRedoNum() { return m_redoCommands.size(); }

private:
	vector<Command*> m_undoCommands;
	vector<Command*> m_redoCommands;
	Level* m_level;

	// if undo any command
	bool m_undoed;
};
#endif // !PLAY_COMMANDS_H

