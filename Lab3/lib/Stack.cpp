#include <iostream>
#include <string.h>
#include "../lib/Stack.h";

namespace Stk {
	Stack::Stack(Massive elem)
	{
		top = 0;
		if (top > SIZE)
			throw std::exception("Stack overflow");
		mas[top++] = elem;
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
		if (top > SIZE)
			throw std::exception("Stack overflow");
		for (int i = 0; i < 20 && str[i] != '\0'; i++)
		{
			mas[top].str[i] = str[i];
		}
	}

	Stack& Stack::push(Massive elem, int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (top > SIZE)
				throw std::exception("Stack overflow");
			mas[top++] = elem;
		}
	}

	Stack& Stack::push(Massive* elem, int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (top > SIZE)
				throw std::exception("Stack overflow");
			mas[top++] = elem[i];
		}
	}

	Stack& Stack::push(int ch)
	{
		if (top > SIZE)
			throw std::exception("Stack overflow");
		mas[top].key = ch;
	}

	Stack& Stack::push(char* str)
	{
		if (top > SIZE)
			throw std::exception("Stack overflow");
		for(int i = 0; i < 19 && str[i] != '\0'; i++)
		{
			mas[top].str[i] = str[i];
		}
		mas[top].str[20] = '\0';
	}

	Stack& Stack::getElems() const
	{	
		if (top == 0)
			throw std::exception("Stack is empty");
		int g = top;	
		while(--g > 0)	
		{		
			std::cout << ("%d key:%d  ",g,mas[g].key)<< ("%d str:%s",g,mas[g].str) << std::endl;	
		}
	}

	Stack& Stack::getElem() const
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		std::cout << (" key:%d  ", mas[top-1].key) << (" str:%s", mas[top-1].str) << std::endl;
	}

	Stack& Stack::pop(Massive& elem)
	{
		if (top < 0)
			throw std::exception("Stack is empty");
		elem = mas[--top];
	}

	Stack& Stack::pop(Massive* elem, int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (top > SIZE)
				throw std::exception("Stack is empty");
			*elem = mas[--top];
		}
	}

	Stack& Stack::pop(int ch)
	{
		if (top > SIZE)
			throw std::exception("Stack is empty");
		ch = mas[--top].key;
	}

	Stack& Stack::pop(char* str)
	{
		if (top > SIZE)
			throw std::exception("Stack is empty");
		str = mas[top].str;
	}
	Stack& Stack::check()
	{
		if (top > SIZE)
			std::cout << "Stack Overflow" << std::endl;
		else
			if (top > 0)
				std::cout << "Stack Patricaly filled" << std::endl;
			else
				std::cout << "Stack is Empty" << std::endl;
	}
}
