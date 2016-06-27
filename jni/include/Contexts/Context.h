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
	private:
		Game* m_game;
};

#endif
