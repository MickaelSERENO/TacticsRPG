#ifndef  UNIT_INC
#define  UNIT_INC

#include "Updatable.h"
#include "Graphics/Vector2.h"
#include "Path.h"
#include "Direction.h"
#include "Entity.h"

#define N_DIRECTION 4

class Unit : public Updatable, Entity
{
	public:
		Unit(Updatable* parent, Animation** animations, uint32_t casePos, uint32_t playerID);
		void onUpdate(Render& render);
		void onDraw(Render& render, const glm::mat4& mvp=glm::mat4(1.0f));
		void moveToTarget(Path** pathFinding);
		const Vector2i& getCasePos();
		uint32_t        getCost();
		bool            isMoving();
	protected:
		Vector2i    m_casePos;
		uint32_t    m_playerID;
		uint32_t    m_cost;
		Path*       m_pathFinding;
		uint32_t    m_currentCase;
		Animation** m_anim;
		bool        m_isMoving;
};

#endif
