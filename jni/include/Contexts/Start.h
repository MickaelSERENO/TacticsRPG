#ifndef  START_INC
#define  START_INC

#include "Widgets/Menu.h"
#include "Widgets/ItemMenu.h"
#include "Shape/Rectangle.h"
#include "Materials/UniColorMaterial.h"
#include "Graphics/Text.h"

#include "Listeners/ActiveListener.h"
#include "Contexts/Context.h"
#include "Contexts/SharedData.h"
#include "GameResources.h"
#include "UnitStats.h"

enum StartOption
{
	START_OPTION, START_IN_GAME, START_QUIT
};

class Start : public Context
{
	public:
		Start(Game* game);
		~Start();
		void onUpdate(Render* render);

		static void optionSelected(Active* item, void* option);
	private:
		UniColorMaterial m_menuBackgroundMaterial;
		Rectangle        m_menuBackground;
		Menu             m_menu;

		UniColorMaterial m_itemMaterial;
		ItemMenu*        m_startItem;
		ItemMenu*        m_optionItem;
		ItemMenu*        m_quitItem;

		Text*            m_startItemText;
		Text*            m_optionItemText;
		Text*            m_quitItemText;
};

#endif
