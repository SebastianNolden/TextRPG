#include "HUD.h"
#include <string>
#include "Displaystats.h"
#include "Misc.h"


HUD::HUD()
{
}

HUD::HUD(Window & screen, player & player)
{
	Misc misc;

	std::string name("Name: "), Lv("Lv  : " ), HP("HP  : "), MP("MP  : "), div("/");

	std::string c_Lv(Lv + misc.turnNumberIntoString(player.getPlayerLv())),
				c_Name(name + (player.getName())),
				c_HP(HP + misc.turnNumberIntoString(player.getPlayerCurrentHp()) + div + misc.turnNumberIntoString(player.getPlayerMaxHp())),
				c_MP(MP + misc.turnNumberIntoString(player.getPlayerCurrentMp()) + div + misc.turnNumberIntoString(player.getPlayerMaxMp()))
		;

	this->_displayName = displayStats(screen, c_Name);
	this->_displayLevel = displayStats(screen, c_Lv);
	this->_displayHP = displayStats(screen, c_HP);
	this->_displayMP = displayStats(screen, c_MP);
}

void HUD::draw(Window & screen) {
	this->_displayName.draw(screen, 10, 100);
	this->_displayLevel.draw(screen, 10, 115);
	this->_displayHP.draw(screen, 10, 130);
	this->_displayMP.draw(screen, 10, 145);
}


