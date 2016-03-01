#include "Player.h"

Player::Player(Updatable* parent, Map* currentMap)
{}

void Player::moveUnitToTarget(uint32_t id, const Vector2i& relativeTarget)
{
	UnitEntity* unitEntity = m_units[id];
	uint32_t unitCost = unitEntity->unit->getPath();

	//Delete the all path finding tree bound to this Unit
	for(uint32_t i=-unitCost; i <= unitCost; i++)
		free(unitEntity->path[i]);
	free(unitEntity->path);
	unitEntity->path = NULL;

	//Create the new pathFinding tree
	Path** newPath = (Path**)malloc(sizeof(Path*)*unitCost);
	for(uint32_t i=-unitCost; i <= unitCost; i++)
		newPath[i] = (Path*)malloc(sizeof(Path)*unitCost);
	
	determinePathFinding(*m_currentMap, unitEntity->unit->getCase(), newPath, unitCost);
	unitEntity->path = newPath;
}
