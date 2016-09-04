#include "Path.h"

TreePath::TreePath(const Vector2i& unitPos, int cost) : m_unitPos(unitPos), m_cost(cost)
{
	LOG_ERROR("COST %d", cost);
	//Init the m_path
	m_paths = (Path**)malloc(sizeof(Path*)*(2*cost+1));
	for(uint32_t i=0; i <= 2*cost+1; i++)
	{
		m_paths[i] = (Path*)malloc(sizeof(Path)*(2*cost+1));
		for(uint32_t j=0; j <= 2*cost+1; j++)
			m_paths[i][j].cost = -1; 
	}
}

TreePath::TreePath(const TreePath& copy)
{
	*this = copy;
}

TreePath::~TreePath()
{
	//Don't forget to free m_path allocated
	for(uint32_t i=0; i < 2*m_cost+1; i++)
		free(m_paths[i]);
	free(m_paths);
}

void TreePath::generate(GameStats& gs)
{
	recursiveGenerate(gs, Vector2i(m_cost, m_cost));
}

void TreePath::recursiveGenerate(GameStats& gs, const Vector2i& relPos, const Vector2i& beforePos, int currentCost, bool isFirst)
{
	if(!isFirst)
	{
		if(relPos.x + m_unitPos.x - m_cost < 0 || relPos.x + m_unitPos.x - m_cost >= gs.getCurrentMap()->getNbCases().x ||
		   relPos.y + m_unitPos.y - m_cost < 0 || relPos.y + m_unitPos.y  - m_cost>= gs.getCurrentMap()->getNbCases().y || 
		   relPos.x + relPos.y - 2*m_cost < -m_cost||
		   relPos.x + relPos.y - 2*m_cost > m_cost)
			return;

		else if(currentCost >= m_cost)
			return;

		//Increase the currentCost
		Vector2i mapCasesSize = gs.getCurrentMap()->getCasesSize();
		Tile* t = gs.getCurrentMap()->getTileTraceCoords((m_unitPos.x + beforePos.x - m_cost) * mapCasesSize.x, (m_unitPos.y + beforePos.y - m_cost) * mapCasesSize.y);
		if(!t)
			return;
		TileInfo* ti = (TileInfo*)(t->getInfo());
		if(!ti || ti->cost < 0)
			return;

		if(m_paths[relPos.x][relPos.y].cost <= currentCost + ti->cost && m_paths[relPos.x][relPos.y].cost >= 0)
			return;
		else if(gs.getUnit(relPos))
			return;

		currentCost += ti->cost;


		//Then copy the path (new created or not) the to tree
		m_paths[relPos.x][relPos.y].caseBefore = beforePos;
		m_paths[relPos.x][relPos.y].cost = currentCost;
	}

	else
	{
		m_paths[relPos.x][relPos.y].cost       = 0;
		m_paths[relPos.x][relPos.y].caseBefore = relPos;
	}

	//Check on the left
	if(relPos.x > 0)
		recursiveGenerate(gs, Vector2i(relPos.x-1, relPos.y), relPos, currentCost, false);

	//Check on the bottom
	if(relPos.y > 0)
		recursiveGenerate(gs, Vector2i(relPos.x, relPos.y-1), relPos, currentCost, false);

	//Check on the right
	if(relPos.x < 2*m_cost)
		recursiveGenerate(gs, Vector2i(relPos.x+1, relPos.y), relPos, currentCost, false);

	//Check on the top
	if(relPos.y < 2*m_cost)
		recursiveGenerate(gs, Vector2i(relPos.x, relPos.y+1), relPos, currentCost, false);
}

TreePath& TreePath::operator=(const TreePath& copy)
{
	if(this == &copy)
		return *this;

	if(m_paths)
	{
		for(uint32_t i=0; i < 2*m_cost+1; i++)
			free(m_paths[i]);
		free(m_paths);
	}

	m_cost = copy.m_cost;
	m_unitPos = copy.m_unitPos;

	m_paths = (Path**)malloc(sizeof(Path*)*(2*m_cost+1));
	for(uint32_t i=0; i <= 2*m_cost; i++)
	{
		m_paths[i] = (Path*)malloc(sizeof(Path)*(2*m_cost+1));
		for(uint32_t j=0; j <= 2*m_cost; j++)
		{
			m_paths[i][j].cost = copy.m_paths[i][j].cost; 
			m_paths[i][j].caseBefore = copy.m_paths[i][j].caseBefore;
		}
	}

	return *this;
}

int TreePath::getCost() const
{
	return m_cost;
}

const Vector2i& TreePath::getUnitPos() const
{
	return m_unitPos;
}

Path** TreePath::getPaths()
{
	return m_paths;
}
