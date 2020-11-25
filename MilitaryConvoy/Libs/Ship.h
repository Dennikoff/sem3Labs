#pragma once 
#include "Captain.h"
#include <iostream>
namespace MC {
	class Ship {
		std::string type;
		std::string name;
		Captain cap;
		double maxspeed;
		double speed;
		int maxhealth;
		int health;
		int price;
	public:
		Ship(std::string type = "", std::string name = "", Captain cap = Captain(), int speed = 0, int health = 0, int price = 0)
			:type(type), name(name), cap(cap), maxspeed(speed), speed(speed), maxhealth(health), health(health), price(price) {};
		std::string getType() { return type; };
		std::string getName() { return name; };
		double getMaxSpeed() { return maxspeed; };
		double getSpeed() { return speed; };
		int getMaxHealth() { return maxhealth; };
		int getHealth() { return health; };
		int getPrice() { return price; };
		Ship& setType(std::string key) { type = key;  return *this; };
		Ship& setName(std::string key) { name = key;  return *this; };
		Ship& setMaxSpeed(double key) { maxspeed = key; return *this; };
		Ship& setSpeed(double key) { speed = key; return *this; };
		Ship& setMaxHealth(int key) { maxhealth = key; return *this; };
		Ship& setHealth(int key) { health = key; return *this; };
		Ship& setPrice(int key) { price = key; return *this; };
		Ship& takeDamage(int);
	};
}