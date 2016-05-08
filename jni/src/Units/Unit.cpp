#include "Units/Unit.h"

Unit::Unit(Updatable* parent, const Vector2i& casePos, uint32_t playerID, uint32_t cost) : Updatable(parent), Entity(), m_casePos(casePos), m_playerID(playerID), m_movableCost(cost), m_treePath(NULL), m_staticAnim(NULL), m_moveAnim(NULL), m_currentAction(ANIM_MOVING)
{
}

void Unit::loadMoveAnim(Animation** anim)
{
	//Add the forth basic animation in movements
	for(uint32_t i=0; i < N_DIRECTION; i++)
	{
		m_moveAnim[i] = anim[i];
		if(animation[i])
		{
			addChild(animation[i]);
			animation[i]->setCanDraw(false);
			animation[i]->setCanUpdate(false);
		}
	}
}

void Unit::loadStaticAnim(Anim** anim)
{
	//Add the forth basic animation in movements
	for(uint32_t i=0; i < N_DIRECTION; i++)
	{
		m_staticAnim[i] = anim;
		if(anim[i])
		{
			addChild(anim[i]);
			anim[i]->setCanDraw(false);
			anim[i]->setCanUpdate(false);
		}
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
	m_currentAction = ANIM_MOVING;
	m_targetCase  = targetCase;
	m_treePath    = treePath;
}

const Vector2i& Unit::getCasePos() const
{
	return m_casePos;
}

uint32_t Unit::getMovable() const
{
	return m_movableCost;
}

bool Unit::isMoving() const
{
	return m_isMoving;
}

uint32_t Unit::getPlayerID() const
{
	return m_playerID;
}
