#include "Units/Unit.h"

Unit* Unit::currentSelected = NULL;

Unit::Unit(Updatable* parent, const Vector2i& casePos, uint32_t playerID, const UnitStats* us) : Updatable(parent), m_casePos(casePos), m_playerID(playerID), m_targetCase(-1, -1), m_pv(us->life), m_mp(us->mana), m_unitStats(us)
{
	UnitAnim* ua  = UnitDatabase::getSingleton()->getAnimationDatas(us->id, "REMAIN");
	m_animation   = ua->createAnim(this, &m_animMaterial, getTexture(ua->getModelPath()), 2, BOTTOM);

	m_animation->rotate(1.57f, glm::vec3(0, 0, -1), glm::vec3(0.5f, 0.5f, 0.0), true);
	m_animation->setPosition(glm::vec3(-TILE_PER_ROW/2.0f + casePos.x,
									   (TILE_PER_ROW/2.0f*height/width) - casePos.y-1, 1.0f));
	m_animation->setFocusCallback(Unit::animationCallback, this);
}

void Unit::onUpdate(Render& render)
{
	if(!m_endAnimation)
	{
				
	}
}

void Unit::attack(Unit& enemy, AttackType type)
{}

const Vector2i& Unit::getCasePos() const
{
	return m_casePos;
}

bool Unit::isAnimated() const
{
	return m_endAnimation;
}

uint32_t Unit::getPlayerID() const
{
	return m_playerID;
}

const UnitStats* Unit::getUnitStats() const
{
	return m_unitStats;
}

void Unit::animationCallback(Updatable* anim, void* data)
{
	Unit* self = (Unit*)data;
	LOG_ERROR("ANIMATION CALLBACK %d", self->m_unitStats->movableCost);
	Unit::currentSelected = (Unit*)data;
}
