#ifndef DEF_TACTICSRENDERER
#define DEF_TACTICSRENDERER

#include "Renderer.h"
#include "GameResources.h"
#include "Contexts/Game.h"

class TacticsRenderer : public Renderer
{
	public:
		TacticsRenderer(Updatable* parent);
		~TacticsRenderer();
		void onFocus(uint32_t pID, Render& render);
		void accelerometerEvent(float x, float y, float z);
		void init();
	private:
		Game* m_game = NULL;
};

#endif

