#ifndef  TMAP_INC
#define  TMAP_INC

#include "Map/Map.h"
#include "Map/Tiles/TTile.h"
#include "Map/TileFactory.h"
#include "Map/Tiles/DefaultTile.h"
//#include "Map/Traces/PlayerTrace.h"
#include "Materials/TextureMaterial.h"
#include <map>

class TMap : public Map
{
	public:
		TMap(Updatable* parent, File& file);
		~TMap();
		virtual createStaticTilePtr  getStaticTileFunction(const char* name, const char* type)const; 
		virtual Material*            getStaticTileMaterial(const char* name, const char* type);
		virtual void*                getStaticTileInfo(const char* name, const char* type);
		virtual createDynamicAnimPtr getDynamicAnimFunction(const char* name) const; 
		virtual Material*            getDynamicAnimMaterial(const char* name);
		virtual createStaticAnimPtr  getStaticAnimFunction(const char* name) const; 
		virtual Material*            getStaticAnimMaterial(const char* name);
		virtual createObjectPtr      getObjectFunction(const char* name, const char* type) const;
	private:
		TextureMaterial m_mtl;
		std::map<std::string, TileInfo*> m_tileInfo;
//		PlayerTrace* m_playerTrace;
};

#endif
