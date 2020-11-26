#include "Mission.h"
namespace MC {

													     /*----------*/
														/* SETTERS: */
													   /*----------*/

	Mission& Mission::setCap(Captain& key) { 
		cap = key; 
		return *this; 
	}

	Mission& Mission::setTableC(Table& key) {
		Convoy_tab = key;  
		return *this; 
	}

	Mission& Mission::setTableR(Table& key) {
		Pirate_tab = key;  
		return *this; 
	}

	Mission& Mission::setStartMoney(long& key) {
		if (key > 0)
			StartMoney = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Mission& Mission::setMoneyLeft(long& key) {
		if (key > 0)
			MoneyLeft = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Mission& Mission::setFullWeight(long& key) {
		if (key > 0)
			FullWeight = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Mission& Mission::setMaxShip_Con(int& key) {
		if (key > 0)
			MaxShip_Con = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Mission& Mission::setMaxShip_Pir(int& key) {
		if (key > 0)
			MaxShip_Pir = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Mission& Mission::setCoordA(std::pair<int, int>& key) {
		Coordinates_A = key; 
		return *this; 
	}

	Mission& Mission::setCoordB(std::pair<int, int>& key) {
		Coordinates_B = key; 
		return *this; 
	}

	Mission& Mission::setCoordPir(std::pair<int, int>& key) { 
		Coordinates_Pir = key; 
		return *this; 
	}

}