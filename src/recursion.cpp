#include"main.h"
void swap(int& a, int& b) {		//& is call by reference func1tion
	int temp{};
	a = temp;
	a = b;
	b = temp;
}

//int* creatArray(int n) {		//this func create an array in heap memory
//	int* p;
//	p = (int*)malloc(n * sizeof(int));
//	return p;
//}

//typedef struct {
//	int length;
//	int breadth;
//}rectangle;

//normal class
//class rectangle
//{
//public:
//	rectangle(int l, int b) {
//		length = l;
//		breadth = b;
//	}
//	int area() {
//		return length * breadth;
//	}
//	void changeLength(int l) {
//		length = l;
//	}
//private:
//	int length;
//	int breadth;
//};

//template<class T>
//class rectangle {
//private:
//	T a;
//	T b;
//public:
//	rectangle(T a, T b);
//	T area();
//	T perimeter();
//	void changeLength(T a);
//};
//
//template<class T>
//rectangle<T>::rectangle(T a, T b) {
//	this->a = a;
//	this->b = b;
//}
//
//template<class T>
//T rectangle<T>::area() {
//	return a * b;
//}
//
//template<class T>
//T rectangle<T>::perimeter() {
//	return 2 * a * b;
//}
//
//template<class T>
//void rectangle<T>::changeLength(T a) {
//	this->a = a;
//}

//recursion func
void func1(int n) {
	if (n > 0)
	{
		//head recursion
		func1(n - 1);	//output 1 2 3 ...acsending
		cout << n << " ";

		//tail recursion => use while loop for more efficient
		//cout << n << " ";
		//func1(n - 1);	//output 10 9 8 ...decending
		//this is a tail recursion that take more space than while loop(O(1))
		/*
			while(n>0){
				cout << n << " ";
				n--;
			} use this one is more efficient than tail recursion
		*/
	}
}

int func2(int n) {
	static int a;
	if (n > 0)
	{
		a++;
		return func2(n - 1) + a;
	}
	return 0;
}

void treeFunc(int x) //tree recursion call its func 2 time 
{
	if (x > 0) {
		cout << x << " ";
		treeFunc(x - 1);
		treeFunc(x - 1);
	}
}

void funA(int n)
{
	cout << n << " ";
	funB(n - 1);
}
void funB(int n)
{
	cout << n << " ";
	funA(n / 2);
}