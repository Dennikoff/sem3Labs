#include "../Libs/Mission.h"
#include <iostream>
using namespace MC;
int main()
{
	Mission h;
	std::fstream fs;
	fs.open("data.txt",std::fstream::in| std::fstream::out);
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
	h.setTime(stoi(str.substr(str.find(":")+2)));
	std::getline(fs, str);
	std::getline(fs, str);
	std::getline(fs, str);
	Unit un;
	while(str.find("Pirate") == -1)
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
			//std::cout << def;
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
			//std::cout << mil;
			un.ship = mil;
		}
		h.addShipCon(un);
		std::getline(fs, str);
		std::getline(fs, str);
	}
	std::cout << h;
	//std::cout << "\n" <<str.substr(str.find(";") + 1, str.find(")") - str.find(";") - 1);
	//h.setStartMoney(10000);
	//std::cout << cap;
	//cap.setName();
	//std::cout << str;
	/*MilShip mil;
	mil.print(std::cout);*/
	/*Unit h;
	SupShip();
	h.ship = new DefShip();
	std::cout << typeid(*(h.ship)).name();*/
	/*std::fstream fs;
	std::string nm = "data.txt";
	fs.open(nm,std::fstream::in| std::fstream::out);
	Mission h;
	h.setCoordA(std::make_pair(10,0));
	h.setCoordB(std::make_pair(100,0));
	h.setCoordPir(std::make_pair(10,10));
	BatArm weapon("Mashine gun",200,14,50,30,200);
	h.buyCon(2);
	h.buyCon(1);
	h.buyWeapon("a", "Stern", weapon);
	h.createShipP();
	h.createShipP();
	h.createWeapon("1", "BoardL", weapon);
	h.createWeapon("1", "Bow", weapon);
	try
	{
		h.createWeapon("3", "BoardR", weapon);
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	try
	{
		h.buyWeapon("b", "BoardL", weapon);
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	std::cout << h;
	h.sellCon("b");
	std::cout << h;
	h.buyCon(1);
	h.destroyShipPir("1");
	try
	{
		h.sellWeapon("b", "Stern");
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	try
	{
		h.sellWeapon("a", "BoardL");
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	try
	{
		h.sellWeapon("b", "Stern");
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	try
	{
		h.loadShip("a", 10);
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	try
	{
		h.loadShip("b", 10);
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	try
	{
		h.loadShip("b", 1000);
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	try
	{
		h.unloadShip("a", 10);
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	try
	{
		h.unloadShip("b", 10);
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	h.buyWeapon("a","BoardL",weapon);
	h.buyCon(3);
	h.buyWeapon("c", "BoardL", weapon);
	std::cout << h;
	fs << h;
	fs.close();*/
	return 0;
}