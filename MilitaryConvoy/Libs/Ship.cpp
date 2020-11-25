#include "Ship.h"
namespace MC{
	Ship& Ship::takeDamage(int k)
	{
		if (health - k > 0)
		{
			health -= k;
		}
		else
		{
			health = 0;
		}
		return *this;
	}
}