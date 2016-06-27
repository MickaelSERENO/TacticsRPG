#include "UnitStats.h"

UnitDatabase::UnitDatabase()
{}

UnitDatabase::~UnitDatabase()
{}

void UnitDatabase::init(const char* path)
{

}

const std::map<UnitType, const UnitStats>& UnitDatabase::getUnitStats()
{
	return m_unitStats;
}

UnitDatabase& UnitDatabase::getSingleton()
{
	return UnitDatabase::m_singleton;
}
