#include "GameStats.h"
#include "Path.h"

GameStats::GameStats() : m_currentPlayer(0)
{}

GameStats::~GameStats()
{
	if(m_currentUnitTreePath)
		delete m_currentUnitTreePath;
}

void GameStats::addPlayer(Player* p)
{
	m_players.push_back(p);
}

Player* GameStats::getPlayer(uint32_t id)
{
	return (id < m_players.size()) ? m_players[id] : NULL;
}

uint32_t GameStats::getNbPlayers() const
{
	return m_players.size();
}

void GameStats::clear()
{
	m_players.clear();
	m_units.clear();
}

void GameStats::setCurrentMap(TMap* map)
{
	m_currentMap = map;
}

TMap* GameStats::getCurrentMap()
{
	return m_currentMap;
}

/* ****************** UNIT FUNCTIONS ********************* */

void GameStats::initUnitTrace(const Vector2i& mapSize)
{
	m_units.clear();
	for(int i=0; i < mapSize.x; i++)
	{
		m_units.push_back(std::vector<Unit*>());
		for(int j=0; j < mapSize.y; j++)
			m_units[i].push_back(NULL);
	}
}

void GameStats::recordUnit(Unit* u)
{
	m_units[u->getCasePos().x][u->getCasePos().y] = u;
}

void GameStats::moveUnit(const Vector2i& caseBefore, const Vector2i& caseAfter)
{
	m_units[caseAfter.x][caseAfter.y]   = m_units[caseBefore.x][caseBefore.y];
	m_units[caseBefore.x][caseBefore.y] = NULL;
}

Unit* GameStats::getUnit(const Vector2i& pos)
{
	return m_units[pos.x][pos.y];
}

void GameStats::unitSelected(Unit* unit)
{
	m_currentUnitSelected = unit;
	if(m_currentUnitTreePath)
		delete m_currentUnitTreePath;
	m_currentUnitTreePath = new TreePath(unit->getCasePos(), unit->getUnitStats()->movableCost);
	m_currentUnitTreePath->generate(*this);
}

void GameStats::deselectUnit()
{
	if(m_currentUnitTreePath)
	{
		delete m_currentUnitTreePath;
		m_currentUnitTreePath = NULL;
	}
	m_currentUnitSelected = NULL;
}

TreePath* GameStats::getCurrentTreePath()
{
	return m_currentUnitTreePath;
}
