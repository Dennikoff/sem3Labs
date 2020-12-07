#pragma once
#include <iostream>
#include "Table.h"
namespace MC {
	class Mission {
		Captain cap;
		std::vector<Unit> tabC;
		std::vector<Unit> tabP; ////
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
		std::vector<Unit> getTableC() { return tabC; };
		std::vector<Unit> getTableP() { return tabP; };
		long getStartMoney() { return StartMoney; };
		long getMoneyLeft() { return MoneyLeft; };
		long getFullWeight() { return FullWeight; };
		int getMaxShip_Con() { return MaxShip_Con; };
		int	getMaxShip_Pir() { return MaxShip_Pir; };
		std::pair<int, int> getCoordA() { return Coordinates_A; };
		std::pair<int, int> getCoordB() { return Coordinates_B; };
		std::pair<int, int> getCoordPir() { return Coordinates_Pir; };
		Mission& setCap(Captain& key);
		Mission& setTableC(std::vector<Unit>& key);
		Mission& setTableP(std::vector<Unit>& key);
		Mission& setStartMoney(long& key);
		Mission& setMoneyLeft(long& key);
		Mission& setFullWeight(long& key);
		Mission& setMaxShip_Con(int& key);
		Mission& setMaxShip_Pir(int& key);
		Mission& setCoordA(std::pair<int, int>& key);
		Mission& setCoordB(std::pair<int, int>& key);
		Mission& setCoordPir(std::pair<int, int>& key);
		Ship* getShipCon(std::string name);
		//Ship& setShipCon(std::string name);
		Ship* getShipPir(std::string name);
		//Ship& setShipPir(std::string name);
		Unit createShipC();
		Unit createShipP();
		Mission& buyCon();
		Mission& sellCon(std::string);
		Mission& buyPir();
		Mission& sellPir();
		Mission& buyWepon(std::string name);
		Mission& sellWeapon();
		Mission& destroyShipCon(std::string name);
		Mission& destroyShipPir();
		Mission& loadShip();
		Mission& unloadShip();
		Mission& autoLoad();
	};
}