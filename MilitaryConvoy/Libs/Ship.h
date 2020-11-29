#pragma once 
#include "Captain.h"
#include <iostream>
namespace MC {
	class Ship {
		static Ship DefaultShip;
		std::string type;
		std::string name;
		Captain cap;
		double maxspeed;
		double speed;
		int maxhealth;
		int health;
		int price;
	public:
		Ship() :type(DefaultShip.type), name(DefaultShip.name), cap(DefaultShip.cap), maxspeed(DefaultShip.speed), speed(DefaultShip.speed), maxhealth(DefaultShip.health), health(DefaultShip.health), price(DefaultShip.price) {}
		Ship(std::string type , std::string name, Captain cap, int speed, int health, int price)
			:type(type), name(name), cap(cap), maxspeed(speed), speed(speed), maxhealth(health), health(health), price(price) {};
		static void setDefaultShip(std::string type, std::string name, Captain cap, int speed, int health, int price)
		{
			DefaultShip.type = type; DefaultShip.name = name; DefaultShip.cap = cap; DefaultShip.maxspeed = speed; DefaultShip.speed = speed; DefaultShip.maxhealth = health; DefaultShip.health = health; DefaultShip.price = price;
		};
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