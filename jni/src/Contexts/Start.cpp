#include "Contexts/Start.h"
#include "Contexts/Game.h"

Start::Start(Game* game) : Context(game), m_menuBackgroundMaterial(Color::BLUE), m_menuBackground(NULL, &m_menuBackgroundMaterial), m_menu(this, NULL, glm::vec3(-0.5f, 0.5f, 0.0f), &m_menuBackground), m_itemMaterial(Color::WHITE)
{
	Font* font       = fontResources.get("DejaVuSansMono");
	m_optionItemText = new Text(NULL, &m_itemMaterial, font, "Option");
	m_quitItemText   = new Text(NULL, &m_itemMaterial, font, "Quit");

	m_optionItem     = new ItemMenu(NULL, m_optionItemText);
	m_quitItem       = new ItemMenu(NULL, m_quitItemText);

	m_menu.addItem(m_optionItem);
	m_menu.addItem(m_quitItem);
}

Start::~Start()
{
	delete m_optionItem;
	delete m_quitItem;
	delete m_optionItemText;
	delete m_quitItemText;
}
