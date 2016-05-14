#ifndef  UNITSTATS_INC
#define  UNITSTATS_INC

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

};

class UnitStats
{
	public:
		//Unit database
		UnitType m_unitType; /* <!The type of the Unit */
		uint32_t m_goldCost; /* <! How many gold it costs */
		uint32_t m_life; /* <!How many life has the Unit*/
		uint32_t m_mana; /* <!How many mana has the Unit */
		uint32_t m_defense; /* <!The defense of the Unit */
		uint32_t m_speDefense; /* <!The special defense of the Unit */
		uint32_t m_attack; /* <!The attack of the Unit */
		uint32_t m_speAttack; /* <!The special attack of the Unit */
		uint32_t m_movableCost; /* <!How many cases I can cross (weighted by the Tile cost) */
		uint32_t m_accuracy; /* <!The accuracy of the Unit */
		uint32_t m_visibility; /* <!The visibility in the fog of the Unit */
		double   m_nbTourStat; /* <!Statistics telling how many times the Unit can attack */
		double   m_nbAttackStat; /* <!Statistics telling how many I can attack per actions */
};

extern std::map<UnitType, const UnitStats> m_unitStats;

#endif
