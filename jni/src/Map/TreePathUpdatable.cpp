#include "Map/TreePathUpdatable.h"

TreePathUpdatable::TreePathUpdatable(Updatable* parent, TreePath* tp) : Updatable(parent), m_treePath(tp)
{
	Texture* texture = getTexture("pathCase.png");
	m_mtl.setOpacity(0.6f);
	Path** paths = tp->getPaths();
	int cost = tp->getCost();

	for(int i=0; i < 2*cost+1; i++)
		for(int j=0; j < 2*cost+1; j++)
		{
			if(paths[i][j].cost == -1)
			{
				LOG_ERROR("CONTINUE U_U");
				continue;
			}

			PathCase* pc = new PathCase(this, &m_mtl, texture, Vector2i(i, j));
			m_pathCases.push_back(pc);
			pc->setFocusCallback(TreePathUpdatable::caseUpdatable, (void*)this);
			pc->setPosition(glm::vec3(-TILE_PER_ROW/2.0f + tp->getUnitPos().x + i - cost,
			    				      (TILE_PER_ROW/2.0f*height/width) - tp->getUnitPos().y -j +cost -1, 1.0f));
		}
}

void TreePathUpdatable::caseUpdatable(Updatable* obj, void* data)
{
	PathCase* pc = (PathCase*)obj;
	TreePathUpdatable* self = (TreePathUpdatable*)(data);
}

PathCase::PathCase(Updatable* parent, Material* mtl, const Texture* texture, const Vector2i& relPos) : Sprite(parent, mtl, texture), m_relPos(relPos)
{}
