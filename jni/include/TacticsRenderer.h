#ifndef DEF_TACTICSRENDERER
#define DEF_TACTICSRENDERER

#include "Renderer.h"
#include "Map/TMap.h"
#include "Graphics/Sprite.h"
#include "Graphics/Materials/TextureMaterial.h"
#include "Graphics/Widgets/Menu.h"
#include "Graphics/Widgets/ItemMenu.h"
#include "Graphics/Font.h"
#include "Graphics/Text.h"

class TacticsRenderer : public Renderer
{
	public:
		TacticsRenderer(Updatable* parent);
		~TacticsRenderer();
		void onFocus(uint32_t pID, Render& render);
		void accelerometerEvent(float x, float y, float z);
		void init();
	private:
		TMap* tmap;
		Sprite* m_skel;
		Sprite* m_zomb;
		Texture* m_skelTexture;
		Texture* m_zombTexture;
		TextureMaterial* m_mtl;
};

#endif

