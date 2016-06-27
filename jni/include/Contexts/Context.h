#ifndef  CONTEXT_INC
#define  CONTEXT_INC

enum ContextID
{
	Start, InGame
};

class Game;

class Context
{
	public:
		Context(Game* game);
		virtual void run() = 0;
	private:
		Game* m_game;
};

#endif
