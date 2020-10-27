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
		if (strlen(str) < 21)
			str[strlen(str)] = '\0';
		else
			str[20] = '\0';
		return *this;
	}

	Stack::Stack(Massive elem, int k)
	{
		top = 0;
		for (int i = 0; i < k; i++)
		{
			if (top > SIZE - 1)
				throw std::exception("Stack overflow");
			mas[top++] = elem;
		}
	}
	Stack::Stack(Massive* elem, int k)
	{
		top = 0;
		for (int i = 0; i < k; i++)
		{
			if (top > SIZE - 1)
				throw std::exception("Stack overflow");
			mas[top++] = elem[i];
		}
	}

	Stack& Stack::push(Massive elem) //написать метод реализующий добавления из входного потока
	{
		if (top > SIZE - 1)
			throw std::exception("Stack overflow.");
		mas[top++] = elem;
		return *this;
	}

	Stack& Stack::pushS(std::istream& c)
	{
		Massive elem;
		elem.getElem(c);
		if (top > SIZE - 1)
			throw std::exception("Stack overflow");
		mas[top++] = elem;
		return *this;
	}

	void Stack::Print(std::ostream& c) const
	{	
		if (top == 0)
			throw std::exception("Stack is empty");
		int g = top;
		while(--g >= 0)
		{	
			Massive elem = mas[g];
			elem.Print(c);
		}
	}
	void Stack::PrintFirst(std::ostream& c) const
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		Massive h = mas[top - 1];
		h.Print(c);
	}

	Massive Stack::pop()
	{
		Massive elem;
		if (top == 0)
			throw std::exception("Stack is empty");
		elem = mas[--top];
		return elem;
	}

	int Stack::check()
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
