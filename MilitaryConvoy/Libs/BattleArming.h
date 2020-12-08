#pragma once
#include <string>
#include <iostream>
namespace MC {
	class BatArm {
		std::string type;
		int damage;
		int ratefire;
		int range;
		int maxammo;
		int ammo;
		int price;
	public:
		BatArm(std::string type = "", int damage = 0, int ratefire = 0, int range = 0, int ammo = 0, int price = 0) :type(type), //пустой и от всех парамтеров
			damage(damage), ratefire(ratefire), range(range), maxammo(ammo), ammo(ammo), price(price) {};
		std::string getType() { return type; };
		int getDamage() { return damage; };
		int getRateFire() { return ratefire; };
		int getRange() { return range; };
		int getMaxAmmo() { return maxammo; };
		int getAmmo() { return ammo; };
		int getPrice() { return price; };
		BatArm& setType(std::string key);
		BatArm& setDamage(int key);
		BatArm& setRateFire(int key);
		BatArm& setRange(int key);
		BatArm& setMaxAmmo(int key);
		BatArm& setAmmo(int key);
		BatArm& setPrice(int key);
		int Atack();
		friend std::ostream& operator <<(std::ostream& c, BatArm a);
	};
}
