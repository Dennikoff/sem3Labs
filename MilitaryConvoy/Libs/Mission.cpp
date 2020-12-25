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

	Mission& Mission::setCap(const Captain& key) {
		cap = key;
		return *this;
	}

	Mission& Mission::setTableC(const Table& key) {
		tabC = key;
		return *this;
	}

	Mission& Mission::setTableP(const Table& key) {
		tabP = key;
		return *this;
	}

	Mission& Mission::setStartMoney(const long& key) {
		if (key >= 0)
			StartMoney = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setMoneyLeft(const long& key) {
		if (key >= 0)
			MoneyLeft = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setFullWeight(const long& key) {
		if (key >= 0)
			FullWeight = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setWeightLeft(const long& key) {
		if (key >= 0)
			WeightLeft = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setDelWeight(const long& key) {
		if (key >= 0)
			DelWeight = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setLostWeight(const long& key) {
		if (key >= 0)
			LostWeight = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setMaxShipCon(const int& key) {
		if (key >= 0)
			MaxShipCon = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setMaxShipPir(const int& key) {
		if (key >= 0)
			MaxShipPir = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Mission& Mission::setTime(const int& key)
	{
		if (key >= 0)
			time = key;
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

	Mission& Mission::addShipCon(Unit un)
	{
		tabC.push_back(un);
		return *this;
	}

	Mission& Mission::addShipPir(Unit un)
	{
		tabP.push_back(un);
		return *this;
	}

	Mission& Mission::createShipP()
	{
		DefShip* def;
		Unit un;
		def = new DefShip();
		def->setType("def");
		un.ship = def;
		un.coordinates = Coordinates_Pir;
		if (tabP.size() == 0)
			un.name = "1";
		else
		{
			Unit cur = tabP.back();
			int nm = stoi(cur.name);
			nm++;
			char* str = new char[10];
			_itoa_s(nm, str, 10, 10);
			un.name = std::string(str);
		}
		tabP.push_back(un);
		return *this;
	}

	Mission& Mission::createWeapon(const std::string& name, const std::string& place, BatArm& weapon)
	{
		auto it = tabP.getShip(name);
		if (it != tabP.end())
		{
			DefShip* sh = dynamic_cast<DefShip*>(it->ship);
			if (sh)
			{
				if (sh->getMap().find(place) != sh->getMap().end())
					sh->setNumber(sh->getNumber() - 1);
				sh->Modify(place, weapon);

			}
			else
				throw std::out_of_range("Ship has incorrect type\n");
		}
		else
			throw std::out_of_range("Ship not found\n");

		return *this;
	}

	Mission& Mission::buyCon(const int& choice)
	{
		if (MoneyLeft < 300) throw std::out_of_range("Not enough money");
		SupShip* sup;
		DefShip* def;
		MilShip* mil;
		Unit un;
		switch (choice)
		{
		case 1:
			sup = new SupShip();
			sup->setType("sup");
			un.ship = sup;
			MoneyLeft -= sup->getPrice();
			break;
		case 2:
			def = new DefShip();
			def->setType("def");
			un.ship = def;
			MoneyLeft -= def->getPrice();
			break;
		case 3:
			mil = new MilShip();
			mil->setType("mil");
			un.ship = mil;
			MoneyLeft -= mil->getPrice();
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
			DefShip* def = dynamic_cast<DefShip*>(tabC.getShip(name)->ship);
			if (def)
			{
				auto map = def->getMap();
				auto it = map.begin();
				for (it; it != map.end(); ++it)
				{
					MoneyLeft+=it->second.getPrice();
				}
			}
			tabC.erase(name);
		}
		else
			throw std::out_of_range("Ship not found\n");
		return *this;
	}

	Mission& Mission::buyWeapon(const std::string& name, const std::string& place, BatArm& weapon)
	{
		auto it = tabC.getShip(name);
		if (it != tabC.end()) {
			DefShip* sh = dynamic_cast<DefShip*>(it->ship); //разница между придениями
			if (sh)
			{
				if (sh->getMap().find(place) == sh->getMap().end())
				{
					if (MoneyLeft - weapon.getPrice() < 0) throw std::invalid_argument("Not enough money");
					sh->Modify(place, weapon);
					MoneyLeft -= weapon.getPrice();
				}
				else
				{
					if (MoneyLeft + sh->getMap().find(place)->second.getPrice() - weapon.getPrice() < 0) throw std::invalid_argument("Not enough money");
					MoneyLeft += sh->getMap().find(place)->second.getPrice();
					sh->setNumber(sh->getNumber() - 1);
					sh->Modify(place, weapon);
					MoneyLeft -= weapon.getPrice();
				}
			}
			else
				throw std::out_of_range("Ship has incorrct type\n");
		}
		else
			throw std::out_of_range("Ship not found\n");
		return *this;
	}

	Mission& Mission::destroyShipCon(const std::string& name)
	{
		if (tabC.getShip(name) != tabC.end())
		{
			SupShip* sup = dynamic_cast<SupShip*>(tabC.getShip(name)->ship);
			if (sup)
			{
				LostWeight += sup->getWeight();
			}
			tabC.erase(name);
		}
		else
			throw std::out_of_range("Ship not found");
		return *this;
	}

	Mission& Mission::destroyShipPir(const std::string& name)
	{
		if (tabP.getShip(name) != tabP.end())
		{
			tabP.erase(name);
		}
		else
			throw std::out_of_range("Ship not found");
		return *this;
	}

	Mission& Mission::sellWeapon(const std::string& name, const std::string& place)
	{
		auto it = tabC.getShip(name);
		if (it != tabC.end())
		{
			DefShip* sh = dynamic_cast<DefShip*>(it->ship);
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
				throw std::out_of_range("Ship has Incorrect type\n");
		}
		else
			throw std::out_of_range("Ship hasn't found\n");
		return *this;
	}

	Mission& Mission::loadShip(const std::string& name, int count)
	{
		auto it = tabC.getShip(name);
		if (it != tabC.end())
		{
			SupShip* sh = dynamic_cast<SupShip*>(it->ship);
			if (sh)
			{
				if (sh->getMaxWeight() - sh->getWeight() >= count)
				{
					if (this->getWeigthLeft() < count)
					{
						count = this->getWeigthLeft();
					}
					sh->setWeight(sh->getWeight() + count);
					this->setWeightLeft(this->getWeigthLeft() - count);
				}
				else
					throw std::out_of_range("Not enough place in ship\n");
			}
			else
				throw std::out_of_range("Ship has incorrect type\n");
		}
		else
			throw std::out_of_range("Ship hasn't found\n");
		return *this;
	}

	Mission& Mission::unloadShip(const std::string& name, int count)
	{
		auto it = tabC.getShip(name);
		if (it != tabC.end())
		{
			SupShip* sh = dynamic_cast<SupShip*>(it->ship);
			if (sh)
			{
				if (sh->getWeight() >= count)
				{
					sh->setWeight(sh->getWeight() - count);
					this->setWeightLeft(this->getWeigthLeft() + count);
				}
				else
				{
					this->setWeightLeft(this->getWeigthLeft() + sh->getWeight());
					sh->setWeight(0);
				}
			}
			else
				throw std::out_of_range("Ship has incorrect type\n");
		}
		else
			throw std::out_of_range("Ship hasn't found\n");
		return *this;
	}

	Mission readFromFileMis(std::string name)
	{
		Mission h;
		std::fstream fs;
		fs.open(name, std::fstream::in | std::fstream::out);
		std::string str;
		std::getline(fs, str);
		Captain cap = readFromFileCap(fs);
		h.setCap(cap);
		std::getline(fs, str);
		str.erase(str.find("/"), 1);
		h.setStartMoney(stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2)));
		h.setMoneyLeft(stoi(str.substr(str.find("/") + 1)));
		std::getline(fs, str);
		str.erase(str.find("/"), 1);
		h.setFullWeight(stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2)));
		h.setWeightLeft(stoi(str.substr(str.find("/") + 1)));
		std::getline(fs, str);
		str.erase(str.find("/"), 1);
		h.setDelWeight(stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2)));
		h.setLostWeight(stoi(str.substr(str.find("/") + 1)));
		std::getline(fs, str);
		str.erase(str.find("/"), 1);
		h.setMaxShipCon(stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2)));
		h.setMaxShipPir(stoi(str.substr(str.find("/") + 1)));
		std::getline(fs, str);
		str.erase(str.find("("), 5);
		h.setCoordA(std::make_pair(stoi(str.substr(str.find("(") + 1, str.find(";") - str.find("(") - 1)), stoi(str.substr(str.find(";") + 1, str.find(")") - str.find(";") - 1))));
		std::getline(fs, str);
		str.erase(str.find("("), 5);
		h.setCoordB(std::make_pair(stoi(str.substr(str.find("(") + 1, str.find(";") - str.find("(") - 1)), stoi(str.substr(str.find(";") + 1, str.find(")") - str.find(";") - 1))));
		std::getline(fs, str);
		str.erase(str.find("("), 5);
		h.setCoordPir(std::make_pair(stoi(str.substr(str.find("(") + 1, str.find(";") - str.find("(") - 1)), stoi(str.substr(str.find(";") + 1, str.find(")") - str.find(";") - 1))));
		std::getline(fs, str);
		h.setTime(stoi(str.substr(str.find(":") + 2)));
		std::getline(fs, str);
		std::getline(fs, str);
		std::getline(fs, str);
		Unit un;
		while (str.find("Pirate") == -1)
		{
			int x = str.find("\"");
			str.erase(x, 1);
			un.name = str.substr(x, str.find("\"") - x);
			std::getline(fs, str);
			str.erase(str.find("("), 5);
			un.coordinates = (std::make_pair(stoi(str.substr(str.find("(") + 1, str.find(";") - str.find("(") - 1)), stoi(str.substr(str.find(";") + 1, str.find(")") - str.find(";") - 1))));
			DefShip* def;
			SupShip* sup;
			MilShip* mil;
			std::getline(fs, str);
			std::getline(fs, str);
			std::string tp = str.substr(str.find(":") + 2);
			std::getline(fs, str);
			std::string name = str.substr(str.find(":") + 2);
			Captain cap = readFromFileCap(fs);
			std::getline(fs, str);
			str.erase(str.find("/"), 1);
			int MaxHealth = stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2));
			int Health = stoi(str.substr(str.find("/") + 1));
			std::getline(fs, str);
			str.erase(str.find("/"), 1);
			int MaxSpeed = stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2));
			int Speed = stoi(str.substr(str.find("/") + 1));
			std::getline(fs, str);
			int Price = stoi(str.substr(str.find(":") + 2));
			if (tp == "def")
			{
				def = new DefShip();
				def->setType(tp);
				def->setName(name);
				def->setCaptain(cap);
				def->setMaxHealth(MaxHealth);
				def->setHealth(Health);
				def->setMaxSpeed(MaxSpeed);
				def->setSpeed(Speed);
				def->setPrice(Price);
				std::getline(fs, str);
				std::getline(fs, str);
				std::getline(fs, str);
				def->setNumber(stoi(str.substr(str.find(":") + 2)));
				for (int i = 0; i < def->getNumber(); i++)
				{
					BatArm weapon;
					std::getline(fs, str);
					std::getline(fs, str);
					std::string place = str.substr(0, str.find(":"));
					std::getline(fs, str);
					weapon.setType(str.substr(str.find(":") + 2));
					std::getline(fs, str);
					str.erase(str.find("/"), 1);
					weapon.setMaxAmmo(stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2)));
					weapon.setAmmo(stoi(str.substr(str.find("/") + 1)));
					std::getline(fs, str);
					weapon.setDamage(stoi(str.substr(str.find(":") + 2)));
					std::getline(fs, str);
					weapon.setRange(stoi(str.substr(str.find(":") + 2)));
					std::getline(fs, str);
					weapon.setRateFire(stoi(str.substr(str.find(":") + 2)));
					std::getline(fs, str);
					weapon.setPrice(stoi(str.substr(str.find(":") + 2)));
					def->AddWeapon(place, weapon);
				}
				un.ship = def;
			}
			else if (tp == "sup")
			{
				sup = new SupShip();
				sup->setType(tp);
				sup->setName(name);
				sup->setCaptain(cap);
				sup->setMaxHealth(MaxHealth);
				sup->setHealth(Health);
				sup->setMaxSpeed(MaxSpeed);
				sup->setSpeed(Speed);
				sup->setPrice(Price);
				std::getline(fs, str);
				str.erase(str.find("/"), 1);
				sup->setMaxWeight(stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2)));
				sup->setWeight(stoi(str.substr(str.find("/") + 1)));
				std::getline(fs, str);
				sup->setCoeff(stoi(str.substr(str.find(":") + 2)));
				//std::cout << sup;
				un.ship = sup;
			}
			else if (tp == "mil")
			{
				mil = new MilShip();
				mil->setType(tp);
				mil->setName(name);
				mil->setCaptain(cap);
				mil->setMaxHealth(MaxHealth);
				mil->setHealth(Health);
				mil->setMaxSpeed(MaxSpeed);
				mil->setSpeed(Speed);
				mil->setPrice(Price);
				std::getline(fs, str);
				str.erase(str.find("/"), 1);
				mil->setMaxWeight(stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2)));
				mil->setWeight(stoi(str.substr(str.find("/") + 1)));
				std::getline(fs, str);
				mil->setCoeff(stoi(str.substr(str.find(":") + 2)));
				std::getline(fs, str);
				std::getline(fs, str);
				std::getline(fs, str);
				mil->setNumber(stoi(str.substr(str.find(":") + 2)));
				for (int i = 0; i < mil->getNumber(); i++)
				{
					BatArm weapon;
					std::getline(fs, str);
					std::getline(fs, str);
					std::string place = str.substr(0, str.find(":"));
					std::getline(fs, str);
					weapon.setType(str.substr(str.find(":") + 2));
					std::getline(fs, str);
					str.erase(str.find("/"), 1);
					weapon.setMaxAmmo(stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2)));
					weapon.setAmmo(stoi(str.substr(str.find("/") + 1)));
					std::getline(fs, str);
					weapon.setDamage(stoi(str.substr(str.find(":") + 2)));
					std::getline(fs, str);
					weapon.setRange(stoi(str.substr(str.find(":") + 2)));
					std::getline(fs, str);
					weapon.setRateFire(stoi(str.substr(str.find(":") + 2)));
					std::getline(fs, str);
					weapon.setPrice(stoi(str.substr(str.find(":") + 2)));
					mil->AddWeapon(place, weapon);
				}
				un.ship = mil;
			}
			h.addShipCon(un);
			std::getline(fs, str);
			std::getline(fs, str);
		}
		std::getline(fs, str);
		std::getline(fs, str);
		while (str.find("Name") != -1)
		{
			int x = str.find("\"");
			str.erase(x, 1);
			un.name = str.substr(x, str.find("\"") - x);
			std::getline(fs, str);
			str.erase(str.find("("), 5);
			un.coordinates = (std::make_pair(stoi(str.substr(str.find("(") + 1, str.find(";") - str.find("(") - 1)), stoi(str.substr(str.find(";") + 1, str.find(")") - str.find(";") - 1))));
			DefShip* def;
			std::getline(fs, str);
			std::getline(fs, str);
			std::string tp = str.substr(str.find(":") + 2);
			std::getline(fs, str);
			std::string name = str.substr(str.find(":") + 2);
			Captain cap = readFromFileCap(fs);
			std::getline(fs, str);
			str.erase(str.find("/"), 1);
			int MaxHealth = stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2));
			int Health = stoi(str.substr(str.find("/") + 1));
			std::getline(fs, str);
			str.erase(str.find("/"), 1);
			int MaxSpeed = stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2));
			int Speed = stoi(str.substr(str.find("/") + 1));
			std::getline(fs, str);
			int Price = stoi(str.substr(str.find(":") + 2));
			if (tp == "def")
			{
				def = new DefShip();
				def->setType(tp);
				def->setName(name);
				def->setCaptain(cap);
				def->setMaxHealth(MaxHealth);
				def->setHealth(Health);
				def->setMaxSpeed(MaxSpeed);
				def->setSpeed(Speed);
				def->setPrice(Price);
				std::getline(fs, str);
				std::getline(fs, str);
				std::getline(fs, str);
				def->setNumber(stoi(str.substr(str.find(":") + 2)));
				for (int i = 0; i < def->getNumber(); i++)
				{
					BatArm weapon;
					std::getline(fs, str);
					std::getline(fs, str);
					std::string place = str.substr(0, str.find(":"));
					std::getline(fs, str);
					weapon.setType(str.substr(str.find(":") + 2));
					std::getline(fs, str);
					str.erase(str.find("/"), 1);
					weapon.setMaxAmmo(stoi(str.substr(str.find(":") + 2, str.find("/") - str.find(":") - 2)));
					weapon.setAmmo(stoi(str.substr(str.find("/") + 1)));
					std::getline(fs, str);
					weapon.setDamage(stoi(str.substr(str.find(":") + 2)));
					std::getline(fs, str);
					weapon.setRange(stoi(str.substr(str.find(":") + 2)));
					std::getline(fs, str);
					weapon.setRateFire(stoi(str.substr(str.find(":") + 2)));
					std::getline(fs, str);
					weapon.setPrice(stoi(str.substr(str.find(":") + 2)));
					def->AddWeapon(place, weapon);
				}
				un.ship = def;
			}
			h.addShipPir(un);
		}
		fs.close();
		return h;
	}

	int Mission::writeToFile(std::string name)
	{
		std::fstream fs;
		fs.open(name, std::fstream::in | std::fstream::out);
		if (!fs.is_open())
			return -1;
		fs << *this;
		fs.close();
		return 0;
	}

	std::ostream& operator <<(std::ostream& c, Mission& a) //запись в файл убрать \n
	{
		c << "Mission info:" << std::endl;
		c << "Captain -> " << a.cap;
		c << "StartMoney/MoneyLeft: " << a.StartMoney << '/' << a.MoneyLeft << std::endl;
		c << "FullWeight/WeightLeft: " << a.FullWeight << '/' << a.WeightLeft << std::endl;
		c << "DelWeight/LostWeight: " << a.DelWeight << '/' << a.LostWeight << std::endl;
		c << "MaxShipCon/MaxShipPir: " << a.MaxShipCon << '/' << a.MaxShipPir << std::endl;
		c << "Coordinates of Base A (x;y): (" << a.Coordinates_A.first << ';' << a.Coordinates_A.second << ")" << std::endl;
		c << "Coordinates of Base B (x;y): (" << a.Coordinates_B.first << ';' << a.Coordinates_B.second << ")" << std::endl;
		c << "Coordinates of Pirate Base (x;y): (" << a.Coordinates_Pir.first << ';' << a.Coordinates_Pir.second << ")" << std::endl;
		c << "Time of pirate spawn: " << a.time << std::endl;
		c << "Convoy Ships:" << std::endl << std::endl;
		auto it = a.tabC.begin();
		for (it; it != a.tabC.end(); ++it)
		{
			c << "\tName: \"" << it->name << "\"" << std::endl;
			c << "\tCoordinates (x;y): (" << it->coordinates.first << ';' << it->coordinates.second << ")" << std::endl;
			c << "\tShip:" << std::endl << (it->ship);
		}
		c << "Pirate Ships:" << std::endl << std::endl;
		it = a.tabP.begin();
		for (it; it != a.tabP.end(); ++it)
		{

			c << "\tName: \"" << it->name << "\"" << std::endl;
			c << "\tCoordinates (x;y): (" << it->coordinates.first << ';' << it->coordinates.second << ")" << std::endl;
			c << "Ship:" << std::endl << (it->ship);
		}
		return c;
	}
}