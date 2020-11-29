#include "Mission.h"
namespace MC {

													     /*----------*/
														/* SETTERS: */
													   /*----------*/

	Mission& Mission::setCap(Captain& key) { 
		cap = key; 
		return *this; 
	}

	Mission& Mission::setTableC(std::vector<Unit>& key) {
		tabC = key;  
		return *this; 
	}

	Mission& Mission::setTableP(std::vector<Unit>& key) {
		tabP = key;  
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

	Ship& Mission::getShipCon(std::string name)
	{
		
		std::vector<Unit>::iterator it;
		for (it = tabC.begin(); it != tabC.end(); ++it)
		{
			if (it->name == name)
			{
				break;
			}
		}
			return it->ship;
	}

	Ship& Mission::getShipPir(std::string name)
	{
		std::vector<Unit>::iterator it;
		for (it = tabP.begin(); it != tabP.end(); ++it)
		{
			if (it->name == name)
			{
				break;
			}
		}
		Ship a("404");
		if (it != tabP.end())
			return it->ship;
		else
			return a;
	}

	Mission& Mission::createShipC(Ship a)//допилить
	{
		if (tabC.size())
		{
			Unit cur;
			//cur->name = tabC.back().name;
		}
	}

	Mission& Mission::createShipP(Ship a)
	{

	}
	Mission& Mission::buyCon()
	{
		Ship a();
	}
	
	Mission& Mission::sellCon()
	{

	}

}