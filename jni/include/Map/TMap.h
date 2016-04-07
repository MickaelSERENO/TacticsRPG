#ifndef  TMAP_INC
#define  TMAP_INC

#include "Map/Map.h"
#include "Map/TileFactory.h"
#include "Map/Tiles/DefaultTile.h"
#include "Materials/TextureMaterial.h"

class TMap : public Map
{
	public:
		TMap(Updatable* parent, File& file);

		virtual createStaticTilePtr  getStaticTileFunction(const char* name, const char* type)const; 
		virtual const Material*            getStaticTileMaterial(const char* name, const char* type)const;
		virtual createDynamicAnimPtr getDynamicAnimFunction(const char* name) const; 
		virtual const Material*            getDynamicAnimMaterial(const char* name, const char* type) const;
		virtual createStaticAnimPtr  getStaticAnimFunction(const char* name) const; 
		virtual const Material*            getStaticAnimMaterial(const char* name, const char* type) const;
		virtual createObjectPtr      getObjectFunction(const char* name, const char* type) const;
	private:
		TextureMaterial m_mtl;
};

#endif
