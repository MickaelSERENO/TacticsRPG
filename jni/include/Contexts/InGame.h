#ifndef  INGAME__INC
#define  INGAME__INC

#include "Contexts/Context.h"

class InGame : public Context
{
	public:
		InGame(Game* game);
		void onStart(void* data=NULL);
		void onClose();
	private:
		Map* m_currentMap;
};

#endif
