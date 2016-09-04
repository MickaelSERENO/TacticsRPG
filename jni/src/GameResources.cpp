#include "GameResources.h"

ResourcesManager<Font*, clean<Font*>> fontResources = ResourcesManager<Font*, clean<Font*>>();
ResourcesManager<Texture*, clean<Texture*>> textureResources = ResourcesManager<Texture*, clean<Texture*>>();

uint32_t width  = 0;
uint32_t height = 1;

void initFontResources()
{
	fontResources.add("DejaVuSansMono", Font::fontFromAssets("DejaVuSansMono.ttf"));
}

Texture* getTexture(const std::string& path)
{
	if(textureResources.exist(path))
		return textureResources.get(path);
	Texture* t = Texture::loadAndroidFile(path.c_str());
	textureResources.add(path, t);
	return t;
}
