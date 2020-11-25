#include "DefendShip.h"
namespace MC {
	DefShip& DefShip::Modify(std::map<std::string, BatArm> map)
	{
		if (map.size())
		{
			this->mp = map;
		}
		else
		{
			int a = 1;
			while (a)
			{
				std::cout << "Enter pllace:\n0)To Exit\n1)Bow\n2)Board Right\n3)Board Left\n4)Sterm\n>>>";
				std::cin >> a;
				if (!a) exit;
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
					mp.emplace("Sterm", weapon);
					break;
				default:
					break;
				}
			}
		}
		return *this;
	}
	
	int DefShip::Shot(int x, int y)
	{
		
	}
}