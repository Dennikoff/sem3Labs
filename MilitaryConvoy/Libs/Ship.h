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
		std::string getType() const { return type; };
		std::string getName() const { return name; };
		double getMaxSpeed() const { return maxspeed; };
		double getSpeed() const { return speed; };
		int getMaxHealth() const { return maxhealth; };
		int getHealth() const { return health; };
		int getPrice() const { return price; };
		Ship& setType(std::string key);
		Ship& setName(std::string key);
		Ship& setMaxSpeed(double key);
		Ship& setSpeed(double key);
		Ship& setMaxHealth(int key);
		Ship& setHealth(int key);
		Ship& setPrice(int key);
		Ship& takeDamage(int);
	};
}