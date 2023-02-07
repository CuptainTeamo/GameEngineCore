#include "Resource.h"

ObjectPool<Resource>* Resource::Pool;

Resource::Resource()
{
}

Resource::~Resource()
{
}

void Resource::AssignNonDefaultValues()
{
}

void Resource::ToString()
{
	cout << "BASE RESOURCE" << endl;
}

// store string GUID, then use GUID to get/load assets when deserialization
void Resource::SerializeAsset(ostream& _stream, Asset* _asset)
{
	byte guidLength = 0;
	if (_asset != nullptr)
	{
		guidLength = _asset->GetGUID().length();
	}
	_stream.write(reinterpret_cast<char*>(&guidLength), sizeof(guidLength));
	if (guidLength > 0)
	{
		_stream.write(_asset->GetGUID().c_str(), guidLength);
	}
}

void Resource::DeserializeAsset(istream& _stream, Asset*& _asset)
{
	byte guidLength = 0;
	_stream.read(reinterpret_cast<char*>(&guidLength), sizeof(guidLength));
	if (guidLength > 0)
	{
		char guid[255];
		_stream.read(guid, guidLength);
		guid[guidLength] = 0; // null terminate string

		// Load asset again by using stored guid
		_asset = AssetController::Instance().GetAsset(string(guid));
	}
}

void Resource::Serialize(ostream& _stream)
{
}

void Resource::Deserialize(istream& _stream)
{
}