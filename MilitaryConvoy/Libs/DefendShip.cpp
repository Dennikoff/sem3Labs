#include "DefendShip.h"
namespace MC {
	DefShip& DefShip::Modify(const std::string& place, const BatArm& weapon)
	{
		
			/*std::cout << "Enter pllace:\n0)To Exit\n1)Bow\n2)Board Right\n3)Board Left\n4)Stern\n>>>";
			std::cin >> a;
			if (!a) return *this;
			int ammo, damage, price, range, ratefire;
			std::string type;
			std::cout << "Enter Stats\n Type->";
			std::cin >> type;
			std::cout << "Ammo->";
			std::cin >> ammo;
			std::cout << "Damage->";
			std::cin >> damage;
			std::cout << "Price->";
			std::cin >> price;
			std::cout << "range->";
			std::cin >> range;
			std::cout << "Ratefire->";
			std::cin >> ratefire;
			BatArm weapon(type, damage, ratefire, range, ammo, price);
			switch (a)
			{
			case 1:
				mp.emplace("Bow", weapon);
				break;
			case 2:
				mp.emplace("BoardR", weapon);
				break;
			case 3:
				mp.emplace("BoardL", weapon);
				break;
			case 4:
				mp.emplace("Stern", weapon);
				break;
			default:
				break;
			}*/
		mp[place] = weapon;
		number++;
		return *this;
	}

	DefShip& DefShip::AddWeapon(const std::string& place, const BatArm& weapon)
	{
		mp[place] = weapon;
		return *this;
	}
	int DefShip::setNumber(const int& key)
	{
		if (key >= 0)
			number = key;
		else
			throw std::invalid_argument("Incorrect number");
	}

	int DefShip::Shot(int x, int y)
	{
		return 0;
	}

	std::ostream& DefShip::print(std::ostream& c)
	{
		c << "Type: " << this->getType() << std::endl;
		c << "Name: " << this->getName() << std::endl;
		c << "Captain -> " << this->getCaptain();
		c << "Maxhealth/health: " << this->getMaxHealth() << "/" << this->getHealth() << std::endl;
		c << "Maxspeed/speed: " << this->getMaxSpeed() << "/" << this->getSpeed() << std::endl;
		c << "Price: " << this->getPrice() << std::endl << std::endl;
		c << "Battle Arming:" << std::endl << "Count: " << number << std::endl << std::endl;
		std::map<std::string, BatArm>::iterator it;
		for (it = this->mp.begin(); it != this->mp.end(); ++it)
		{
			c << it->first << ": " << std::endl << it->second << std::endl;
		}
		return c;
	}
}