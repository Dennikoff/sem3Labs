#include <iostream>
#include "../lib/Stack.h"
#include <string.h>
using namespace Stk;

int main()
{
		Stack j;
		std::cout << "Creation of the Stack:\n Enter number of par:";
		int h;
		getInt(h);
		Massive* mas = new Massive[h];
		for (int i = 0; i < h; i++)
		{
			std::cin >> mas[i];
		}
		Stack c(mas, h);
		while (true)
		{
			std::cout << "What do you want to do?" << std::endl;
			std::cout << "0)Exit\n1)Push n elements\n2)Pop n elements\n3)Print your Stack\n4)Show the first element\n5)Check the status\n" << std::endl;
			int q;
			getInt(q);
			switch (q)
			{
			case 1:
				std::cout << "Enter n\n";
				int n;
				getInt(n);
				try
				{
					for (int i = 0; i < n; i++)
					{
						std::cin >> c;
					}
				}
				catch (const std::exception& er)
				{
					std::cout << std::endl << er.what() << std::endl << std::endl;
				}
				break;
			case 2:
				std::cout << "Enter n\n";
				getInt(n);
				try
				{
					for (int i = 0; i < n; i++)
					{
						Massive g;
						c(g);
						std::cout << g;
					}
					std::cout << std::endl;
				}
				catch (const std::exception& er)
				{
					std::cout << std::endl << er.what() << std::endl << std::endl;
				}
				break;
			case 3:
				try
				{
					std::cout << "\nYour Stack: \n";
					Stack a(c);
					std::cout << a << std::endl;
					std::cout << std::endl;
				}
				catch (const std::exception& er)
				{
					std::cout << std::endl << er.what() << std::endl << std::endl;
				}
				break;
			case 4:
				try
				{
					std::cout << "\nYour elem: ";
					c.PrintFirst(std::cout);
					std::cout << std::endl;
				}
				catch (const std::exception& er)
				{
					std::cout << std::endl << er.what() << std::endl << std::endl;
				}
				break;
			case 5:
				//int k = 1;
				int const k = c.check();
				switch (k)
				{
				case -1:
					std::cout << "\nStack is full\n\n";
					break;
				case 0:
					std::cout << "\nStack is particaly filled\n\n";
					break;
				case 1:
					std::cout << "\nStack is empty\n\n";
					break;
				}
				break;
			}
			if (q == 0) break;
		}
	return 0;
}


