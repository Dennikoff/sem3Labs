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
		long WeightLeft;
		long DelWeight;
		long LostWeight;
		int MaxShipCon;
		int MaxShipPir;
		std::pair<int, int> Coordinates_A;
		std::pair<int, int> Coordinates_B;
		std::pair<int, int> Coordinates_Pir;
		int time;
		Mission& addShip();
	public:
		Mission() : cap(Captain()), StartMoney(2000), MoneyLeft(2000), FullWeight(100), WeightLeft(100),  DelWeight(0), LostWeight(0), MaxShipCon(5), MaxShipPir(6), time(8) {};
		Mission(Captain cap, long StartMoney, long FullW, int MaxC, int MaxP, int time):
			cap(cap), StartMoney(StartMoney), MoneyLeft(StartMoney), FullWeight(FullW), WeightLeft(100), DelWeight(0), LostWeight(0), MaxShipCon(MaxC), MaxShipPir(MaxP), time(time) {};
		Captain& getCap() { return cap; };
		Table& getTableC() { return tabC; };
		Table& getTableP() { return tabP; };
		long getStartMoney() { return StartMoney; };
		long getMoneyLeft() { return MoneyLeft; };
		long getFullWeight() { return FullWeight; };
		long getWeigthLeft() { return WeightLeft; };
		long getDelWeigth() { return DelWeight; };
		long getLostWeigth() { return LostWeight; }
		int getMaxShip_Con() { return MaxShipCon; };
		int	getMaxShip_Pir() { return MaxShipPir; };
		std::pair<int, int> getCoordA() { return Coordinates_A; };
		std::pair<int, int> getCoordB() { return Coordinates_B; };
		std::pair<int, int> getCoordPir() { return Coordinates_Pir; };
		Mission& setCap(const Captain& key);
		Mission& setTableC(const Table& key);
		Mission& setTableP(const Table& key);
		Mission& setStartMoney(const long& key);
		Mission& setMoneyLeft(const long& key);
		Mission& setFullWeight(const long& key);
		Mission& setWeightLeft(const long& key);
		Mission& setDelWeight(const long& key);
		Mission& setLostWeight(const long& key);
		Mission& setMaxShipCon(const int& key);
		Mission& setMaxShipPir(const int& key);
		Mission& setTime(const int& key);
		Mission& setCoordA(const std::pair<int, int>& key);
		Mission& setCoordB(const std::pair<int, int>& key);
		Mission& setCoordPir(const std::pair<int, int>& key);
		Ship* getShipCon(const std::string& name);
		Ship* getShipPir(const std::string& name);
		Mission& addShipCon(Unit un);
		Mission& addShipPir(Unit un);
		Mission& createShipP();
		Mission& buyCon(const int& choice);
		Mission& sellCon(std::string);
		Mission& buyWeapon(const std::string& name, const std::string& place, BatArm& weapon);
		Mission& createWeapon(const std::string& name, const std::string& place, BatArm& weapon);
		Mission& sellWeapon(const std::string& name, const std::string& place);
		Mission& destroyShipCon(const std::string& name);
		Mission& destroyShipPir(const std::string& name);
		Mission& loadShip(const std::string& name, int count);
		Mission& unloadShip(const std::string& name, int count);
		Mission& autoLoad();
		friend std::ostream& operator <<(std::ostream& c, Mission& a);
	};
	Mission readFromFileMis(std::fstream&);
	std::map < std::string, BatArm> CreateEmptyMap();
}