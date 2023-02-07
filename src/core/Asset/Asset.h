#ifndef ASSET_H
#define ASSET_H

#include "StandardIncludes.h"
#include "core/ObjectPool/ObjectPool.h"

class Asset
{
public:
	// Cons/Dest
	Asset();
	virtual ~Asset(){}

	// Accessors
	string GetGUID() { return m_GUID; }
	int GetDataSize() { return m_dataSize; }
	byte* GetData() { return m_data; }
	void SetDataSize(int _size) { m_dataSize = _size; }
	void SetData(byte* _data) { m_data = _data; }
	void SetGUID(string _guid) { m_GUID = _guid; }

	// Methods
	void ToString();
	void Reset();
	static ObjectPool<Asset>* Pool;

private:
	string m_GUID;
	int m_dataSize;
	byte* m_data;
};

#endif // !ASSET_H

