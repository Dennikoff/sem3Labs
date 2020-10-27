#ifndef LAB3_STACK_H
#define LAB3_STACK_H
int const SIZE = 10;
namespace Stk {
	//template<class T>
	void getInt(int&);
	struct Massive
	{
	private:
		int key;
		char str[21] = {};
	public:
		Massive& setKey(int a)
		{
			key = a;
			return *this;
		}
		int getKey() { return key; }
		Massive& getElem(std::istream&);
		void Print(std::ostream&) const
		{
			std::cout << "key: " << key << " str: " << str << ' ' << std::endl;
		}
	};
	class Stack {
		int top;
		Massive mas[SIZE] = {};
	public: 
		Stack() { top = 0; };
		Stack(Massive, int k = 1); //Создаёт k одинаковых элементов
		Stack(Massive*, int);
		int getTop() const { return top; }; //возвращает вершину(для гугл теста)
		Stack& push(Massive); //добавление элемента 
		Stack& pushS(std:: istream&); //добавление элемента из потока
		/*Stack& push(Massive, int);*/
		void Print(std:: ostream&) const; //выводит весь стек в поток 
		void PrintFirst(std::ostream&) const; //выводит только первый элемент
		Massive pop(); //выборка из стека massive m = stack.pop();
		int check(); //проверяет стек на заполненность(-1 полный; 0 частично заполнен; 1 пустой)
	};
}


#endif // !LAB3_STACK_H