#ifndef  PLAYER_INC
#define  PLAYER_INC

#include "Units/Unit.h"
#include "Updatable.h"
#include "Graphics/Vector2.h"

class Player : public Updatable
{
	public:
		Player(Updatable* parent, UnitClass uc, uint32_t id);
		~Player();
		void onUpdate(Render& render);
		void addUnit(const UnitStats* us, const Vector2i& pos, Orientation defaultDirection);
		UnitTree& getUnitTree();
		std::vector<Unit*> m_units;
	private:
		uint32_t m_lastUnitMoved;
		UnitClass m_uc;
		UnitTree m_ut;
		uint32_t m_id;
};

#endif
