#ifndef  UNIT_INC
#define  UNIT_INC

#include "Updatable.h"
#include "Graphics/Vector2.h"
#include "Path.h"
#include "Direction.h"
#include "Entity.h"

#define N_DIRECTION  4

#define ANIM_NOTHING 0
#define ANIM_MOVING  1

class Unit : public Updatable, Entity
{
	public:
		Unit(Updatable* parent, uint32_t casePos, uint32_t playerID, uint32_t cost);
		void loadStaticAnim(Animation** anim);
		void loadMoveAnim(Animation** anim);
		void onUpdate(Render& render);
		void onDraw(Render& render, const glm::mat4& mvp=glm::mat4(1.0f));
		void attack(Unit& ennemy);
		void moveToTarget(TreePath* treePath);
		const Vector2i& getCasePos() const;
		uint32_t        getCost() const;
		bool            isMoving() const;
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
