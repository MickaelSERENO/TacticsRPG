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
		m_map = new Map(this);
		m_map.parse(file);
	}
}

void InGame::onClose()
{
	if(!m_resume)
	{
		delete m_map;
		m_map = NULL;
	}
}
