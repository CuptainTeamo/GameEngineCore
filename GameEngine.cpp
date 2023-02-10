#include "Resource/Commands/PlayCommands/PlayCommands.h"
#include "Resource/Level/Level.h"

int main()
{
	PlayCommands* pc = new PlayCommands();

	char choice;
	do
	{
		cout << endl;
		cout << "[Q]uit [S]ave [L]oad [Z] Undo [Y] Redo" << endl;
		cout << "[C]reate image buffer [D]elete image buffer [A]dd chunk [R]emove chunk" << endl;
		cout << "Index (" << pc->GetLevel()->GetIndex() << ") Undo count (" << pc->GetUndoNum();
		cout << ") Redo count (" << pc->GetRedoNum() << ")" << endl;
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'C': // Create Image Buffer
		{
			pc->HandleInput('C');
			cout << "Executing: CommandCreateImageBuffer" << endl;
			break;
		}
		case 'D': // Delete Image Buffer
		{
			pc->HandleInput('D');
			cout << "Executing: CommandDeleteImageBuffer" << endl;
			break;
		}
		case 'S': // Save Level
		{
			pc->HandleInput('S');
			break;
		}
		case 'L': // Load Level
		{
			pc->HandleInput('L');
			break;
		}
		case 'A': // Add Chunk
		{
			pc->HandleInput('A');
			break;
		}
		case 'R': // Remove Chunk
		{
			pc->HandleInput('R');
			break;
		}
		case 'Z': // Undo
		{
			pc->HandleInput('Z');
			break;
		}
		case 'Y': // Redo
		{
			pc->HandleInput('Y');
			break;
		}
			
		case 'Q': // Quit
		{
			delete pc;
			exit(0);
		}
		}

	} while (true);
}

