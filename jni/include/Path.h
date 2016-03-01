#ifndef  PATH_INC
#define  PATH_INC

#include "Graphics/Vector2.h"

struct Path
{
	public:
		uint32_t cost;
		std::vector<Vector2i> path;
};

void determinePathFinding(const Map& map, const Vector2i& pos, Path** pathFinding, uint32_t costInit, uint32_t currentCost=0);

#endif
