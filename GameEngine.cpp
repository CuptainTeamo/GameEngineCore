#include "Resource/Level/Level.h"

int main()
{
	Level* level = new Level();
	level->AssignNonDefaultValues();

	char choice;
	do
	{
		cout << endl;
		cout << "[Q]uit [S]ave [L]oad [Z] Undo [Y] Redo" << endl;
		cout << "[C]reate image buffer [D]elete image buffer [A]dd chunk [R]emove chunk" << endl;
		cout << "Index (" << level->GetIndex() << ") Undo count () Redo count ()" << endl;
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'C':
		{
			level->CreateImageBuffer();
			cout << "Executing: CommandCreateImageBuffer" << endl;
			break;
		}
		case 'D':
		{
			cout << "Executing: CommandDeleteImageBuffer" << endl;
			level->DeleteImageBuffer();
			break;
		}
		case 'S':
		{
			level->SaveLevel();
			break;
		}
		case 'L':
		{
			// delete level
			delete level;
			// create default value
			level = new Level();
			// Load data
			level->CreateImageBuffer();
			level->LoadLevel();
			break;
		}
		case 'A':
		{
			level->AddChunk();
			break;
		}
		case 'R':
		{
			level->RemoveChunk();
			break;
		}
			
		}

	} while (choice != 'Q');
	/*
	ofstream writeStream("level.bin", ios::out | ios::binary);
	level->Serialize(writeStream);
	writeStream.close();
	cout << "Level To Save:";
	level->ToString();
	delete level;
	cout << endl;
	*/

	/*
	Level* loadedLevel = new Level();
	ifstream readStream("level.bin", ios::in | ios::binary);
	loadedLevel->Deserialize(readStream);
	readStream.close();
	cout << "Loaded Level:";
	loadedLevel->ToString();
	delete loadedLevel;
	*/
}

