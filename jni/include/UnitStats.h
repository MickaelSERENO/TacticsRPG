#ifndef  UNITSTATS_INC
#define  UNITSTATS_INC

#include "sqlite3.h"

enum UnitClass
{
	DIVINITY,
	EVIL,
	HUMAN,
	MECA,
	DIVIN_BEAST,
	EVIL_BEAST,
	DRAGONS
};

enum UnitType
{
	SOLDIER
};

class UnitStats
{
	public:
		//Unit database
		UnitType unitType; /* <!The type of the Unit */
		uint32_t occupation; /* The occupation of a building */
		uint32_t goldCost; /* <! How many gold it costs */
		uint32_t life; /* <!How many life has the Unit*/
		uint32_t mana; /* <!How many mana has the Unit */
		uint32_t defense; /* <!The defense of the Unit */
		uint32_t speDefense; /* <!The special defense of the Unit */
		uint32_t attack; /* <!The attack of the Unit */
		uint32_t speAttack; /* <!The special attack of the Unit */
		uint32_t movableCost; /* <!How many cases I can cross (weighted by the Tile cost) */
		uint32_t accuracy; /* <!The accuracy of the Unit */
		uint32_t visibility; /* <!The visibility in the fog of the Unit */
		double   nbTourStat; /* <!Statistics telling how many times the Unit can attack */
		double   nbAttackStat; /* <!Statistics telling how many I can attack per actions */
};

class UnitDatabase
{
	public:
		static const UnitDatabase& getSingleton();
		void init(const char* path);
		const std::map<UnitType, const UnitStats>& getUnitStats();
	private:
		UnitDatabase();
		~UnitDatabase();
		static UnitDatabase m_singleton;
		std::map<UnitType, const UnitStats> m_unitStats;
};

#endif
