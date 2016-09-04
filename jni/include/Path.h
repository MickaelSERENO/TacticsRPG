#ifndef  PATH_INC
#define  PATH_INC

#include "Graphics/Vector2.h"
#include "GameStats.h"

struct Path
{
	public:
		int32_t cost;
		Vector2i caseBefore;
};

class TreePath
{
	public:
		TreePath(const Vector2i& unitPos, int cost);
		TreePath(const TreePath& copy);
		TreePath& operator=(const TreePath& copy);
		~TreePath();

		void generate(GameStats& gs);
		int getCost() const;
		Path** getPaths();
		const Vector2i& getUnitPos() const;
	private:
		void recursiveGenerate(GameStats& gs, const Vector2i& relPos, const Vector2i& beforePos = Vector2i(), int currentCost=0, bool isFirst=true);
		Vector2i m_unitPos;
		int m_cost;
		Path** m_paths=NULL;
};


#endif
