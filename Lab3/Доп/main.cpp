#include "BigInt.h"
#include <iostream>
#include <string.h>
using namespace Prog3b;
int main()
{
	std::cout << "Welcome to program \"Calculator\"\n";
	int q = 1;
	BigInt number;
	while (q)
	{
		std::cout << "0) Press for exit\n1) Press to set your number\n2) Print your number\n3)X+Y\n4)X-Y\n5)X*10^n\n6)X/10^n\n7)(-1)*X\n\n";
		std::cin >> q;
		std::cout << "\n";
		switch (q)
		{
		case 1:
		{
			char str[50];
			std::cout << "Enter your number:";
			std::cin >> str;
			try
			{
				number.Set(str);
			}
			catch (const std::exception& er)
			{
				std::cout << er.what() << std::endl;
			}
			std::cout << "\n";
		}
			break;
		case 2:
			std::cout << "Your number:" << number << std::endl;
			std::cout << "\n";
			break;
		case 3:
		{
			std::cout << "Enter your Y number\n";
			char str[50];
			std::cin >> str;
			BigInt y(str);
			number = number + y;
			std::cout << "Your result number is:" << number << std::endl;
			std::cout << "\n";
		}
			break;
		case 4: 
		{	
			std::cout << "Enter Y\n";
			char str[50];
			std::cin >> str;
			BigInt y(str);
			number = number - y;
			std::cout << "Your result number is:" << number << std::endl;
			std::cout << "\n";
		}
			break;
		case 5: 
		{
			std::cout << "Enter n\n";
			int n;
			std::cin >> n;
			try
			{
				number <<= n;
			}
			catch (const std::exception& er)
			{
				std::cout << er.what() << std::endl;
			}
			std::cout << "Your result number is:" << number << std::endl;
			std::cout << "\n";
		}
			break;
		case 6:
		{
			std::cout << "Enter n\n";
			int n;
			std::cin >> n;
			try
			{
				number >>= n;
			}
			catch (const std::exception& er)
			{
				std::cout << er.what() << std::endl;
			}
			std::cout << "Your result number is:" << number << std::endl;
			std::cout << "\n";
		}
			break;
		case 7:
		{
			number = -number;
			std::cout << "Your result number is:" << number << std::endl;
			std::cout << "\n";
		}
			break;
		}
	}
	return 0;
}