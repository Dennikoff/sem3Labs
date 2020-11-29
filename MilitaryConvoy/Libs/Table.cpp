#include "Table.h"
namespace MC {
	
	std::vector<Unit>::iterator Table::getShip(const std::string& name)
	{
		std::vector<Unit>::iterator it;
		for (it = tab.begin(); it != tab.end(); ++it)
		{
			if (it->name == name)
			{
				break;
			}
		}
		return it;
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