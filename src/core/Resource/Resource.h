#ifndef RESOURCE_H
#define RESOURCE_H

#include "core/Serializable/Serializable.h"
#include "core/AssetController/AssetController.h"

class Resource : public Serializable
{
public:
	// Cons/Des
	Resource();
	virtual ~Resource();

	// Methods
	virtual void Serialize(ostream& _stream);
	virtual void Deserialize(istream& _stream);
	virtual void AssignNonDefaultValues();
	virtual void ToString();

	// members
	static ObjectPool<Resource>* Pool;

protected:
	template<class T>
	void SerializePointer(ostream& _stream, T* _pointer)
	{
		byte exists = 1;
		if (_pointer != nullptr)
		{
			_stream.write(reinterpret_cast<char*>(&exists), sizeof(byte));
			_pointer->Serialize(_stream);
		}
		else
		{
			exists = 0;
			_stream.write(reinterpret_cast<char*>(&exists), sizeof(byte));
		}
	}

	// pass by reference to pass the pointer address to the function
	// change the pointer value
	template<class T>
	void DeserializePointer(istream& _stream, T*& _pointer)
	{
		byte exists = 0;
		_stream.read(reinterpret_cast<char*>(&exists), sizeof(byte));
		if (exists == 1)
		{
			_pointer = T::Pool->GetResource();
			_pointer->Deserialize(_stream);
		}
	}

	void SerializeAsset(ostream& _stream, Asset* _asset);
	void DeserializeAsset(istream& _stream, Asset*& _asset);

private:
};
#endif // !RESOURCE_H

