#ifndef LAB3_STACK_H
#define LAB3_STACK_H
int const SIZE = 20;
namespace Stk {
	struct Massive
	{
		int key;
		char str[20];
	};
	class Stack {
		int top;
		Massive mas[SIZE];
	public: 
		Stack() { top = 0; };
		Stack(Massive);
		Stack(Massive*, int);
		Stack(int);
		Stack(char* str);
		Stack& push(Massive, int n = 1);
		Stack& push(Massive*, int);
		Stack& push(int);
		Stack& push(char* str);
		Stack& getElems() const;
		Stack& getElem() const;
		Stack& pop(Massive&);
		Stack& pop(Massive*, int);
		Stack& pop(int);
		Stack& pop(char* str);
		Stack& check();
	};
}


#endif // !LAB3_STACK_H
