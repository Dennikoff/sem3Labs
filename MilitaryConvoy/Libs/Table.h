#pragma once
#include <string>
#include <iostream>
#include "Ship.h"
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
		Unit* tab;
	public:
		friend class TableIt;
		Ship& getShip(const std::string& name);
		int getSize() { return size; };
		Table& Insert(Ship&);
		Table& Delete(std::string name);
		typedef TableIt iterator;
	};
}