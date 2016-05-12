#include "TileInfo/TileEntity.h"

TileEntity::TileEntity() : m_cost(1)
{}

int TileEntity::getCost()
{
	return m_cost;
}
