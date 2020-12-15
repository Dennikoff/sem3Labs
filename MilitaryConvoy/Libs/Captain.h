#pragma once
#include <iostream>
#include <string>
namespace MC {
	class Captain {
		int rank;
		std::string name;
		std::string surname;
		std::string fathername;
	public:
		Captain() : name("Ivan"), surname("Ivanov"), fathername("Ivanovich"), rank(1) {};
		Captain(std::string name , std::string surname , std::string fathername , int rank ) //stl
			:name(name), surname(surname), fathername(fathername), rank(rank) {};
		int getRank() { return rank; };
		std::string getName() { return name; };
		std::string getSurname() { return surname; };
		std::string getFathername() { return fathername; };
		Captain& setRank(int key);
		Captain& setName(std::string);
		Captain& setSurname(std::string);
		Captain& setFathername(std::string);
		friend std::ostream& operator <<(std::ostream& c, Captain cap);
	};
}