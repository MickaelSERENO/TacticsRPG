#ifndef  GAME_INC
#define  GAME_INC

#include "Updatable.h"
#include "Contexts/Start.h"
#include "Contexts/InGame.h"

class Game : public Updatable
{
	public:
		Game(Updatable* parent);
		void changeContext(ContextID ce, void* data=NULL);
	private:
		InGame m_inGame;
		Start m_start;
		Context* m_currentContext=NULL;
};

#endif
