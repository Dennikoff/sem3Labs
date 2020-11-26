#include "Ship.h"
namespace MC{
	                                                     /*----------*/
														/* SETTERS: */
													   /*----------*/

	Ship& Ship::setType(std::string key) { 
		type = key;  
		return *this; 
	}

	Ship& Ship::setName(std::string key) {
		name = key;  
		return *this; 
	}

	Ship& Ship::setMaxSpeed(double key) {
		if (key > 0)
			maxspeed = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Ship& Ship::setSpeed(double key) {
		if (key > 0)
			speed = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Ship& Ship::setMaxHealth(int key) {
		if (key > 0)
			maxhealth = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Ship& Ship::setHealth(int key) {
		if (key > 0)
			health = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Ship& Ship::setPrice(int key) {
		if (key > 0)
			price = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Ship& Ship::takeDamage(int k)
	{
		if (health - k > 0)
		{
			health -= k;
		}
		else
		{
			health = 0;
		}
		return *this;
	}
}