#include "Player.h"

Player::Player(Updatable* parent, Map* currentMap)
{}

void Player::addUnit(Unit* unit, const Vector2i& pos, Direction defaultDirection)
{
	UnitEntity* entity = new UnitEntity();
	entity->unit       = unit;
	entity->treePath   = new TreePath(unit->getCost());
	entity->treePath->update(*m_currentMap, pos, Vector2i(unitCost, unitCost));
	m_units.push_back(entity);
}

void Player::moveUnitToTarget(uint32_t id, const Vector2i& relativeTarget)
{
	UnitEntity* unitEntity = m_units[id];
	uint32_t unitCost = unitEntity->unit->getPath();

	//Update the TreePath
	unitEntity->treePath->update(*m_currentMap, unitEntity->unit->getCase(), Vector2i(unitCost, unitCost));
}
