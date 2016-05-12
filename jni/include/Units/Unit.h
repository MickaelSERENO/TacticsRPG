#ifndef  UNIT_INC
#define  UNIT_INC

#include "Updatable.h"
#include "Graphics/Vector2.h"
#include "Path.h"
#include "Direction.h"
#include "TileInfo/UnitEntity.h"
#include "Tile.h"

#define N_DIRECTION  4

#define ANIM_NOTHING 0
#define ANIM_MOVING  1

class Unit : public UnitEntity, Tile
{
	public:
		Unit(Updatable* parent, uint32_t casePos, uint32_t playerID, uint32_t cost);

		/** \brief Load the animations while the unit still remain
		 * \param anim the array of the Animation (4 animations because of 4 Directions)*/
		void loadStaticAnim(Animation** anim);

		/** \brief Load the animations while the unit is moving
		 * \param anim the array of the Animation (4 animations because of 4 Directions)*/
		void loadMoveAnim(Animation** anim);
		void onUpdate(Render& render);
		void onDraw(Render& render, const glm::mat4& mvp=glm::mat4(1.0f));

		/** \brief Attack an unity enemy
		 * \param The enemy to attack*/
		void attack(Unit& enemy);

		/** \brief Move the unit to a target
		 * \param treePath the TreePath which represent to world around the unit.*/
		void moveToTarget(TreePath* treePath);

		/** \brief return the case position of the unit
		 *  \return the position of the unit*/
		const Vector2i& getCasePos() const;

		/** \brief return the capacity of the unit to move
		 * \return the capacity to move*/
		uint32_t        getMovingCapacity() const;

		/** \brief is the unit moving ?
		 * \return the unit is moving*/
		bool            isMoving() const;

		/** \brief get the player which the unit is owned
		 * \return the player ID*/
		uint32_t        getPlayerID() const;
	protected:
		Vector2i    m_casePos; /* <!Player position in the map */
		uint32_t    m_playerID;/* <!The player ID. The ID match to the player, identity, not the Unit identity */
		uint32_t    m_movableCost; /* <!How many cases I can cross (weighted by the Tile cost) */
		TreePath*   m_treePath; /* <!The current TreePath for the motion */
		Vector2i    m_targetCase; /* <!The case the unit is going */
		Animation*  m_staticAnim[4]; /* <!The animation while the player is static (4 Animation because 4 directions) */
		Animation*  m_moveAnim[4];/* <!The animation while the player is moving (4 Animation because 4 directions) */
		uint32_t    m_currentAction; /* <!The current animation playing*/
		bool        m_endAnimation; /* <!Is the current animation ended ? */
};

#endif
