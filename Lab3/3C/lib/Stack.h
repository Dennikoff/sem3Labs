#ifndef LAB3_STACK_H
#define LAB3_STACK_H
#include <iostream>

namespace Stk { //добавить вывод сообщений, функцию в main возращающую по значению
	void getInt(int&);
	struct Massive
	{
	private:
		static const int SIZES = 30; //почитать про статик
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
	class Stack { //добьавить сайз 
		static const int SZ = 10; // размер для увеличения массива
		int Size;
		int top;
		Massive* mas; //(добавить перемещающий, копирующий, конструкторы, деструкторы,) (копирующее и перемещающее присваивание)
	public:
		Stack() : top(0), Size(SZ) { mas = new Massive[SZ]; };
		Stack(Massive, int k = 1); //Создаёт k одинаковых элементов  
		Stack(Massive*, int); //создание из массива 
		~Stack() { delete[] mas; std::cout << "distr\n"; };
		Stack(const Stack&);
		Stack(Stack&&);
		int getSize() const { return Size; }; // возвращает размер массива
		int getTop() const { return top; }; //возвращает вершину(для гугл теста)
		Stack& operator = (const Stack&); //копирующее присваивание
		Stack& operator = (Stack&&); //перемещающее присваивание
		Stack& operator +=(Massive&); //добавление элемента
		Stack& operator +=(const Stack&); //копирующее присваивание с добавлением
		Stack& operator ()(Stack&); //перемещающее присваивание с добавлением
		friend std::ostream& operator <<(std::ostream& c, Stack& a); //выводит весь стек в поток
		friend std::istream& operator >>(std::istream&, Stack&); //добавляет элемент из потока
		void PrintFirst(std::ostream&) const; //печать первого элемента
		Stack& operator ()(Massive&); //выборка из стека pop
		int  check() const; //проверяет стек на заполненность(-1 полный; 0 частично заполнен; 1 пустой)
	};
}


#endif // !LAB3_STACK_H