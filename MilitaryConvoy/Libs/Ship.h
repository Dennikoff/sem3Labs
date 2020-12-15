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
		Ship() :type("LichKing"), name("Warcraft"), cap(Captain()), maxspeed(15), speed(15), maxhealth(100), health(100), price(300) {}
		Ship(std::string type) : Ship() { Ship::type = type; };
		Ship(std::string type , std::string name, Captain cap, double speed, int health, int price)
			:type(type), name(name), cap(cap), maxspeed(speed), speed(speed), maxhealth(health), health(health), price(price) {};
		std::string getType() const { return type; };
		std::string getName() const { return name; };
		Captain getCaptain() const { return cap; };
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
		virtual std::ostream& print(std::ostream& c) = 0;
		friend std::ostream& operator <<(std::ostream& c, Ship* sh)
		{
			sh->print(c);
			return c;
		} 
		/*virtual ~Ship() {};*/
	};
}