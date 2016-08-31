#include "Contexts/Start.h"
#include "Contexts/Game.h"

Start::Start(Game* game) : Context(game), m_menuBackgroundMaterial(Color::BLUE), m_menuBackground(NULL, &m_menuBackgroundMaterial), m_menu(this, NULL, glm::vec3(-0.5f, 0.5f, 0.0f), &m_menuBackground), m_itemMaterial(Color::WHITE)
{
	m_menu.setItemAlignment(X_CENTER);
	Font* font       = fontResources.get("DejaVuSansMono");

	m_startItemText  = new Text(NULL, &m_itemMaterial, font, "Start");
	m_optionItemText = new Text(NULL, &m_itemMaterial, font, "Option");
	m_quitItemText   = new Text(NULL, &m_itemMaterial, font, "Quit");

	m_startItem      = new ItemMenu(NULL, m_startItemText);
	m_optionItem     = new ItemMenu(NULL, m_optionItemText);
	m_quitItem       = new ItemMenu(NULL, m_quitItemText);

	ActiveListener startListener(Start::optionSelected, (void*)START_IN_GAME);
	ActiveListener optionListener(Start::optionSelected, (void*)START_OPTION);
	ActiveListener quitListener(Start::optionSelected, (void*)START_QUIT);

	m_startItem->setActiveListener(startListener);
	m_optionItem->setActiveListener(optionListener);
	m_quitItem->setActiveListener(quitListener);

	m_menu.addItemMenu(m_startItem);
	m_menu.addItemMenu(m_optionItem);
	m_menu.addItemMenu(m_quitItem);

	m_menu.setItemAlignment(X_CENTER);
	m_menu.setDefaultPositionOrigin(CENTER);
	m_menu.setPosition(-m_menu.getDefaultPos());
}

Start::~Start()
{
	delete m_startItem;
	delete m_optionItem;
	delete m_quitItem;

	delete m_startItemText;
	delete m_optionItemText;
	delete m_quitItemText;
}

//The Listener handler
void Start::optionSelected(Active* item, void* option)
{
	int selected = (int)option;
	m_game->changeContext(IN_GAME, new InGame_OnStart{.mapFile = "map.xml"});
}
