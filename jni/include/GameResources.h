#ifndef  GAMERESOURCES_INC
#define  GAMERESOURCES_INC

#include "ResourcesManager.h"
#include "Graphics/Font.h"
#include "Graphics/Texture.h"

#define TILE_PER_ROW 20

extern ResourcesManager<Font*, clean<Font*>> fontResources;
extern ResourcesManager<Texture*, clean<Texture*>> textureResources;
extern uint32_t width;
extern uint32_t height;
void initFontResources();
Texture* getTexture(const std::string& path);

#endif
