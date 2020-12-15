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
		c << "Type = " << this->getType() << std::endl;
		c << "Name = " << this->getName() << std::endl;
		c << "Captain = " << this->getCaptain();
		c << "Maxhealth/health = " << this->getMaxHealth() << "/" << this->getHealth() << std::endl;
		c << "Maxspeed/speed = " << this->getMaxSpeed() << "/" << this->getSpeed() << std::endl;
		c << "Price = " << this->getPrice() << std::endl;
		c << "Maxweight/weight = " << this->maxweight << "/" << this->weight << std::endl;
		c << "Coefficient = " << this->coeff << std::endl << std::endl;
		return c << std::endl;
	}
}