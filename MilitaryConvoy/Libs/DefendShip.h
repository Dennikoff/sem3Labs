#pragma once
#include <map>
#include "Ship.h"
#include "BattleArming.h"
namespace MC {
	class DefShip : virtual public Ship
	{
		int number;
		std::map <std::string, BatArm> mp;
	public:
		DefShip(std::string type, std::string name, Captain cap, double speed, int health, int price, std::map< std::string, BatArm > map = std::map<std::string, BatArm>())
			:Ship(type, name, cap, speed, health, price), mp(map), number(0) {};
		DefShip() : Ship(), mp(), number(0) {};
		std::map<std::string, BatArm>& getMap() { return mp; }
		int getNumber() { return number; };
		int setNumber(const int& key);
		DefShip& Modify(const std::string& place,const BatArm& weapon);
		DefShip& AddWeapon(const std::string& place, const BatArm& weapon);
		int Shot(int x, int y);
		virtual std::ostream& print(std::ostream& c) override;
		~DefShip()override {};
	};
}