#pragma once
#include <iostream>
#include "Table.h"
namespace MC {
	class Mission {
		Captain cap;
		Table Convoy_tab;
		Table Pirate_tab;
		long StartMoney;
		long MoneyLeft;
		long FullWeight;
		int MaxShip_Con;
		int MaxShip_Pir;
		std::pair<int, int> Coordinates_A;
		std::pair<int, int> Coordinates_B;
		std::pair<int, int> Coordinates_Pir;
		int time;
	public:
		Captain getCap() { return cap; };
		Table getTableC() { return Convoy_tab; };
		Table getTableR() { return Pirate_tab; };
		long getStartMoney() { return StartMoney; };
		long getMoneyLeft() { return MoneyLeft; };
		long getFullWeight() { return FullWeight; };
		int getMaxShip_Con() { return MaxShip_Con; };
		int	getMaxShip_Pir() { return MaxShip_Pir; };
		std::pair<int, int> getCoordA() { return Coordinates_A; };
		std::pair<int, int> getCoordB() { return Coordinates_B; };
		std::pair<int, int> getCoordPir() { return Coordinates_Pir; };
		Mission& setCap(Captain& key);
		Mission& setTableC(Table& key);
		Mission& setTableR(Table& key);
		Mission& setStartMoney(long& key);
		Mission& setMoneyLeft(long& key);
		Mission& setFullWeight(long& key);
		Mission& setMaxShip_Con(int& key);
		Mission& setMaxShip_Pir(int& key);
		Mission& setCoordA(std::pair<int, int>& key);
		Mission& setCoordB(std::pair<int, int>& key);
		Mission& setCoordPir(std::pair<int, int>& key);
	};
}