#include "Units/Unit.h"

Unit::Unit(Updatable* parent, Animation** animation, const Vector2i& casePos, uint32_t playerID, uint32_t cost) : Updatable(parent), Entity(), m_casePos(casePos), m_playerID(playerID), m_cost(cost), m_treePath(NULL), m_anim(animation), m_isMoving(false)
{
	for(uint32_t i=0; i < N_DIRECTION; i++)
	{
		addChild(animation[i]);
		animation[i]->setCanDraw(false);
		animation[i]->setCanUpdate(false);
	}
}

void Unit::onUpdate(Render& render)
{
	if(m_isMoving)
	{
				
	}
}

void Unit::moveToTarget(TreePath* treePath, const Vector2i& targetCase)
{
	m_isMoving    = true;
	m_targetCase  = targetCase;
	m_treePath    = treePath;
}

const Vector2i& Unit::getCasePos() const
{
	return m_casePos;
}

uint32_t Unit::getCost() const
{
	return m_cost;
}

bool Unit::isMoving() const
{
	return m_isMoving;
}

uint32_t Unit::getPlayerID() const
{
	return m_playerID;
}
