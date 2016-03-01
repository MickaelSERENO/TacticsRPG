#ifndef  PLAYER_INC
#define  PLAYER_INC

#include "UnitEntity.h"
#include "Updatable.h"
#include "Graphics/Vector2.h"

class Player : public Updatable
{
	public:
		Player(Updatable* parent);
		void addUnit(const Vector2i& pos, Direction defaultDirection);
		void moveUnitToTarget(uint32_t id, const Vector2i& relativeTarget);
	private:
		std::vector<UnitEntity*> m_units;
		uint32_t m_lastUnitMoved;
};

#endif
