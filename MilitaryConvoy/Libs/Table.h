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
		typedef TableIt iterator;
	};
}