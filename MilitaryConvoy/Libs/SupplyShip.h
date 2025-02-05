#pragma once
#include "Ship.h"
namespace MC {
	class SupShip : virtual public Ship
	{
		int maxweight;
		int weight; //weight of the supply
		short coeff; //0..100 = 0.00..1.00
	public:
		SupShip() :Ship(), maxweight(100), weight(0), coeff(50) {};
		SupShip(std::string type , std::string name , Captain cap , double spd , int health , int price, int weight , short coeff )
			:Ship(type, name, cap, spd, health, price), maxweight(weight), weight(0), coeff(coeff) {}; // ������
		SupShip(int weight, short coeff) : maxweight(weight), weight(0), coeff(coeff) {};
		int getMaxWeight() { return maxweight; };
		int getWeight() { return weight; };
		short getCoeff() { return coeff; };
		SupShip& setWeight(int key);
		SupShip& setMaxWeight(int key);
		SupShip& setCoeff(short key);
		virtual std::ostream& print(std::ostream& c) override;
		double countSpeed() 
		{
			return getSpeed()*(1 - double((double(weight) / maxweight)*(coeff/100.00)));
		}
		~SupShip() override {};
	};
}