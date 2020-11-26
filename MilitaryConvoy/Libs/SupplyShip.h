#pragma once
#include "Ship.h"
namespace MC {
	class SupShip : public Ship
	{
		int maxweight;
		int weight; //weight of the supply
		short coeff; //0..100 = 0.00..1.00
	public:
		int getMaxWeight() { return maxweight; };
		int getWeight() { return weight; };
		short getCoeff() { return coeff; };
		SupShip& setWeight(int key);
		SupShip& setMaxWeight(int key);
		SupShip& setCoeff(short key);
		double CountSpeed() 
		{
			return getSpeed()*(1 - double((double(weight) / maxweight)*(coeff/100.00)));
		}
	};
}