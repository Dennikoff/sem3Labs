#include "MilitaryShip.h"
namespace MC {
	std::ostream& MilShip::print(std::ostream& c)
	{
		this->SupShip::print(c);
		c << "Battle Arming:" << std::endl << "Count: " << this->getNumber() << std::endl << std::endl;
		std::map<std::string, BatArm>::iterator it;
		for (it = this->getMap().begin(); it != this->getMap().end(); ++it)
		{
			c << it->first << ": " << std::endl << it->second << std::endl;
		}
		return c;
	}
}