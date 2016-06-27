#ifndef  GAME_INC
#define  GAME_INC

#include "Updatable.h"
#include "Contexts/Start.h"

class Game : public Updatable
{
	public:
		Game(Updatable* parent);
	private:
		Start m_start;
};

#endif
