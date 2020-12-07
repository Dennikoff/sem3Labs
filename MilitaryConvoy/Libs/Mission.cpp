#include "Mission.h"
#include <typeinfo>
namespace MC {
	std::map < std::string, BatArm> CreateEmptyMap()
	{
		std::map < std::string, BatArm> mp;
		mp["Bow"] = BatArm();
		mp["BoardR"] = BatArm();
		mp["BoardL"] = BatArm();
		mp["Stern"] = BatArm();
		return mp;
	}

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

	Ship* Mission::getShipCon(std::string name)
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

	Ship* Mission::getShipPir(std::string name)
	{
		std::vector<Unit>::iterator it;
		for (it = tabP.begin(); it != tabP.end(); ++it)
		{
			if (it->name == name)
			{
				break;
			}
		}
		Ship* a = new Ship("404");
		if (it != tabP.end())
			return it->ship;
		else
			return a;
	}

	Mission& Mission::buyCon()//допилить
	{
		if (MoneyLeft < 100)
		{
			"Not Enough Money\n";
		}
	}

	Mission& Mission::createShipP(Ship a)
	{

	}

	Unit Mission::createShipC()
	{
		/*if (MoneyLeft < 100) {
			std::cout << "Not Enough Money\n";
			return *this;
		}*/
		std::cout << "What type of ship do you want to add:\n1)Empty\n2)Supply ship\n3)Defend ship\n";
		int choice;
		Ship* a = new Ship("Ship", "a", Captain("Ivan", "Ivanov", "Ivanovich"), 1, 10, 100);
		//MoneyLeft -= 100;
		SupShip* sup;
		DefShip* def;
		Unit un;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			un.ship = a;
			break;
		case 2:
			sup = new SupShip(*a, 100, 25);
			un.ship = sup;
			break;
		case 3:
			def = new DefShip(*a, CreateEmptyMap());
			un.ship = def;
			break;
		}
		un.coordinates = std::make_pair(0, 0);
		if (tabC.size() == 0)
			un.name = "a";
		else
		{
			Unit cur = tabC.back();
			char nm = cur.name[1];
			nm++;
			un.name = nm;
		}
		//tabC.push_back(un);
		//return *this;
	}
	
	Mission& Mission::sellCon(std::string name)
	{
		std::vector<Unit>::iterator it;
		for (it = tabC.begin(); it != tabC.end(); ++it)
		{
			if (it->name == name)
			{
				MoneyLeft += it->ship->getPrice();
				tabC.erase(it);
			}
		}
		return *this;
	}

	Mission& Mission::buyWepon(std::string name)
	{
		std::vector<Unit>::iterator it;
		for (it = tabC.begin(); it != tabC.end(); ++it)
		{
			if (it->name == name)
			{
				Ship* sh = it->ship;
				DefShip* curShip = dynamic_cast<DefShip*>(it->ship);
				if(curShip)
					curShip->Modify(curShip->getMap(), MoneyLeft);
			}
		}
		return *this;
	}

	Mission& Mission::destroyShipCon(std::string name)
	{
		std::vector<Unit>::iterator it;
		for (it = tabC.begin(); it != tabC.end(); ++it)
		{
			if (it->name == name)
			{
				tabC.erase(it);
			}
		}
		return *this;
	}

	Mission& Mission::destroyShipCon(std::string name)
	{
		std::vector<Unit>::iterator it;
		for (it = tabP.begin(); it != tabP.end(); ++it)
		{
			if (it->name == name)
			{
				tabP.erase(it);
			}
		}
		return *this;
	}
}