#pragma once
#include "Ship.h"
namespace MC {
	class SupShip : public Ship
	{
		int maxweight;
		int weight; //weight of the supply
		short coeff; //0..100 = 0.00..1.00
	public:
		SupShip(std::string type = "", std::string name = "", Captain cap = Captain(), double speed = 0, int health = 0, int price = 0, int weight = 0, short coeff = 100)
			:Ship(type, name, cap, speed, health, price),maxweight(weight), weight(weight), coeff(coeff) {};
		SupShip(Ship& a, int weight = 0, short coeff = 100) : Ship(a), maxweight(weight), weight(weight), coeff(coeff) {};
		int getMaxWeight() { return maxweight; };
		int getWeight() { return weight; };
		short getCoeff() { return coeff; };
		SupShip& setWeight(int key);
		SupShip& setMaxWeight(int key);
		SupShip& setCoeff(short key);
		double countSpeed() 
		{
			return getSpeed()*(1 - double((double(weight) / maxweight)*(coeff/100.00)));
		}
	};
}