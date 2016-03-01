#ifndef  UNITENTITY_INC
#define  UNITENTITY_INC

#include "Units/Unit.h"
#include "Path.h"

struct UnitEntity
{
	Unit* unit;
	Path** path;
};

#endif
