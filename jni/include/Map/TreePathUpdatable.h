#ifndef  TREEPATHUPDATABLE_INC
#define  TREEPATHUPDATABLE_INC

#include "Path.h"
#include "Updatable.h"
#include "GameResources.h"
#include "GameStats.h"
#include "Sprite.h"
#include "GameResources.h"

class PathCase : public Sprite
{
	public:
		PathCase(Updatable* parent, Material* mtl, const Texture* texture, const Vector2i& relPos);
		const Vector2i& getRelPos() const;
	private:
		Vector2i m_relPos;
};

class TreePathUpdatable : public Updatable
{
	public:
		TreePathUpdatable(Updatable* parent, TreePath* tp);
		static void caseUpdatable(Updatable* pathCase, void* data);
	private:
		TextureMaterial        m_mtl;
		TreePath*              m_treePath;
		std::vector<PathCase*> m_pathCases;
		Vector2i			   m_pathSelected;
		bool                   m_hasSelection=false;
};

#endif
