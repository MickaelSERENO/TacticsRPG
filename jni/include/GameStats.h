#ifndef  GAMESTATS_INC
#define  GAMESTATS_INC

#include "Player.h"
#include "Map/TMap.h"

class TreePath;

class GameStats
{
	public:
		GameStats();
		~GameStats();
		void addPlayer(Player* player);
		Player* getPlayer(uint32_t id);
		uint32_t getNbPlayers() const;
		void clear();

		void initUnitTrace(const Vector2i& mapSize);
		void recordUnit(Unit* u);
		void moveUnit(const Vector2i& caseBefore, const Vector2i& caseAfter);
		Unit* getUnit(const Vector2i& pos);
		void deselectUnit();
		void unitSelected(Unit* unit);
		TreePath* getCurrentTreePath();

		void setCurrentMap(TMap* map);
		TMap* getCurrentMap();
	private:
		std::vector<Player*> m_players;
		std::vector<std::vector<Unit*>> m_units;
		uint32_t m_currentPlayer;
		TMap* m_currentMap              = NULL;
		Unit* m_currentUnitSelected     = NULL;
		TreePath* m_currentUnitTreePath = NULL;
};

#endif
