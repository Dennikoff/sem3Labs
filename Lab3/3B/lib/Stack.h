#ifndef LAB3_STACK_H
#define LAB3_STACK_H
#include <iostream>
int const SIZE = 5;
int const SIZES = 30;
namespace Stk {
	void getInt(int&);
	struct Massive
	{
	private:
		int key;
		char str[SIZES] = {};
	public:
		Massive& setKey(int a)
		{
			key = a;
			return *this;
		}
		int getKey() { return key; }
		friend std::istream& operator >>(std::istream&, Massive&);
		friend std::ostream& operator <<(std::ostream& c, Massive& a)
		{
			c << "key: " << a.key << " str: " << a.str << ' ' << std::endl;
			return c;
		}
	};
	class Stack {
		int top;
		Massive mas[SIZE] = {};
	public: 
		Stack() { top = 0; };
		Stack(Massive, int k = 1); //Создаёт k одинаковых элементов
		int getTop() const { return top; }; //возвращает вершину(для гугл теста)
		Stack& operator +=(Massive&); //добавление элемента
		friend std::ostream& operator <<(std::ostream& c,  Stack& a); //выводит весь стек в поток
		friend std::istream& operator >>(std::istream&, Stack&); //добавляет элемент из потока
		void PrintFirst() const; //печать первого элемента
		Stack& operator ()(Massive&); //выборка из стека
		int  check() const; //проверяет стек на заполненность(-1 полный; 0 частично заполнен; 1 пустой)
	};
}


#endif // !LAB3_STACK_H