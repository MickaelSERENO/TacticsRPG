#include "Map/TMap.h"

TMap::TMap(Updatable* parent, File& file) : Map(parent), m_mtl()
{
	parse(file);
}

createStaticTilePtr TMap::getStaticTileFunction(const char* name, const char* type) const
{
	return staticTileFactory<DefaultTile>;
}

Material* TMap::getStaticTileMaterial(const char* name, const char* type)
{
	LOG_ERROR("GET MATERIAL !");
	return &m_mtl;
}

createDynamicAnimPtr TMap::getDynamicAnimFunction(const char* name) const
{
	return NULL;
}

Material* TMap::getDynamicAnimMaterial(const char* name, const char* type)
{
	return NULL;
}

createStaticAnimPtr TMap::getStaticAnimFunction(const char* name) const
{
	return NULL;
}

Material* TMap::getStaticAnimMaterial(const char* name, const char* type)
{
	return &m_mtl;
}

createObjectPtr TMap::getObjectFunction(const char* name, const char* type) const
{
	return NULL;
}
