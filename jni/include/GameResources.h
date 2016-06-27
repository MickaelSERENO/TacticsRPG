#ifndef  GAMERESOURCES_INC
#define  GAMERESOURCES_INC

#include "ResourcesManager.h"
#include "Graphics/Font.h"

extern ResourcesManager<Font*, clean<Font*>> fontResources;
void initFontResources();

#endif
