#ifndef  PATHARRAY_INC
#define  PATHARRAY_INC

#include "Graphics/Sprite.h"
#include "Vector2.h"
#include "GameResources.h"
#include "Orientation.h"
#include <cmath>

class PathArrowCase : public Sprite
{
	public:
		PathArrowCase(Updatable* parent, Material* mtl, const Texture* texture, const Vector2i& casePos);
		const Vector2i& getCasePos() const;
	private:
		Vector2i m_casePos;
};

class PathArrow : public Updatable
{
	public:
		PathArrow(Updatable* parent, Material* mtl, const Vector2i& startCase, int cost);
		~PathArrow();

		bool addCase(const Vector2i& relPos, int cost);
		void removeLastCase();
	private:
		Material* m_mtl;
		glm::vec2 m_offset;
		Vector2i m_startCase;
		int m_cost;
		std::vector<PathArrowCase*> m_cases;
		int m_currentCost=0;
		Texture* m_arrowTexture;
};

#endif
