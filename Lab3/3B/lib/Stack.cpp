#include <iostream>
#include <string.h>
#include "../lib/Stack.h";

namespace Stk {   
	std::istream& operator >>(std::istream& c, Massive& a)
	{
		std::cout << "Enter your key" << std::endl;
		c >> a.key;
		char s[SIZES*10];
		std::cout << "Enter your string" << std::endl;
		c >> s;
		for (int i = 0; i < SIZES; i++)
		{
			a.str[i] = s[i];
		}
		if (strlen(a.str) < SIZES)
			a.str[strlen(a.str)] = '\0';
		else
			a.str[SIZES-1] = '\0';
		return c;
	}

	void getInt(int& n)
	{
		std::cin >> n;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	/*Massive& Massive::getElem(std::istream& c) 
	{
		std::cout << "Enter your key" << std::endl;
		c >> this->key;
		char s[255];
		std::cout << "Enter your string" << std::endl;
		c >> s;
		for (int i = 0; i < SIZES; i++)
		{
			str[i] = s[i];
		}
		if (strlen(str) < SIZES)
			str[strlen(str)] = '\0';
		else
			str[SIZES-1] = '\0';
		return *this;
	}*/

	std::istream& operator >>(std::istream& c, Stack& a)
	{
		Massive elem;
		c >> elem;
		if (a.top > SIZE-1)
			throw std::exception("Stack overflow");
		a += elem;
		return c;
	}

	std::ostream& operator <<(std::ostream& c, Stack& a)
	{
		if (a.top == 0)
			throw std::exception("Stack is empty");
		int g = a.top;
		while (--g >= 0)
		{
			Massive elem;
			elem = a.mas[g];
			c << elem;
		}
		return c;
	}
	
	Stack::Stack(Massive elem, int k)
	{
		top = 0;
		for (int i = 0; i < k; i++)
		{
			if (top > SIZE)
				throw std::exception("Stack overflow");
			mas[top++] = elem;
		}
	}

	Stack& Stack::operator+=(Massive& elem)
	{
		if (top > SIZE - 1)
			throw std::exception("Stack overflow.");
		mas[top++] = elem;
		return *this;
	}

	void Stack::PrintFirst() const
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		Massive h = mas[top - 1];
		std::cout << h;
	}

	Stack& Stack:: operator()(Massive& elem)
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		elem = mas[--top];
		return *this;
	}

	int  Stack::check() const
	{
		if (top > SIZE - 1)
			return -1;     //��������
		else
			if (top > 0)
				return 0;    //�������� ��������
			else
				return 1;    //����
	}
}
