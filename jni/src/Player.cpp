#include "Player.h"

Player::Player(Updatable* parent, UnitClass uc, uint32_t id) : Updatable(parent), m_uc(uc), m_ut(uc), m_id(id)
{
	
}

void Player::onUpdate(Render& render)
{
//	m_ut.getFirstParents();
}

Player::~Player()
{
	for(Unit* u : m_units)
		delete u;
}

void Player::addUnit(const UnitStats* us, const Vector2i& pos, Orientation defaultDirection)
{
	m_units.push_back(new Unit(this, pos, m_id, us));
}

UnitTree& Player::getUnitTree()
{
	return m_ut;
}
