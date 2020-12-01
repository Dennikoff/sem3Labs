#pragma once
#include <string>
#include <iostream>
#include "MilitaryShiph.h"
#include <vector>
class TableIt;
namespace MC {
	struct Unit {
		std::string name;
		Ship ship;
		std::pair<int, int> coordinates;
	};

	class Table {
		/*static const int SZ = 10;
		int size;*/
		//std::vector<Unit> tab;
	public:
		std::vector<Unit> tab;
		std::vector<Unit>::iterator getShip(const std::string& name);
		//friend class TableIt;
		//Ship& getShip(const std::string& name);
		//int getSize() { return size; };
		/*Table& Insert(Ship&);
		Table& Delete(std::string name);
		typedef TableIt iterator;*/
	};

	/*class TableIt
	{
		Unit* cuv;
		Unit cur;
	};*/
}