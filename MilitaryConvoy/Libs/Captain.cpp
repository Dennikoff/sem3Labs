#include "Captain.h"
namespace MC {

	Captain& Captain::setRank(int key)
	{
		if (key > 0)
			rank = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Captain& Captain::setName(std::string key)
	{
		if (key != "")
			name = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;

	}

	Captain& Captain::setSurname(std::string key)
	{
		if (key != "")
			surname = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Captain& Captain::setFathername(std::string key)
	{
		if (key != "")
			fathername = key;
		else
			throw std::invalid_argument("Invalid argument");
		return *this;
	}

	Captain readFromFileCap(std::fstream& fs)
	{
		std::string str;
		std::getline(fs, str);
		Captain cap;
		cap.setSurname(str.substr(str.find(":") + 2, str.find("|") - str.find(":") - 2));
		str.erase(str.find(":"), 1);
		str.erase(str.find("|"), 1);
		cap.setName(str.substr(str.find(":") + 2, str.find("|") - str.find(":") - 2));
		str.erase(str.find(":"), 1);
		cap.setFathername(str.substr(str.find(":") + 2));
		std::getline(fs, str);
		cap.setRank(std::stoi(str.substr(str.find(":") + 2)));
		std::getline(fs, str);
		return cap;
	}

	std::ostream& operator <<(std::ostream& c, Captain cap)
	{
		c << "Surname: " << cap.surname << "|Name: " << cap.name << "|Fathername: " << cap.fathername << std::endl;
		c << "Rank: " << cap.rank << std::endl;
		return c << std::endl;
	}
}