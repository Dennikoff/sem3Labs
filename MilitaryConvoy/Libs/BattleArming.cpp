#include "BattleArming.h"
namespace MC {
	int BatArm::Atack() {
		if(ammo)
		{
			ammo--;
			return damage;
		}
		return 0;
	}
}