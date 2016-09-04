#include "Map/PathArrow.h"

PathArrow::PathArrow(Updatable* parent, Material* mtl, const Vector2i& startCase, int cost) : Updatable(parent), m_mtl(mtl), m_startCase(startCase), m_cost(cost), m_arrowTexture(getTexture("arrow.png"))
{
}

PathArrow::~PathArrow()
{
	for(uint32_t i=0; i < m_cases.size(); i++)
		delete m_cases[i];
}

bool PathArrow::addCase(const Vector2i& relPos, int cost)
{
	if(m_currentCost + cost > m_cost)
		return false;
	m_currentCost += cost;
	LOG_ERROR("ADD CASE");
	PathArrowCase* pc = new PathArrowCase(this, m_mtl, m_arrowTexture, m_startCase + relPos);

	//Determine the new orientation
	Orientation newOrientation;

	//Select the good image
	if(m_cases.size() > 0)
	{
		int xDiff = -m_cases[m_cases.size()-1]->getCasePos().x + m_startCase.x + relPos.x;
		int yDiff = -m_cases[m_cases.size()-1]->getCasePos().y + m_startCase.y + relPos.y;

		if(xDiff > 0)
			newOrientation = RIGHT;
		else if(xDiff < 0)
			newOrientation = LEFT;
		else if(yDiff > 0)
			newOrientation = BOTTOM;
		else if(yDiff < 0)
			newOrientation = TOP;

		//Determine the orientation of the movement
		Orientation oldOrientation;
		xDiff = m_cases[m_cases.size()-1]->getCasePos().x - m_cases[m_cases.size()-2]->getCasePos().x;
		yDiff = m_cases[m_cases.size()-1]->getCasePos().y - m_cases[m_cases.size()-2]->getCasePos().y;

		if(xDiff > 0)
			oldOrientation = RIGHT;
		else if(xDiff < 0)
			oldOrientation = LEFT;
		else if(yDiff > 0)
			oldOrientation = BOTTOM;
		else if(yDiff < 0)
			oldOrientation = TOP;

		PathArrowCase* oldPc = m_cases[m_cases.size()-1];
		//Determine the new subrect
		if(newOrientation != oldOrientation)
		{
			LOG_ERROR("TOP %d", TOP);
			LOG_ERROR("ORIENTATION new %d old %d relPos.x %d relPos.y %d", newOrientation, oldOrientation, relPos.x, relPos.y);
			if(newOrientation == TOP && oldOrientation == LEFT)
			{
				oldPc->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(128, 0, 32, 32)));
				oldPc->setRotate(-M_PI/2, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			}

			//It is in good shape already
			else if(newOrientation == TOP && oldOrientation == RIGHT)
			{
				oldPc->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(64, 0, 32, 32)));
				oldPc->setRotate(0, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			}

			else if(newOrientation == BOTTOM && oldOrientation == LEFT)
			{
				oldPc->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(64, 0, 32, 32)));
				oldPc->setRotate(M_PI, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			}

			else if(newOrientation == BOTTOM && oldOrientation == RIGHT)
			{
				oldPc->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(128, 0, 32, 32)));
				oldPc->setRotate(M_PI/2, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			}

			else if(newOrientation == LEFT && oldOrientation == TOP)
			{
				oldPc->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(64, 0, 32, 32)));
				oldPc->setRotate(M_PI/2, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			}

			else if(newOrientation == LEFT && oldOrientation == BOTTOM)
			{
				oldPc->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(128, 0, 32, 32)));
				oldPc->setRotate(0, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			}

			else if(newOrientation == RIGHT && oldOrientation == TOP)
			{
				oldPc->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(128, 0, 32, 32)));
				oldPc->setRotate(-M_PI, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			}

			else if(newOrientation == RIGHT && oldOrientation == BOTTOM)
			{
				oldPc->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(64, 0, 32, 32)));
				oldPc->setRotate(-M_PI/2, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			}
		}

		else
		{
			oldPc->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(32, 0, 32, 32)));
			switch(newOrientation)
			{
				case TOP:
					oldPc->setRotate(M_PI/2, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
					break;

				case BOTTOM:
					oldPc->setRotate(-M_PI/2, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
					break;

				case LEFT:
					oldPc->setRotate(M_PI, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
					break;

				case RIGHT:
					break;
			}
		}
	}

	else
	{
		PathArrowCase* pac = new PathArrowCase(this, m_mtl, m_arrowTexture, m_startCase);
		pac->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(0, 0, 32, 32)));
		pac->setPosition(glm::vec3(-TILE_PER_ROW/2.0 + m_startCase.x, TILE_PER_ROW/2.0*height/width- m_startCase.y - 1, 0));
		m_cases.push_back(pac);

		int xDiff = relPos.x;
		int yDiff = relPos.y;

		if(xDiff > 0)
			newOrientation = RIGHT;
		else if(xDiff < 0)
		{
			pac->setRotate(M_PI, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			newOrientation = LEFT;
		}
		else if(yDiff > 0)
		{
			pac->setRotate(M_PI/2, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			newOrientation = BOTTOM;
		}
		else if(yDiff < 0)
		{
			newOrientation = TOP;
			pac->setRotate(-M_PI/2, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
		}
	}

  	pc->setSubTextureRect(m_arrowTexture->getDirectXRect(Rectangle2ui(96, 0, 32, 32)));
	switch(newOrientation)
	{
		case TOP:
			pc->setRotate(M_PI/2.0, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			break;

		case BOTTOM:
			pc->setRotate(-M_PI/2, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			break;

		case LEFT:
			pc->setRotate(M_PI, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.5, 0.0));
			break;

		case RIGHT:
			break;
	}
	pc->setPosition(glm::vec3(-TILE_PER_ROW/2.0 + m_startCase.x + relPos.x, TILE_PER_ROW/2.0*height/width- m_startCase.y - relPos.y - 1, 0));

	m_cases.push_back(pc);
}

PathArrowCase::PathArrowCase(Updatable* parent, Material* mtl, const Texture* texture, const Vector2i& casePos) : Sprite(parent, mtl, texture), m_casePos(casePos)
{}

const Vector2i& PathArrowCase::getCasePos() const
{
	return m_casePos;
}
