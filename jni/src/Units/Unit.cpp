#include "Units/Unit.h"

Unit::Unit(Updatable* parent, Animation* animation, const Vector2i& casePos, uint32_t playerID) : m_casePos(casePos), m_playerID(playerID), m_anim(animation)
{}

void Unit::onUpdate(Render& render)
{
	if(m_isMoving)
	{
		
	}
}

void Unit::onDraw(Render& render, const glm::mat4& mvp)
{
	m_anim->onDraw(render, mvp);
}

void Unit::moveToTarget(Path* pathFinding)
{
	m_isMoving    = true;
	m_pathFinding = pathFinding;
}

const Vector2i& Unit::getCasePos()
{
	return m_casePos;
}

uint32_t Unit::getCost()
{
	return m_cost;
}

bool Unit::isMoving()
{
	return m_isMoving;
}
