#include "SupplyShip.h"
namespace MC{

	                                                     /*----------*/
														/* SETTERS: */
													   /*----------*/

	SupShip& SupShip::setWeight(int key) { 
		if (key > 0)
			weight = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	SupShip& SupShip::setMaxWeight(int key) {
		if (key > 0)
			maxweight = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	SupShip& SupShip::setCoeff(short key) {
		if (key > 0)
			coeff = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	std::ostream& SupShip::print(std::ostream& c)
	{
		c << "type = " << getType() << std::endl;
		c << "name = " << getName() << std::endl;
		c << "Captain = " << getCaptain();
		c << "maxhealth/health = " << getMaxHealth() << "/" << getHealth() << std::endl;
		c << "maxspeed/speed = " << getMaxSpeed() << "/" << getSpeed() << std::endl;
		c << "price = " << getPrice() << std::endl;
		c << "maxweight/weight = " << maxweight << "/" << weight << std::endl;
		c << "coeff = " << coeff << std::endl << std::endl;
	}
}