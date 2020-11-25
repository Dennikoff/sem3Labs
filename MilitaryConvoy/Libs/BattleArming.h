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
		BatArm(std::string type = "", int damage = 0, int ratefire = 0, int range = 0, int ammo = 0, int price = 0) :type(type),
			damage(damage), ratefire(ratefire), range(range), maxammo(ammo), ammo(ammo), price(price) {};
		std::string getType() { return type; };
		int getDamage() { return damage; };
		int getRateFire() { return ratefire; };
		int getRange() { return range; };
		int getMaxAmmo() { return maxammo; };
		int getAmmo() { return ammo; };
		int getPrice() { return price; };
		BatArm& setType(std::string key) { type = key;  return *this; };
		BatArm& setDamage(int key) { damage = key;  return *this; };
		BatArm& setRateFire(int key) { ratefire = key; return *this; };
		BatArm& setRange(int key) { range = key; return *this; };
		BatArm& setMaxAmmo(int key) { maxammo = key; return *this; };
		BatArm& setAmmo(int key) { ammo = key; return *this; };
		BatArm& setPrice(int key) { price = key; return *this; };
		int Atack();
	};
}
