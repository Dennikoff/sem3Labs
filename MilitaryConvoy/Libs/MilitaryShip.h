#pragma once
#include "SupplyShip.h"
#include "DefendShip.h"
namespace MC {
	class MilShip : public DefShip, public SupShip
	{
	public:
		/*MilShip(Ship& a, int weight, short coeff, std::map<std::string, BatArm> mp)
			: Ship(a), weight(weight), maxweight(weight), map(mp) {}*/
		
	};
}