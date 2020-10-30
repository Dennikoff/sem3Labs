#include <iostream>
#include <string.h>
#include "Stack.h";

namespace Stk {
	std::istream& operator >>(std::istream& c, Massive& a)
	{
		std::cout << "Enter your key" << std::endl;
		c >> a.key;
		char s[a.SIZES * 10];
		std::cout << "Enter your string" << std::endl;
		c >> s;
		for (int i = 0; i < a.SIZES; i++)
		{
			a.str[i] = s[i];
		}
		if (strlen(a.str) < a.SIZES)
			a.str[strlen(a.str)] = '\0';
		else
			a.str[a.SIZES - 1] = '\0';
		return c;
	}

	Stack::Stack(Massive elem, int k)
	{
		top = 0;
		Size = 0;
		for(int i = 0; i < (k/10 + 1); i++)
			Size+= SZ;
		mas = new Massive[SZ];
		for (int i = 0; i < k; i++)
		{
			/*if (top > Size)
			{
				Size += SZ;
				Massive* old = mas;
				mas = new Massive[Size];
				for (int j = 0; j < Size; j++)
				{
					mas[j] = old[j];
				}
				delete[] old;
			}*/
			mas[top++] = elem;
		}
	}

	Stack::Stack(Massive* elem, int n)
	{
		top = 0;
		Size = n;
		mas = new Massive[n];
		for (int i = 0; i < n; i++)
		{
			/*if (top > Size)
			{
				Size += SZ;
				Massive* old = mas;
				mas = new Massive[Size];
				for (int j = 0; j < top; j++)
				{
					mas[j] = old[j];
				}
				delete[] mas;
				mas = old;
			}*/
			mas[top++] = elem[i];
		}
	}

	Stack::Stack(const Stack& a)
	{
		top = a.top;
		Size = a.Size;
		mas = new Massive[Size];
		for (int i = 0; i < top; i++)
		{
			mas[i] = a.mas[i];
		}
	}

	Stack::Stack(Stack&& a)
	{
		top = a.top;
		Size = a.Size;
		mas = a.mas;
		a.mas = nullptr;
	}

	void getInt(int& n)
	{
		std::cin >> n;
		while (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid.Try again.\n";
			std::cin >> n;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	Stack& Stack::operator =(const Stack& a)
	{
		if (this != &a)
		{
			top = a.top;
			Size = a.Size;
			delete[] mas;
			mas = new Massive[Size];
			for (int i = 0; i < top; i++)
			{
				mas[i] = a.mas[i];
			}
		}
		return *this;
	}

	Stack& Stack::operator =(Stack&& a)
	{
		/*top = a.top;
		Size = a.Size;
		delete[] mas;
		mas = a.mas;
		a.mas = nullptr;*/
		int tmp = top;
		top = a.top;
		a.top = tmp;
		tmp = Size;
		Size = a.Size;
		a.Size = tmp;
		Massive* el = mas;
		mas = a.mas;
		a.mas = el;
		return *this;
	}

	std::istream& operator >>(std::istream& c, Stack& a)
	{
		Massive elem;
		c >> elem;
		if (a.top > a.Size - 1)
		{
			a.Size += a.SZ;
			Massive* old = a.mas;
			a.mas = new Massive[a.Size];
			for (int i = 0; i < a.top; i++)
			{
				a.mas[i] = old[i];
			}
			delete[] old;
		}
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

	Stack& Stack::operator+=(Massive& elem)
	{
		if (top >= Size)
		{
			Size += SZ;
			Massive* old = mas;
			mas = new Massive[Size];
			for (int i = 0; i < Size; i++)
			{
				mas[i] = old[i];
			}
			delete[] old;
		}
		mas[top++] = elem;
		return *this;
	}

	Stack& Stack::operator +=(const Stack& st)
	{
		Stack tmp(st);
		Massive el;
		while (tmp.top > 0)
		{
			tmp(el);
			*this += el;
		}
		return *this;
	}

	void Stack::PrintFirst(std::ostream& c) const
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		Massive h = mas[top - 1];
		c << h;
	}

	Stack& Stack:: operator()(Massive& elem)
	{
		if (top == 0)
			throw std::exception("Stack is empty");
		elem = mas[--top];
		return *this;
	}

	Stack& Stack:: operator()(Stack& st)
	{
		Massive el;
		while (st.top > 0)
		{
			st(el);
			*this += el;
		}
		return *this;
	}

	int  Stack::check() const
	{
		if (top > Size - 1)
			return -1;     //заполнен
		else
			if (top > 0)
				return 0;    //частично заполнен
			else
				return 1;    //пуст
	}
}
