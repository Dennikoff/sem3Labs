#include "../Libs/Mission.h"
#include <iostream>
using namespace MC;
int main()
{
	Ship* def = new DefShip("Type", "name", Captain(), 10, 100, 15);
	std::cout << def;
	Ship* sup = new SupShip();
	std::cout << sup;
	Mission h;
	h.setCoordA(std::make_pair(10,0));
	h.setCoordB(std::make_pair(100,0));
	h.setCoordPir(std::make_pair(10,10));
	BatArm weapon("Mashine gun",200,14,50,30,200);
	h.buyCon(2);
	h.buyCon(1);
	h.buyWepon("a", "Stern", weapon);
	h.createShipP();
	h.createShipP();
	std::cout << h;
	return 0;
}