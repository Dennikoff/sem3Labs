#pragma once
#include <string>
#include <iostream>
#include "Ship.h"
#include <vector>
class TableIt;
namespace MC {
	struct Unit {
		std::string name;
		Ship ship;
		int x;
		int y;
	};

	class Table {
		static const int SZ = 10;
		int size;
		std::vector<Unit> tab;
	public:
		//friend class TableIt;
		Ship& getShip(const std::string& name);
		int getSize() { return size; };
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