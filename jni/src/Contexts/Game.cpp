#include "Contexts/Game.h"

Game::Game(Updatable* parent) : Updatable(parent), m_inGame(this), m_start(this)
{
	m_inGame.setParent(NULL);
	m_currentContext = &m_start;
}

void Game::changeContext(ContextID ce, void* data)
{
	m_currentContext->onClose();
	m_currentContext->setParent(NULL);
	switch(ce)
	{
		case START:
			m_currentContext = &m_start;
			break;

		case IN_GAME:
			m_currentContext = &m_inGame;
			break;
	}
	m_currentContext->setParent(this);
	m_currentContext->onStart(data);
}
