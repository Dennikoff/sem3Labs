#pragma once
#include <map>
#include "Ship.h"
#include "BattleArming.h"
namespace MC {
	class DefShip : public Ship
	{
		std::map <std::string, BatArm> mp;
	};
}