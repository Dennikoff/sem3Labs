#include "BattleArming.h"
namespace MC {

	                                                     /*----------*/
														/* SETTERS: */
													   /*----------*/

	BatArm& BatArm::setType(std::string key) { 
		type = key;  
		return *this; 
	}

	BatArm& BatArm::setDamage(int key) {
		if (key > 0)
			damage = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	BatArm& BatArm::setRateFire(int key) {
		if (key > 0)
			ratefire = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	BatArm& BatArm::setRange(int key) {
		if (key > 0)
			range = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	BatArm& BatArm::setMaxAmmo(int key) {
		if (key > 0)
			maxammo = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	BatArm& BatArm::setAmmo(int key) {
		if (key > 0)
			ammo = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	BatArm& BatArm::setPrice(int key) {
		if (key > 0)
			price = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}


	int BatArm::Atack() {
		if(ammo)
		{
			ammo--;
			return damage;
		}
		return 0;
	}
}