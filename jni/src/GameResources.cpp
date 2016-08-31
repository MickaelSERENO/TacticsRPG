#include "GameResources.h"

ResourcesManager<Font*, clean<Font*>> fontResources = ResourcesManager<Font*, clean<Font*>>();

void initFontResources()
{
	fontResources.add("DejaVuSansMono", Font::fontFromAssets("DejaVuSansMono.ttf"));
}
