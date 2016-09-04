#include "TacticsRenderer.h"

TacticsRenderer::TacticsRenderer(Updatable* parent) : Renderer(parent)
{
}

TacticsRenderer::~TacticsRenderer()
{
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
	initFontResources();
	m_game = new Game(this);
}

void TacticsRenderer::setViewport(int w, int h)
{
	Renderer::setViewport(w, h);
	width  = w;
	height = h;
}
