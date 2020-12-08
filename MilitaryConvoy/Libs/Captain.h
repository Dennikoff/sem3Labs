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
		Captain(std::string name = "", std::string surname = "", std::string fathername = "", int rank = 1)
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