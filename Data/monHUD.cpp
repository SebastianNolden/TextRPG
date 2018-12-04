#include "monHUD.h"
#include <string>
#include "Displaystats.h"
#include "Misc.h"


monHUD::monHUD()
{
}

monHUD::monHUD(Window & screen, Goblin & goblin) {
	Misc misc;

	std::string name("Name: "), Lv("Lv  : "), HP("HP  : "), MP("MP  : "), div("/");

	std::string g_Lv(Lv + misc.turnNumberIntoString(goblin.getGoblinLv())),
		    	g_Name(name + (goblin.getName())),
			    g_HP(HP + misc.turnNumberIntoString(goblin.getGoblinCurrentHp()) + div + misc.turnNumberIntoString(goblin.getGoblinMaxHp())),
				g_MP(MP + misc.turnNumberIntoString(goblin.getGoblinCurrentMp()) + div + misc.turnNumberIntoString(goblin.getGoblinMaxMp()))
			;

	this->_displayMonName = displayStats(screen, g_Name);
	this->_displayMonLevel = displayStats(screen, g_Lv);
	this->_displayMonHP = displayStats(screen, g_HP);
	this->_displayMonMP = displayStats(screen, g_MP);
}

void monHUD::draw(Window & screen, std::string monType) {
	if (monType == "Goblin") {
		this->_displayMonName.draw(screen, 800, 100);
		this->_displayMonLevel.draw(screen, 800, 115);
		this->_displayMonHP.draw(screen, 800, 130);
		this->_displayMonMP.draw(screen, 800, 145);
	}
}
