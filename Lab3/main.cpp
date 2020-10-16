#include <iostream>
#include "../lib/Stack.h"
#include <string.h>
using namespace Stk;
int main()
{
	Massive g;
	g.key = 15;
	g.str[0] = '5';
	g.str[1] = '8';
	g.str[2] = '\0';
	char* s = new char[5];
	strcpy_s(s,5,"kekw\0");
	Stack a(5);
	Stack b(g, 10);
	Stack c;
	Stack d(s);
	try {
		std::cout << "c.getElems\n";
		try
		{
			c.getElems();
		}
		catch (const std::exception& er)
		{
			std::cout << er.what() << std::endl;
		}
		std::cout << "d.getElems\n";
		try
		{
			d.getElems();
		}
		catch (const std::exception& er)
		{
			std::cout << er.what() << std::endl;
		}
		std::cout << "a   : \n";
		try
		{
			a.getElems();
		}
		catch (const std::exception& er)
		{
			std::cout << er.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "b   : \n";
		try
		{
			b.getElems();
		}
		catch (const std::exception& er)
		{
			std::cout << er.what() << std::endl;
		}
		std::cout << "b.push(g)((g.key = 1000; g.str = \"79\"))  = ";
		g.key = 1000;
		g.str[0] = '7';
		g.str[1] = '9';
		try
		{
			b.push(g);
			b.getElems();
		}
		catch (const std::exception& er)
		{
			std::cout << er.what() << std::endl;
		}
		std::cout << "b.push(100)\n";
		try
		{
			b.push(100);
			b.getElem();
		}
		catch (const std::exception& er)
		{
			std::cout << er.what() << std::endl;
		}
		std::cout << "b.push(g,10)\n";
		try
		{
			for (int i = 0; i < 10; i++)
			{
				std::cout << "enter g.key\n";
				std::cin >> g.key;
				b.push(g);
			}
		}
		catch (const std::exception& er)
		{
			std::cout << er.what() << std::endl;
		}
		b.getElems();
		std::cout << std::endl;
		try
		{
			a.pop(g);
		}
		catch (const std::exception& er)
		{
			std::cout << er.what() << std::endl;
		}
		g.printKey();
		std::cout << "b.check()\n";
		b.check();
		std::cout << "a.check()\n";
		a.check();
		std::cout << "d.check()\n";
		d.check();
	}
	catch (...)
	{
		std::cout << "Something wrong" << std::endl;
	}
	return 0;
}
