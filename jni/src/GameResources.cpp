#include "GameResources.h"

ResourcesManager<Font*, clean<Font*>> fontResources();

void initFontResources()
{
	fontResources.add("DejaVuSansMono", Font::openFromAssets("DejaVuSansMono.ttf"));
}
