#pragma once
#include <iostream>
#include <string>
namespace MC {
	class Captain {
		short rank;
		std::string name;
		std::string surname;
		std::string fathername;
	public:
		Captain(std::string name = "", std::string surname = "", std::string fathername = "", int rank = 1)
			:name(name), surname(surname), fathername(fathername), rank(rank) {};
		short getRank() { return rank; };

	};
}