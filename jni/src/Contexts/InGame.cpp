#include "Contexts/InGame.h"
#include "Contexts/Game.h"

InGame::InGame(Game* game) : Context(game)
{}

InGame::~InGame()
{
	if(m_currentMap)
		delete m_currentMap;
	if(m_player)
		delete m_player;
}

void InGame::update(Render& render)
{
	if(m_hasStart)
	{
		render.getCamera().setScale(glm::vec3(2.0f/TILE_PER_ROW, 2.0f/TILE_PER_ROW*(float)width/(float)height, 1.0));
		m_hasStart = false;
		m_gameStats.clear();
		if(m_data != NULL)
		{
			if(m_currentMap)
				delete m_currentMap;
			  
			InGame_OnStart* d = (InGame_OnStart*)(m_data);
			File file(JniMadeOf::getJEnv(), JniMadeOf::context, d->mapFile.c_str(), "r");

			m_currentMap = new TMap(this, file);
			Rectangle3f defaultConf = m_currentMap->getDefaultConf();
			m_currentMap->setScale(glm::vec3(1/32.0, 1/32.0, 1.0));
			m_currentMap->setPosition(glm::vec3(-TILE_PER_ROW/2.0f, TILE_PER_ROW/2.0f*height/(float)width-defaultConf.height/32.0f, 0.0f));

			m_gameStats.setCurrentMap(m_currentMap);
			m_gameStats.initUnitTrace(m_currentMap->getNbCases());
			delete m_data;
			m_data = NULL;

			if(m_player)
				delete m_player;
			m_player = new Player(this, HUMAN, 0);
			m_gameStats.addPlayer(m_player);

			m_player->addUnit(m_player->getUnitTree().getFirstParents()[0], Vector2i(3, 3), BOTTOM);
			m_player->addUnit(m_player->getUnitTree().getFirstParents()[0], Vector2i(3, 4), BOTTOM);
			m_player->addUnit(m_player->getUnitTree().getFirstParents()[0], Vector2i(4, 3), BOTTOM);
			m_player->addUnit(m_player->getUnitTree().getFirstParents()[0], Vector2i(5, 3), BOTTOM);

			PathArrow* pa = new PathArrow(this, &m_textureMtl, Vector2i(3, 3), 3);
			pa->addCase(Vector2i(1, 0), 1);
			pa->addCase(Vector2i(2, 0), 1);
			pa->addCase(Vector2i(2, 1), 0);
			pa->addCase(Vector2i(1, 1), 0);
		}

		std::vector<glm::vec3> v;
		v.push_back(glm::vec3(-10, 10, 0));
		v.push_back(glm::vec3(10, -10, 0));
	}

	if(Unit::currentSelected != NULL)
	{
		m_gameStats.unitSelected(Unit::currentSelected);
		Unit::currentSelected = NULL;
		TreePathUpdatable* tpu = new TreePathUpdatable(this, m_gameStats.getCurrentTreePath());
	}
	Updatable::update(render);
}

void InGame::onStart(void* data)
{
	m_hasStart = true;
	m_data = (InGame_OnStart*)data;
}

void InGame::onClose()
{
	if(!m_willResumed)
	{
		delete m_currentMap;
		m_currentMap = NULL;
		delete m_player;
		m_player = NULL;
		m_gameStats.clear();
	}
}
