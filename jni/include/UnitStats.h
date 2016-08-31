#ifndef  UNITSTATS_INC
#define  UNITSTATS_INC

#include "sqlite3.h"
#include "stdint.h"
#include "Database.h"
#include <map>
#include <vector>

enum UnitClass
{
	DIVINITY,
	DEVIL,
	HUMAN,
	NEUTRAL,
	DIVIN_BEAST,
	DEMONIAC_BEAST,
	DRAGONS
};

enum UnitType
{
	ABERRATION,
	ARDOR,
	ASIAN_DRAGON,
	BOWMAN,
	CELESTIAL,
	CHARITY,
	CHASTITY,
	CHIMERA,
	COMPASSION,
	DARK_DRAGON,
	DEMONIAC_ANIMAL,
	DEMONIAC_PLANT,
	DIVINE_PLANT,
	ELDER_DRAGON,
	ELEMENTARY,
	ELEMENTARY_DRAGON,
	ENVY,
	FAIRY,
	FIGHT_DRAGON,
	FLYING,
	GARGOYLE,
	GIANT,
	GLUTTONY,
	GOBELIN,
	GOLEM,
	GREED,
	HAMMERMAN,
	HARPY,
	HUMILITY,
	LANCEMAN,
	LUST,
	MAGIC_ANIMAL,
	MAGICIAN,
	MARTIAL,
	METALLIC_DRAGON,
	ORC,
	PARSIMONY,
	PRIDE,
	REPTILIAN,
	SANGUINARY_BEAST,
	SERENITY,
	SLOTH,
	SPECTRUM,
	SPIRIT,
	SWORDMAN,
	UNDEAD,
	UNDEAD_DRAGON,
	WHIPMAN,
	WRATH
};

enum AnimOrientation
{
	LEFT,
	TOP,
	RIGHT,
	BOTTOM
};

struct TypeStats
{
	UnitType unitType;
	int8_t place;
};

struct UnitStats
{
	//Unit database
	UnitType unitType; /* <!The type of the Unit */

	std::string name; /* <!The name of the Unit */
	std::string description; /* <!The description of the Unit */
	std::string modelPath; /* <!The path of the texture of the Unit */

	int      id; /* <! The id of the Unit */
	uint32_t occupation; /* <! The occupation of a building */
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
	uint32_t level; /* <!The level where the Unit is available */
	bool     winged; /*  <!Tell if the unit can fly */
	double   nbTourStat; /* <!Statistics telling how many times the Unit can attack */
	double   nbAttackStat; /* <!Statistics telling how many I can attack per actions */
};

struct UnitDynamicSubAnim
{
	int left;
	int bottom;
	int sizeX;
	int sizeY;
};

struct UnitAnim
{
	int         id;
	int         unitID;
	std::string type;
	std::string name;
};

struct UnitStaticAnim : public UnitAnim
{
	AnimOrientation orientation;
	int x;
	int y;
	int sizeX;
	int sizeY;
	int padX;
	int padY;
	int n;
	int nX;
};

struct UnitDynamicAnim : public UnitAnim
{
	std::vector<UnitDynamicSubAnim> subAnim;
}

class UnitTree
{
	public:
		UnitTree(UnitClass uc);
		std::vector<const UnitStats*> getChildren(const std::string& name) const;
		std::vector<const UnitStats*> getChildren(int id) const;
	private:
		UnitClass m_uc;
		std::map<UnitType, std::vector<UnitStats>> m_data;
		std::map<int, std::vector<int>> m_childTree;
};

struct ClassDataCallback
{
	std::map<UnitType, std::vector<UnitStats>> data;
	UnitClass uc;
	Database* db;
};

/** \brief Class which provides functions to access some part of the Data
  * \class UnitDatabase*/
class UnitDatabase
{
	public:
		/** \brief init the singleton
		 * \param db The Database to use*/
		static void initSingleton(Database* db);

		/** \brief get the singleton
		 * \return The UnitDatabase*/
		static UnitDatabase* getSingleton();

		//Mapping functions

		/** \brief get the string for an UnitClass
		 * \return the string associated with the UnitClass*/
		static std::string getClassName(UnitClass uc);

		/** \brief convert a UnitType to a std::string
		 * \return the string associated with the UnitType*/
		static std::string getUnitTypeString(UnitType ut);

		/** \brief convert a std::string to a UnitType
		 * \return the UnitType associated with the std::string*/
		static UnitType getUnitType(const std::string& ut);

		//Callback functions

		static int getUnitDataCallback(void* data, int nbColumn, char** argv, char** columnName);

		static int getClassDatabaseCallback(void* data, int nbColumn, char** argv, char** columnName);

		static int getChildrenCallback(void* data, int nbColumn, char** argv, char** columnName);

		/** \brief get the information of a whole UnitClass.
		 * \param uc The UnitClass
		 * \return an array of all the UnitStats of this UnitClass mapped by UnitType.*/
		std::map<UnitType, std::vector<UnitStats>> getClassDatabase(UnitClass uc);

		/** \brief get the id of the children of one unit represented by its id
		 * \param id The id of the Unit parent
		 * \return An array of the children of this Unit*/
		std::vector<int> getChildrenID(int id);
	private:
		static UnitDatabase* m_singleton;
		UnitDatabase(Database* db);
		~UnitDatabase();
		Database* m_db;
};

#endif
