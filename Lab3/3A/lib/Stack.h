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
		Stack(Massive, int k = 1); //������ k ���������� ���������
		Stack(Massive*, int);
		int getTop() const { return top; }; //���������� �������(��� ���� �����)
		Stack& push(Massive); //���������� �������� 
		Stack& pushS(std:: istream&); //���������� �������� �� ������
		/*Stack& push(Massive, int);*/
		void Print(std:: ostream&) const; //������� ���� ���� � ����� 
		void PrintFirst(std::ostream&) const; //������� ������ ������ �������
		Massive pop(); //������� �� ����� massive m = stack.pop();
		int check(); //��������� ���� �� �������������(-1 ������; 0 �������� ��������; 1 ������)
	};
}


#endif // !LAB3_STACK_H