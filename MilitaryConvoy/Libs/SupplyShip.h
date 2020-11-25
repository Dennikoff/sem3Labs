#pragma once
#include "Ship.h"
namespace MC {
	class SupShip : public Ship
	{
		int maxweight;
		int weight; //weight of the supply
		short coeff; //0..100
	public:
		int getMaxWeight() { return maxweight; };
		int getWeight() { return weight; };
		SupShip& setWeight(int key) { weight = key; return *this; };
		SupShip& setMaxWeight(int key) { maxweight = key;  return *this; };
		double CountSpeed() 
		{
			return getSpeed()*(1 - double((double(weight) / maxweight)*(coeff/100.00)));
		}
	};
}