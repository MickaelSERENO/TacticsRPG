#include "TacticsRenderer.h"

TacticsRenderer::TacticsRenderer(Updatable* parent) : Renderer(parent), tmap(NULL)
{
}

TacticsRenderer::~TacticsRenderer()
{
	if(tmap)
		delete tmap;
/*  delete m_zombTexture;
	delete m_skelTexture;
	delete m_zomb;
	delete m_skel;
	*/
}

void TacticsRenderer::onFocus(uint32_t pID, Render& render)
{
	/*
	glm::vec4 v(touchCoord[pID].x, touchCoord[pID].y, 0.0f, 1.0f);
	v = glm::inverse(getCamera().getMatrix())*v;
	if(tmap->getTile(v.x, v.y))
		LOG_ERROR("Yeah ! ");
	*/
}

void TacticsRenderer::accelerometerEvent(float x, float y, float z)
{
}

void TacticsRenderer::init()
{
	Renderer::init();

	File file(JniMadeOf::jenv, JniMadeOf::context, "Resources/Tile.xml", "r");
	m_mtl = new TextureMaterial();
	tmap = new TMap(this, file);
	tmap->setUpdateFocus(false);
	tmap->scale(glm::vec3(0.01, 0.01, 0.01)*0.5f);
	tmap->move(glm::vec3(-1.0, -1.0, 0.0));
}
