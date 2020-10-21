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
		void Print(std::ostream& c) const
		{
			c << "key: " << key << " str: " << str << ' ' << std::endl;
		}
	};
	class Stack {
		int top;
		Massive mas[SIZE] = {};
	public: 
		Stack() { top = 0; };
		Stack(Massive, int k = 1); //Создаёт k одинаковых элементов
		int getTop() const { return top; }; //возвращает вершину(для гугл теста)
		Stack& push(Massive); //добавление элемента 
		Stack& pushS();//добавление элемента из потока
		const Stack& takeFirst(Massive&) const;
		friend std::ostream& operator <<(std::ostream& c,  Stack& a); //сделано!
		//friend std::istream& operator >>(std::istream&, Stack&);
		void Print() const; //выводит весь стек в поток
		void PrintFirst() const; //выводит только первый элемент
		Stack& pop(Massive&); //выборка из стека 
		int  check() const; //проверяет стек на заполненность(-1 полный; 0 частично заполнен; 1 пустой)
	};
}


#endif // !LAB3_STACK_H