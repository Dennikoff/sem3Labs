#pragma once
#include <string>
#include <iostream>
#include "MilitaryShip.h"
#include <vector>
class TableIt;
namespace MC {
	struct Unit {
		std::string name;
		Ship* ship;
		std::pair<int, int> coordinates;
		Unit()  {};
		/*Unit(Unit& a): name(a.name), coordinates(a.coordinates)
		{
			if(typeid(*(a.ship)) == typeid(SupShip))
			{
				SupShip* cur = dynamic_cast<SupShip*>(a.ship);
				ship = new SupShip(*cur);
			}
			else if (typeid(*(a.ship)) == typeid(DefShip))
			{
				DefShip* cur = dynamic_cast<DefShip*>(a.ship);
				ship = new DefShip(*cur);
			}
				else if (typeid(*(a.ship)) == typeid(MilShip))
				{
					MilShip* cur = dynamic_cast<MilShip*>(a.ship);
					ship = new MilShip(*cur);
				}
			
		}*/
		~Unit() { 
			//delete ship; 
		}
	};
	class Table {
		friend class TableIt;
		std::vector<Unit> tab;
	public:
		std::vector<Unit>::iterator getShip(const std::string& name);
		typedef TableIt iterator;
		std::vector<Unit>::iterator begin();
		std::vector<Unit>::iterator end();
		int size() { return tab.size(); }
		//std::vector<Unit>::iterator find(std::string name);
		//int getSize() { return size; };
		Table& push_back(Unit& );
		Table& erase(const std::string& name);
		Unit& back() { return tab.back(); }
	};

	class TableIt
	{
		Unit* cur;
	public:
		TableIt() :cur(0) {}
	};
}