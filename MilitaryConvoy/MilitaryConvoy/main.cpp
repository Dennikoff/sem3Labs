#include "../Libs/Mission.h"
int a = 2;
int& f(int x)
{
	return a += x;
}
int main()
{
	std::cout << f(2) << " | a = " << a << std::endl;
	f(1) = 10;
	std::cout << "a = " << a << std::endl;
}