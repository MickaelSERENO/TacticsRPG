#ifndef  CONTEXT_INC
#define  CONTEXT_INC

#include "Updatable.h"

enum ContextID
{
	START, IN_GAME
};

class Game;

class Context : public Updatable
{
	public:
		Context(Game* game);
		virtual void onStart(void* data=NULL);
		virtual void onClose();
	protected:
		bool m_willResumed=false;
		Game* m_game;
};

#endif
