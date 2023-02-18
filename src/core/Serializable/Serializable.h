#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "../../StandardIncludes.h"

// interface class
class Serializable
{
public:
	//Cons/Des
	Serializable(){}
	virtual ~Serializable(){}

	// methods
	virtual void Serialize(std::ostream& _stream) = 0;
	virtual void Deserialize(std::istream& _stream) = 0;

};
#endif // !SERIALIZABLE_H

