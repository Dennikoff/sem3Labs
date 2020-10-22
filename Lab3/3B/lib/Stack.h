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
		Stack(Massive, int k = 1); //������ k ���������� ���������
		int getTop() const { return top; }; //���������� �������(��� ���� �����)
		Stack& operator +=(Massive&); //���������� ��������
		friend std::ostream& operator <<(std::ostream& c,  Stack& a); //������� ���� ���� � �����
		friend std::istream& operator >>(std::istream&, Stack&); //��������� ������� �� ������
		void PrintFirst() const; //������ ������� ��������
		Stack& operator ()(Massive&); //������� �� �����
		int  check() const; //��������� ���� �� �������������(-1 ������; 0 �������� ��������; 1 ������)
	};
}


#endif // !LAB3_STACK_H