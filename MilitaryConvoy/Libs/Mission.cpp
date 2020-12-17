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

	Mission& Mission::setTableC(Table& key) {
		tabC = key;  
		return *this; 
	}

	Mission& Mission::setTableP(Table& key) {
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

	Mission& Mission::setWeightLeft(long& key) {
		if (key > 0)
			WeightLeft = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setDelWeight(long& key) {
		if (key > 0)
			DelWeight = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setLostWeight(long& key) {
		if (key > 0)
			LostWeight= key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setMaxShipCon(int& key) {
		if (key > 0)
			MaxShipCon = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Mission& Mission::setMaxShipPir(int& key) {
		if (key > 0)
			MaxShipPir = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this; 
	}

	Mission& Mission::setCoordA(const std::pair<int, int>& key) {
		Coordinates_A = key; 
		return *this; 
	}

	Mission& Mission::setCoordB(const std::pair<int, int>& key) {
		Coordinates_B = key; 
		return *this; 
	}

	Mission& Mission::setCoordPir(const std::pair<int, int>& key) { 
		Coordinates_Pir = key; 
		return *this; 
	}

	Ship* Mission::getShipCon(const std::string& name)
	{
		
		auto it = tabC.getShip(name);
		if (it != tabC.end())
			return it->ship;
		else
			throw std::out_of_range("Ship not found\n");
	}

	Ship* Mission::getShipPir(const std::string& name)
	{
		auto it = tabP.getShip(name);
		if (it != tabP.end())
			return it->ship;
		else
			throw std::out_of_range("Ship not found\n");
	}


	Mission& Mission::createShipP()
	{
		DefShip* def;
		Unit un;
		def = new DefShip();
		un.ship = def;
		un.coordinates = Coordinates_Pir;
		if (tabP.size() == 0)
			un.name = "9";
		else
		{
			Unit cur = tabP.back();
			int nm = stoi(cur.name);
			nm++;
			char* str = new char[10];
			_itoa_s(nm,str,10,10);
			un.name = std::string(str);
		}
		tabP.push_back(un);
		return *this;
	}

	Mission& Mission::buyCon(const int& choice)
	{
		/*if (MoneyLeft < 100) {
			std::cout << "Not Enough Money\n";
			return *this;
		}*/
		/*std::cout << "What type of ship do you want to add:\n1)Empty\n2)Supply ship\n3)Defend ship\n";*/
		SupShip* sup;
		DefShip* def;
		Unit un;
		switch (choice)
		{
		case 1:
			sup = new SupShip(100, 25);
			un.ship = sup;
			MoneyLeft -= sup->getPrice();
			break;
		case 2:
			def = new DefShip();
			un.ship = def;
			MoneyLeft -= def->getPrice();
			break;
		}
		un.coordinates = Coordinates_A;
		if (tabC.size() == 0)
			un.name = "a";
		else
		{
			Unit cur = tabC.back();
			char nm = cur.name[0];
			nm++;
			un.name = nm;
		}
		tabC.push_back(un);
		return *this;
	}
	
	Mission& Mission::sellCon(std::string name)
	{
		if (tabC.getShip(name) != tabC.end())
		{
			MoneyLeft += tabC.getShip(name)->ship->getPrice();
			tabC.erase(name);
			
		}
		else
			throw std::out_of_range("Ship not found\n");
		return *this;
	}

	Mission& Mission::buyWepon(const std::string& name, const std::string& place, BatArm& weapon)
	{
		DefShip* sh = dynamic_cast<DefShip*>(tabC.getShip(name)->ship);
		if (sh)
		{
			sh->Modify(place, weapon);
			MoneyLeft -= weapon.getPrice();
		}
		else
			throw std::out_of_range("Ship not found\n");
		/*for (it = tabC.begin(); it != tabC.end(); ++it)
		{
			if (it->name == name)
			{
				Ship* sh = it->ship;
				DefShip* curShip = dynamic_cast<DefShip*>(it->ship);
				if(curShip)
					curShip->Modify(place,weapon);
			}
		}*/
		return *this;
	}

	Mission& Mission::destroyShipCon(const std::string& name)
	{
		if (tabC.getShip(name) != tabC.end()) 
		{
			tabC.erase(name);
		}
		else
			std::cout << "Ship not found";
		/*std::vector<Unit>::iterator it;
		for (it = tabC.begin(); it != tabC.end(); ++it)
		{
			if (it->name == name)
			{
				tabC.erase(it);
			}
		}*/
		return *this;
	}

	Mission& Mission::destroyShipPir(const std::string& name)
	{
		if (tabP.getShip(name) != tabP.end())
		{
			tabP.erase(name);
		}
		else
			std::cout << "Ship not found";
		return *this;
	}

	Mission& Mission::sellWeapon(const std::string& name, const std::string& place)
	{

		DefShip* sh = dynamic_cast<DefShip*>(tabC.getShip(name)->ship);
		if (sh)
		{
			std::map<std::string, BatArm>::iterator it = sh->getMap().find(place);
			if (it != sh->getMap().end())
			{
				MoneyLeft += it->second.getPrice();
				sh->getMap().erase(it);
			}
			else
				throw std::out_of_range("Weapon not found\n");
		}
		else
			throw std::out_of_range("Ship not found\n");
		return *this;
	}

	Mission& Mission::loadShip(const std::string& name, int count)
	{
		SupShip* sh = dynamic_cast<SupShip*>(tabC.getShip(name)->ship);
		if (sh)
		{
			if (sh->getMaxWeight() - sh->getWeight() >= count)
				sh->setWeight(sh->getWeight() + count);
			else
				throw std::out_of_range("Not enough place in ship\n");
		}
		else 
			throw std::out_of_range("Ship not found\n");
		return *this;
	}

	Mission& Mission::unloadShip(const std::string& name, int count)
	{
		SupShip* sh = dynamic_cast<SupShip*>(tabC.getShip(name)->ship);
		if (sh)
		{
			if (sh->getWeight() >= count)
				sh->setWeight(sh->getWeight() - count);
			else
				sh->setWeight(0);
		}
		else
			throw std::out_of_range("Ship not found\n");
		return *this;
	}

	std::ostream& operator <<(std::ostream& c, Mission& a)
	{
		c << "Mission info:\n";
		c << "Captain:" << a.cap << std::endl;
		c << "StartMoney/MoneyLeft:" << a.StartMoney << '/' << a.MoneyLeft;
		c << "\nFullWeight/WeightLeft:" << a.FullWeight << '/' << a.WeightLeft;
		c << "\nDelWeight/LostWeight:" << a.DelWeight << '/' << a.LostWeight;
		c << "\nMaxShipCon/MaxShipPir:" << a.MaxShipCon << '/' << a.MaxShipPir;
		c << "\nCoordinates of Base A (x;y): (" << a.Coordinates_A.first << ';' << a.Coordinates_A.second << ")\n";
		c << "Coordinates of Base B (x;y): (" << a.Coordinates_B.first << ';' << a.Coordinates_B.second << ")\n";
		c << "Coordinates of Pirate Base (x;y): (" << a.Coordinates_Pir.first << ';' << a.Coordinates_Pir.second << ")\n";
		c << "Time of pirate spawn:" << a.time << std::endl;
		c << "Convoy Ships:\n\n";
		auto it = a.tabC.begin();
		for (it; it != a.tabC.end(); ++it)
		{
			c << "\tName: \"" << it->name << "\"" << std::endl;
			c << "\tCoordinates (x;y): (" << it->coordinates.first << ';' << it->coordinates.second << ")\n";
			c << "Ship:" << (it->ship) << std::endl;
		}
		c << "\n\nPirate Ships:\n\n";
		it = a.tabP.begin();
		for (it; it != a.tabP.end(); ++it)
		{
			c << "\tName: \"" << it->name << "\"" << std::endl;
			c << "\tCoordinates (x;y): (" << it->coordinates.first << ';' << it->coordinates.second << ")\n";
			c << "Ship:" << (it->ship) << std::endl;
		}
		return c;
	}
}