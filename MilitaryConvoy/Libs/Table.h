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