#ifndef TEXTURE_H
#define TEXTURE_H

#include "core/Resource/Resource.h"
#include "../TGAReader/TGAReader.h"

class Asset;

class Texture :public Resource
{
public:

	Texture();
	virtual ~Texture();

	// Accessors
	Asset* GetData() { return m_texture; }
	ImageInfo* GetImageInfo() { return &m_imageInfo; }

	// Methods
	void Serialize(ostream& _stream) override;
	void Deserialize(istream& _stream) override;
	void ToString() override;
	void Load(string _guid);

	//members
	static ObjectPool<Texture>* Pool;

private:
	ImageInfo m_imageInfo;
	Asset* m_texture;
};

#endif // !TEXTURE_H

