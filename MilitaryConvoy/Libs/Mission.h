#pragma once
#include <iostream>
#include "Table.h"
namespace MC {
	class Mission {
		Captain cap;
		Table tabC;
		Table tabP;
		long StartMoney;
		long MoneyLeft;
		long FullWeight;
		int MaxShipCon;
		int MaxShipPir;
		std::pair<int, int> Coordinates_A;
		std::pair<int, int> Coordinates_B;
		std::pair<int, int> Coordinates_Pir;
		int time;
	public:
		Mission(Captain cap, long StartMoney, long MoneyL, long FullW, int MaxC, int MaxP, int time) :
			cap(cap), StartMoney(StartMoney), MoneyLeft(MoneyL), FullWeight(FullW), MaxShipCon(MaxC), MaxShipPir(MaxP), time(time)  {};
		Captain& getCap() { return cap; };
		Table& getTableC() { return tabC; };
		Table& getTableP() { return tabP; };
		long getStartMoney() { return StartMoney; };
		long getMoneyLeft() { return MoneyLeft; };
		long getFullWeight() { return FullWeight; };
		int getMaxShip_Con() { return MaxShipCon; };
		int	getMaxShip_Pir() { return MaxShipPir; };
		std::pair<int, int> getCoordA() { return Coordinates_A; };
		std::pair<int, int> getCoordB() { return Coordinates_B; };
		std::pair<int, int> getCoordPir() { return Coordinates_Pir; };
		Mission& setCap(Captain& key);
		Mission& setTableC(Table& key);
		Mission& setTableP(Table& key);
		Mission& setStartMoney(long& key);
		Mission& setMoneyLeft(long& key);
		Mission& setFullWeight(long& key);
		Mission& setMaxShipCon(int& key);
		Mission& setMaxShipPir(int& key);
		Mission& setCoordA(std::pair<int, int>& key);
		Mission& setCoordB(std::pair<int, int>& key);
		Mission& setCoordPir(std::pair<int, int>& key);
		Ship* getShipCon(const std::string& name);
		Ship* getShipPir(const std::string& name);
		Mission& createShipP(Ship* a);
		Mission& buyCon(const int& );
		Mission& sellCon(std::string);
		Mission& buyWepon(const std::string& name, const std::string& place, BatArm& weapon);
		Mission& sellWeapon(const std::string& name, const std::string& place);
		Mission& destroyShipCon(const std::string& name);
		Mission& destroyShipPir(const std::string& name);
		Mission& loadShip(const std::string& name, int count);
		Mission& unloadShip(const std::string& name, int count);
		Mission& autoLoad();
	};
	std::map < std::string, BatArm> CreateEmptyMap();
}