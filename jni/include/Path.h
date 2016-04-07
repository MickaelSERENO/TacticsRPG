#ifndef  PATH_INC
#define  PATH_INC

#include "Graphics/Vector2.h"
#include "Map.h"

struct Path
{
	public:
		uint32_t cost;
		Vector2i caseBefore;
};

class TreePath
{
	public:
		TreePath(uint32_t cost);
		~TreePath();
		void update(const Map& map, const Vector2i& elemPos, const Vector2i& relPos, const Vector2i& beforePos = Vector2i(), uint32_t currentCost=0);
		uint32_t getCost() const;
	private:
		uint32_t m_cost;
		Path** m_paths;
};

void determineTreePath(const Map& map, const Vector2i& elemPos, const Vector2i& relPos, Path** treePath, uint32_t costInit, const Vector2i& beforePos=Vector2i(), uint32_t currentCost=0);

#endif
