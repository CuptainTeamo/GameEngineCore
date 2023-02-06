#ifndef RESOURCE_H
#define RESOURCE_H

#include "core/Serializable/Serializable.h"

class Resource : public Serializable
{
public:
	// Cons/Des
	Resource();
	virtual ~Resource();

	// Methods
	virtual void Serialize(ostream& _stream);
	virtual void Deserialize(istream& _stream);
	void AssignNonDefaultValues();
	void ToString();

private:
	int m_val1;
	double m_val2;
	char m_val3;
};
#endif // !RESOURCE_H

