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


}