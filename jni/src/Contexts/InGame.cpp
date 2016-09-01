#include "Contexts/InGame.h"
#include "Contexts/Game.h"

InGame::InGame(Game* game) : Context(game)
{}

void InGame::onStart(void* data)
{
	if(data != NULL)
	{
		InGame_OnStart* d = (InGame_OnStart*)(data);
		File file(d->mapFile.c_str(), "r");
		m_currentMap = new TMap(this, file);
	}
}

void InGame::onClose()
{
	if(!m_willResumed)
	{
		delete m_currentMap;
		m_currentMap = NULL;
	}
}
