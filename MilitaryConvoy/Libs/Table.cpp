#include "Table.h"
namespace MC {

	Ship& Table::getShip(const std::string& name)
	{
		for (int i = 0; i < size; ++i)
		{
			if (tab[i].name == name)
			{
				return tab[i].ship;
			}
		}
		Ship a("404");
		return a;
	}

	//Table& Table::Insert(Ship& ship) //не готово
	//{
	//	//Table::iterator it;
	//	
	//}

	//Table& Table::Delete(std::string name) //не готово
	//{
	//	Ship h = getShip(name);
	//	if (h.getType() == "404")
	//	{
	//		throw std::out_of_range("Ship not found");
	//	}
	//	else
	//	{
	//		
	//	}
	//	return;
	//}

}