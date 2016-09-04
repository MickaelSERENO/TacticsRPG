#ifndef  UNIT_INC
#define  UNIT_INC

#include "Updatable.h"
#include "Graphics/Vector2.h"
#include "UnitStats.h"
#include "GameResources.h"
#include "Graphics/Materials/TextureMaterial.h"

#define ANIM_NOTHING 0
#define ANIM_MOVING  1

enum AttackType
{
	SWORD,
};

class Unit : public Updatable
{
	public:
		Unit(Updatable* parent, const Vector2i& casePos, uint32_t playerID, const UnitStats* us);

		void onUpdate(Render& render);

		/** \brief Attack an unity enemy
		 * \param The enemy to attack*/
		void attack(Unit& enemy, AttackType type);

		/** \brief return the case position of the unit
		 *  \return the position of the unit*/
		const Vector2i& getCasePos() const;

		/** \brief is the unit moving ?
		 * \return the unit is moving*/
		bool isAnimated() const;

		/** \brief get the player which the unit is owned
		 * \return the player ID*/
		uint32_t getPlayerID() const;

		const UnitStats* getUnitStats() const;

		static void animationCallback(Updatable* anim, void* data);
		static Unit* currentSelected;
	protected:
		Animation*  m_animation; /* <!The animation of the Unit */
		TextureMaterial   m_animMaterial; /* <!The Material of all animation */
		Vector2i    m_casePos; /* <!Player position in the map */
		uint32_t    m_playerID;/* <!The player ID. The ID match to the player, identity, not the Unit identity */
		Vector2i    m_targetCase; /* <!The case the unit is going */
		uint32_t    m_currentAction=ANIM_NOTHING; /* <!The current animation playing*/
		bool        m_endAnimation=true; /* <!Is the current animation ended ? */
		uint32_t    m_currentLevel=0; /* <!The current level of the Unit */
		uint32_t    m_pv; /* <!The current pv of the Unit */
		uint32_t    m_mp; /* <!The current mp of the Unit */

		int coucou=56;
		const UnitStats*  m_unitStats; /* <!The unit statistic */

		//Unit attack
		std::vector<AttackType> m_unlockAttack; /* <!Attack actually unlocked */
};

#endif
