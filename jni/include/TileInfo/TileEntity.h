#ifndef  ENTITY_INC
#define  ENTITY_INC

class TileEntity
{
	public:
		TileEntity();
		int getCost() const;
	protected:
		int m_cost;
};

#endif
