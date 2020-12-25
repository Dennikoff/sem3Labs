#include "../Libs/Mission.h"
#include <iostream>
using namespace MC;
int main()
{
	Mission mis;
	std::cout << "Welcome to the Military Convoy!\n";
	std::cout << "If you want to create new Mission, enter 1;\nIf you want to create your Mission from file, enter 2.\n";
	int ch;
	std::cin >> ch;
	while (ch != 1 && ch != 2)
	{
		std::cin.clear();
		std::cout << "Please, enter 1 or 2\n";
		std::cin >> ch;
	}
	ch--;
	if (ch)
	{
		std::string name;
		std::cout << "Please, enter name of the file:\n";
		std::cin >> name;
		try
		{
			mis = readFromFileMis(name);
		}
		catch (const std::exception& er)
		{
			std::cout << er.what() << std::endl;
		}
	}
	int choice = 1;
	std::cout << "Here some option for you:\n0)Exit\n1)Add new con ship\n2)Add new weapon to con ship\n3)Create Pir ship\n4)Add new weapon to pir ship\n5)Print your mission\n6)A ship atack B ship\n7)Sell ship con\n8)Sell weapon con\n9)Destroy Ship con\n10)Load ship\n11)Unload Ship\n";
	while (choice)
	{
		std::cout << "What do you want to do?\n";
		std::cin >> choice;
		switch (choice){
		case 1:
		{
			std::cout << "What type of ship do you want to add:\n1)Supply Ship\n2)Defend Ship\n3)Military Ship\n>>>";
			std::cin >> ch;
			mis.buyCon(ch);
			break;
		}
		case 2:
		{
			std::cout << "Enter place:\n0)To Exit\n1)Bow\n2)Board Right\n3)Board Left\n4)Stern\n>>>";
			std::cin >> ch;
			if (!ch) break;
			int ammo, damage, price, range, ratefire;
			std::string place, type;
			switch (ch)
			{
			case 1:
				place = "Bow";
				break;
			case 2:
				place = "BoardR";
				break;
			case 3:
				place = "BoardL";
				break;
			case 4:
				place = "Stern";
				break;
			default:
				break;
			}
			std::string name;
			std::cout << "Enter name of the ship:\n";
			std::cin >> name;
			std::cout << "Enter Stats\n Type->";
			std::cin >> type;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ammo->";
			std::cin >> ammo;
			std::cout << "Damage->";
			std::cin >> damage;
			std::cout << "range->";
			std::cin >> range;
			std::cout << "Ratefire->";
			std::cin >> ratefire;
			price = (ammo + damage + range + ratefire) / 10;
			BatArm weapon(type, damage, ratefire, range, ammo, price);
			try
			{
				mis.buyWeapon(name, place, weapon);
			}
			catch (const std::exception& er)
			{
				std::cout << er.what() << std::endl;
			}
			break;
		}
		case 3:
		{
			mis.createShipP();
			break;
		}
		case 4:
		{
			int ammo, damage, price, range, ratefire;
			std::string place, type;
			std::cout << "Enter place:\n0)To Exit\n1)Bow\n2)Board Right\n3)Board Left\n4)Stern\n>>>";
			std::cin >> ch;
			switch (ch)
			{
			case 1:
				place = "Bow";
				break;
			case 2:
				place = "BoardR";
				break;
			case 3:
				place = "BoardL";
				break;
			case 4:
				place = "Stern";
				break;
			default:
				break;
			}
			std::string name;
			std::cout << "Enter name of the ship:\n";
			std::cin >> name;
			std::cout << "Enter Stats\n Type->";
			std::cin >> type;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ammo->";
			std::cin >> ammo;
			std::cout << "Damage->";
			std::cin >> damage;
			std::cout << "range->";
			std::cin >> range;
			std::cout << "Ratefire->";
			std::cin >> ratefire;
			price = (ammo + damage + range + ratefire) / 10;
			BatArm weapon(type, damage, ratefire, range, ammo, price);
			try
			{
				mis.createWeapon(name, place, weapon);
			}
			catch (const std::exception& er)
			{
				std::cout << er.what() << std::endl;
			}
			break;
		}
		case 5:
		{
			std::cout << mis;
			break;
		}
		case 6:
		{
			std::cout << "Enter name of the ships A and B";
			std::string A, B;
			std::cin >> A, B;
			DefShip* def = dynamic_cast<DefShip*>(mis.getShipCon(A));
			Ship* sh = mis.getShipPir(B);
			if (def)
			{
				sh->takeDamage(def->getMap()["Bow"].Atack());
			}
			else
				std::cout << "Ship has incorrect type";
			break;
		}
		case 7:
		{
			std::string name;
			std::cout << "Enter name of the ship:\n";
			std::cin >> name;
			mis.sellCon(name);
			break;
		}
		case 8:
		{
			std::string name;
			std::string place;
			std::cout << "Enter name of the ship:\n";
			std::cin >> name;
			std::cout << "Enter place:\n0)To Exit\n1)Bow\n2)Board Right\n3)Board Left\n4)Stern\n>>>";
			std::cin >> ch;
			switch (ch)
			{
			case 1:
				place = "Bow";
				break;
			case 2:
				place = "BoardR";
				break;
			case 3:
				place = "BoardL";
				break;
			case 4:
				place = "Stern";
				break;
			default:
				break;
			}
			try
			{
				mis.sellWeapon(name, place);
			}
			catch (const std::exception& er)
			{
				std::cout << er.what() << std::endl;
			}
		}
		case 9:
		{
			std::string name;
			std::cout << "Enter name of the ship:\n";
			std::cin >> name;
			try
			{
				mis.destroyShipCon(name);
			}
			catch (const std::exception& er)
			{
				std::cout << er.what() << std::endl;
			}
			break;
		}
		case 10:
		{
			std::string name;
			std::cout << "Enter name of the ship:\n";
			std::cin >> name;
			std::cout << "Enter weigth\n";
			int weight;
			std::cin >> weight;
			try
			{
				mis.loadShip(name, weight);
			}
			catch (const std::exception& er)
			{
				std::cout << er.what() << std::endl;
			}
			break;
		}
		case 11:
		{
			std::string name;
			std::cout << "Enter name of the ship:\n";
			std::cin >> name;
			std::cout << "Enter weigth\n";
			int weight;
			std::cin >> weight;
			try
			{
				mis.unloadShip(name, weight);
			}
			catch (const std::exception& er)
			{
				std::cout << er.what() << std::endl;
			}
			break;
		}
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "Do you want to save your mission in file? 1 - no; 2 - yes;\n";
	std::cin >> ch;
	if (ch - 1)
	{
		std::string name;
		std::cout << "Enter name of the file\n";
		std::cin >> name;
		mis.writeToFile(name);
	}
	return 0;
}