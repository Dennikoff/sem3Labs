#pragma once
#include <map>
#include "Ship.h"
#include "BattleArming.h"
namespace MC {
	class DefShip : virtual public Ship
	{
		std::map <std::string, BatArm> mp;
	public:
		DefShip(std::string type, std::string name, Captain cap, double speed, int health, int price, std::map< std::string, BatArm > map = std::map<std::string, BatArm>())
			:Ship(type, name, cap, speed, health, price), mp(map) {};
		DefShip() : Ship(), mp() {};
		std::map<std::string, BatArm>& getMap() { return mp; }
		DefShip& Modify(const std::string& place,const BatArm& weapon);
		int Shot(int x, int y);
		virtual std::ostream& print(std::ostream& c) override;
	};
}