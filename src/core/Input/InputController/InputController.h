#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include "StandardIncludes.h"

class Keyboard;

class InputController :public Singleton<InputController>
{
public:
	// Cons/Dest
	InputController();
	virtual ~InputController();

	// Accessors
	Keyboard* KB() { return m_keyboard; }

private:
	Keyboard* m_keyboard;
};

#endif // !INPUTCONTROLLER_H

