#ifndef ASSET_CONTROLLER_H
#define ASSET_CONTROLLER_H

#include "../../StandardIncludes.h"
#include "../StackAllocator/StackAllocator.h"
#include "../Asset/Asset.h"

class AssetController :public Singleton<AssetController>
{
public:
	// Cons/Dest
	AssetController();
	virtual ~AssetController();

	// Methods
	void Initialize(int _stackSize);
	void Clear();
	Asset* GetAsset(string _guid);

	// Members
	static StackAllocator* Stack;
private:
	map<string, Asset*> m_assets;
};

#endif // !ASSET_CONTROLLER_H

