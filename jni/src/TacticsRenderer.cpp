#include "TacticsRenderer.h"

TacticsRenderer::TacticsRenderer(Updatable* parent) : Renderer(parent), tmap(NULL)
{
}

TacticsRenderer::~TacticsRenderer()
{
	if(tmap)
		delete tmap;
}

void TacticsRenderer::onFocus(uint32_t pID, Render& render)
{
}

void TacticsRenderer::accelerometerEvent(float x, float y, float z)
{
}

void TacticsRenderer::init()
{
	Renderer::init();
	File file(JniMadeOf::jenv, JniMadeOf::context, "map.xml", "r");
	tmap = new TMap(this, file);
}

