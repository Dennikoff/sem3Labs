#pragma once
#include <iostream>
#include "Table.h"
namespace MC {
	class Mission {
		Captain cap;
		Table Convoy_tab;
		Table Pirate_tab;
		int StartMoney;
		int MoneyLeft;
		int FullWeight;
		int MaxShip_Con;
		int MaxShip_Pir;
		std::pair<int, int> Coordinates_A;
		std::pair<int, int> Coordinates_B;
		std::pair<int, int> Coordinates_Pir;
		int time;


	};
}