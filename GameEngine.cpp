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
		cout << "Index () Undo count () Redo count ()" << endl;
		cin >> choice;
		choice = toupper(choice);

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

