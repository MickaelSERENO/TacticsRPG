#ifndef  ATTACKTYPE_INC
#define  ATTACKTYPE_INC

//List of attacks, spells
enum AttackType
{
	ATTACK_SWORD,
	ATTACK_BOW
};

class Attack
{
	public:
		uint32_t m_manaCost;
		uint32_t m_lifeCost;
		uint32_t m_damage;
		uint32_t m_range;
};

extern std::map<AttackType, const Attack> m_attackStats;

#endif
