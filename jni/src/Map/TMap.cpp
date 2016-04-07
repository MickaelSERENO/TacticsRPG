#include "Map/TMap.h"

TMap::TMap(Updatable* parent, File& file) : Map(parent, file), m_mtl()
{}

createStaticTilePtr TMap::getStaticTileFunction(const char* name, const char* type) const
{
	return staticTileFactory<DefaultTile>;
}

const Material* TMap::getStaticTileMaterial(const char* name, const char* type) const
{
	return &m_mtl;
}

createDynamicAnimPtr TMap::getDynamicAnimFunction(const char* name) const
{
	return NULL;
}

const Material* TMap::getDynamicAnimMaterial(const char* name, const char* type) const
{
	return NULL;
}

createStaticAnimPtr TMap::getStaticAnimFunction(const char* name) const
{
	return NULL;
}

const Material* TMap::getStaticAnimMaterial(const char* name, const char* type) const
{
	return &m_mtl;
}

createObjectPtr TMap::getObjectFunction(const char* name, const char* type) const
{
	return NULL;
}
