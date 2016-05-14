#ifndef  PLAYERTRACE_INC
#define  PLAYERTRACE_INC

#include "Map/Traces/Trace.h"

class PlayerTrace : public Trace
{
	public:
		PlayerTrace(Updatable* parent, uint32_t nbCasesX, uint32_t nbCasesY, uint32_t sizeX, uint32_t sizeY);
	private:
		uint32_t m_nbCasesX, m_nbCasesY, m_sizeX, m_sizeY;
};

#endif
