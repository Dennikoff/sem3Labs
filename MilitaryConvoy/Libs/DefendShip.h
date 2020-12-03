#pragma once
#include <map>
#include "Ship.h"
#include "BattleArming.h"
namespace MC {
	class DefShip : public Ship
	{
		std::map <std::string, BatArm> mp;
	public:
		DefShip(std::string type = "", std::string name = "", Captain cap = Captain(), double speed = 0, int health = 0, int price = 0, std::map< std::string, BatArm > map = std::map<std::string, BatArm>())
			:Ship(type, name, cap, speed, health, price), mp(map) {};
		DefShip(Ship& a, std::map < std::string, BatArm > map) : Ship(a), mp(map) {};
		std::map<std::string, BatArm> getMap() { return mp; }
		DefShip& Modify(std::map<std::string, BatArm> map,long& money);
		int Shot(int x, int y);

	};
}