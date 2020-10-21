#include <iostream>
#include <string.h>
#include "../lib/Stack.h";

namespace Stk {
	//template<class T>
	void getInt(int& n)
	{
		std::cin >> n;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	Massive& Massive::getElem(std::istream& c) 
	{
		std::cout << "Enter your key" << std::endl;
		c >> this->key;
		std::cout << "Enter your string" << std::endl;
		c >> str;
		if (strlen(str) < 20)
			str[strlen(str)] = '\0';
		else
			str[19] = '\0';
		return *this;
	}

	/*std::istream& operator >>(std::istream& c, Stack& a)
	{
		Massive elem;
		elem.getElem(c);
		if (a.check() < 0)
			throw std::exception("Stack overflow");
		a.push(elem);
		return c;
	}*/

	std::ostream& operator <<(std::ostream& c, Stack& a)
	{
		if (a.check())
			throw std::exception("Stack is empty");
		int g = a.getTop();
		while (--g >= 0)
		{
			Massive elem;
			a.takeFirst(elem);
			elem.Print(c);
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

	Stack& Stack::push(Massive elem) //написать метод реализующий добавления из входного потока
	{
		if (top > SIZE - 1)
			throw std::exception("Stack overflow.");
		mas[top++] = elem;
		return *this;
	}

	Stack& Stack::pushS()
	{
		Massive elem;
		elem.getElem(std::cin);
		if (top > SIZE - 1)
			throw std::exception("Stack overflow");
		mas[top++] = elem;
		return *this;
	}

	void Stack::Print() const
	{	
		if (top == 0)
			throw std::exception("Stack is empty");
		int g = top;
		while(--g >= 0)
		{	
			Massive elem = mas[g];
			elem.Print(std::cout);
		}
	}
	void Stack::PrintFirst() const
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		Massive h = mas[top - 1];
		h.Print(std::cout);
	}

	const Stack& Stack::takeFirst(Massive& elem) const
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		elem = mas[top - 1];
		return *this;
	}

	Stack& Stack::pop(Massive& elem)
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		elem = mas[--top];
		return *this;
	}

	int  Stack::check() const
	{
		if (top > SIZE - 1)
			return -1;     //заполнен
		else
			if (top > 0)
				return 0;    //частично заполнен
			else
				return 1;    //пуст
	}
}
