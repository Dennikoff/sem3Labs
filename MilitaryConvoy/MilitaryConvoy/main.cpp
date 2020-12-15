#include "../Libs/Mission.h"
#include <iostream>
using namespace MC;
int main()
{
	Ship* def = new DefShip("Type", "name", Captain(), 10, 100, 15);
	std::cout << def;
	Ship* sup = new SupShip();
	std::cout << sup;
	return 0;
}