#include "Table.h"
namespace MC {
	std::vector<Unit>::iterator Table::getShip(const std::string& name)
	{
		auto it = this->begin();
		for (it = this->begin(); it != this->end(); ++it)
		{
			if (it->name == name)
			{
				break;
			}
		}
		return it;
		
	}

	std::vector<Unit>::iterator Table::begin()
	{
		return tab.begin();
	}

	std::vector<Unit>::iterator Table::end()
	{
		return tab.end();
	}

	
	/*std::vector<Unit>::iterator Table::find()
	{
		return  ;
	}*/

	Table& Table::push_back(Unit& un)
	{
		tab.push_back(un);
		return *this;
	}

	Table& Table::erase(const std::string& name) //не готово
	{
		auto it = getShip(name);
		if (it != tab.end())
			tab.erase(it);
		else
			throw std::out_of_range("Element not found");
		return *this;

	}

}