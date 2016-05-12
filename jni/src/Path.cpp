#include "Path.h"

TreePath::TreePath(uint32_t cost) : m_cost(cost)
{
	//Init the m_path
	m_path = (Path**)malloc(sizeof(Path*)*(2*cost+1));
	for(uint32_t i=0; i <= 2*cost; i++)
	{
		m_path[i] = (Path*)malloc(sizeof(Path)*(2*cost+1));
		for(uint32_t j=0; j <= 2*cost; j++)
			m_path[i][j].cost = (uint32_t)(-1); //Init all at 2**32 - 1
	}
}

TreePath::~TreePath()
{
	//Don't forget to free m_path allocated
	for(uint32_t i=-m_cost; i <= m_cost; i++)
		free(m_path[i]);
	free(m_path);
}

void TreePath::update(const Map& map, const Vector2i& elemPos, const Vector2i& relPos, const Vector2& beforePos, uint32_t currentCost)
{
	if(currentCost >= m_cost || m_paths[relPos.x][relPos.y].cost <= currentCost)
		return;

	//Increase the currentCost
	/* Need to be completed */

	//Then copy the path (new created or not) the to tree
	m_paths[relPos.x][relPos.y].cost       = currentCost;
	m_paths[relPos.x][relPos.y].caseBefore = beforePos;

	//Check on the left
	if(relPos.x > 0)
	{
		relPos.x--;
		update(map, elemPos, relPos, Vector2i(relPos.x+1, relPos.y), currentCost);
	}

	//Check on the bottom
	if(relPos.y > 0)
	{
		relPos.y--;
		update(map, elemPos, relPos, Vector2i(relPos.x, relPos.y+1), currentCost);
	}

	//Check on the right
	if(relPos.x <= 2*m_cost)
	{
		relPos.x++;
		update(map, elemPos, relPos, Vector2i(relPos.x-1, relPos.y), currentCost);
	}

	//Check on the top
	if(relPos.y <= 2*m_cost)
	{
		relPos.y++;
		update(map, elemPos, relPos, Vector2i(relPos.x, relPos.y-1), currentCost);
	}
}
