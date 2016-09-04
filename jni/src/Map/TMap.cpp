#include "Map/TMap.h"

TMap::TMap(Updatable* parent, File& file) : Map(parent), m_mtl()
{
	TileInfo* info = new TileInfo();
	info->cost = 1;
	m_tileInfo.insert(std::pair<std::string, TileInfo*>("grass", info));
	parse(file);
}

TMap::~TMap()
{
	for(std::map<std::string, TileInfo*>::iterator it = m_tileInfo.begin(); it != m_tileInfo.end(); it++)
		if(it->second)
			delete it->second;
}

createStaticTilePtr TMap::getStaticTileFunction(const char* name, const char* type) const
{
	return staticTileFactory<DefaultTile>;
}

Material* TMap::getStaticTileMaterial(const char* name, const char* type)
{
	return &m_mtl;
}

void* TMap::getStaticTileInfo(const char* name, const char* type)
{
//	if(!strcmp(type, "grass"))
	return (void*)m_tileInfo["grass"];
//	return NULL;
}

createDynamicAnimPtr TMap::getDynamicAnimFunction(const char* name) const
{
	return NULL;
}

Material* TMap::getDynamicAnimMaterial(const char* name)
{
	return NULL;
}

createStaticAnimPtr TMap::getStaticAnimFunction(const char* name) const
{
	return NULL;
}

Material* TMap::getStaticAnimMaterial(const char* name)
{
	return &m_mtl;
}

createObjectPtr TMap::getObjectFunction(const char* name, const char* type) const
{
	return objectFactory<TileObject>;
}
