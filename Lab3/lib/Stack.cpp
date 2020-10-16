#include <iostream>
#include <string.h>
#include "../lib/Stack.h";

namespace Stk {
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

	Stack::Stack(Massive* elem, int n)
	{
		top = 0;
		for (int i = 0; i < n; i++)
		{
			if (top > SIZE)
				throw std::exception("Stack overflow");
			mas[top++] = elem[i];
		}
	}

	Stack::Stack(int ch)
	{
		top = 0;
		if (top > SIZE)
			throw std::exception("Stack overflow");
		mas[top++].key = ch;
	}

	Stack::Stack(char* str)
	{
		top = 0;
		if (top > SIZE - 1)
			throw std::exception("Stack overflow");
		for (int i = 0; i < 20 && str[i] != '\0'; i++)
		{
			mas[top].str[i] = str[i];
		}
		top++;
	}

	Stack& Stack::push(Massive elem)
	{
		if (top > SIZE - 1)
			throw std::exception("Stack overflow.");
		mas[top++] = elem;
		return *this;
	}

	Stack& Stack::push(Massive* elem, int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (top > SIZE - 1)
				throw std::exception("Stack overflow");
			mas[top++] = elem[i];
		}
		return *this;
	}

	Stack& Stack::push(int ch)
	{
		if (top > SIZE - 1)
			throw std::exception("Stack overflow");
		mas[top-1].key += ch;
		return *this;
	}

	Stack& Stack::push(char* str)
	{
		if (top > SIZE - 1)
			throw std::exception("Stack overflow");
		for(int i = 0; i < 19 && str[i] != '\0'; i++)
		{
			mas[top].str[i] = str[i];
		}
		mas[top].str[20] = '\0';
		return *this;
	}

	const Stack& Stack::getElems() const
	{	
		if (top == 0)
			throw std::exception("Stack is empty");
		int g = top;
		while(--g >= 0)
		{	
			std::cout << g + 1 << " key: " << mas[g].key << "  " << " str: " << mas[g].str << std::endl;
		}
		return *this;
	}

	const Stack& Stack::getElem() const
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		std::cout << " key: " << mas[top - 1].key << "  " << " str: " << mas[top - 1].str << std::endl;
		return *this;
	}

	Stack& Stack::pop(Massive& elem)
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		elem = mas[--top];
		return *this;
	}

	Stack& Stack::pop(Massive* elem, int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (top == 0)
				throw std::exception("Stack is empty");
			*elem = mas[--top];
		}
		return *this;
	}

	Stack& Stack::pop(int ch)
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		ch = mas[--top].key;
	}

	Stack& Stack::pop(char* str)
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		str = mas[top].str;
	}
	Stack& Stack::check()
	{
		if (top > SIZE - 1)
			std::cout << "Stack Overflow" << std::endl;
		else
			if (top > 0)
				std::cout << "Stack Patricaly filled" << std::endl;
			else
				std::cout << "Stack is Empty" << std::endl;
		return *this;
	}
}
