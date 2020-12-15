#include "MilitaryShip.h"
namespace MC {
	std::ostream& MilShip::print(std::ostream& c)
	{
		this->DefShip::print(c);
		c << "Maxweight/weight = " << this->getMaxWeight() << "/" << this->getWeight() << std::endl;
		c << "Coefficient = " << this->getCoeff() << std::endl << std::endl;
		return c << std::endl;
	}
}