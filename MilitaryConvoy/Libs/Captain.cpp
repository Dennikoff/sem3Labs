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

}