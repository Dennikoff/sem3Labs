#ifndef LAB3_STACK_H
#define LAB3_STACK_H
int const SIZE = 20;
namespace Stk {
	struct Massive
	{
		int key;
		char str[20] = {'\0'};
		void printKey()
		{
			std::cout << this->key << std::endl;
		}
		void printStr()
		{
			std::cout << this->str << std::endl;
		}
	};
	class Stack {
		int top;
		Massive mas[SIZE] = {'\0'};
	public: 
		Stack() { top = 0; };
		Stack(Massive, int k = 1);
		Stack(Massive*, int);
		Stack(int);
		Stack(char* str);
		int getTop() { return top; };
		Stack& push(Massive);
		Stack& push(Massive*, int);
		Stack& push(int);
		Stack& push(char* str);
		const Stack& getElems() const;
		const Stack& getElem() const;
		Stack& pop(Massive&);
		Stack& pop(Massive*, int);
		Stack& pop(int);
		Stack& pop(char* str);
		Stack& check();
	};
}


#endif // !LAB3_STACK_H
