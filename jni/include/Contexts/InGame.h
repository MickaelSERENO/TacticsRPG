#ifndef  INGAME__INC
#define  INGAME__INC

#include "Contexts/Context.h"
#include "Map/TMap.h"
#include "GameStats.h"
#include "Contexts/SharedData.h"
#include "Path.h"
#include "Map/TreePathUpdatable.h"
#include "Map/PathArrow.h"
#include <jni.h>

class InGame : public Context
{
	public:
		InGame(Game* game);
		~InGame();
		void onStart(void* data=NULL);
		void onClose();
		void update(Render& render);
	private:
		bool m_hasStart=false;
		InGame_OnStart* m_data=NULL;
		TMap* m_currentMap=NULL;
		GameStats m_gameStats;
		Player* m_player=NULL;
		TextureMaterial m_textureMtl;
};

#endif
