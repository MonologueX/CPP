#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <windows.h>
using namespace std;

//////////////////////////////////
//// �ʼ�
//////////////////////////////////
//// ʲô�Ǻ�������
//// << ����Ա���������� >> 
//// 
////
////
////
////void fun(int i)
////{
////	cout << i << endl;
////}
////void fun(char ch)
////{
////	cout << ch << endl;
////}
//
//int main()
//{
//	fun(10);
//	fun('a');
//	system("pause");
//	return 0;
//}

//struct BigData
//{
//	int array[1000];
//};
//
//void Read(const BigData& bd)
//{
//
//}
//
//int main()
//{
//	BigData b;
//	Read(b);
//
//	system("pause");
//	return 0;
//}

//int& Add(int d1, int d2)
//{
//	int ret = d1 + d2;
//	return ret;
//}
//
//int main()
//{
//	int& c = Add(1, 2);
//	Add(10, 20);
//	cout << c << endl;
//	system("pause");
//	return 0;
//}
//
//int& Add(int d1, int d2)
//{
//	static int ret = d1 + d2;
//	return ret;
//}
//
//int main()
//{
//	int& c = Add(1, 2);
//	Add(10, 20);
//	cout << c << endl;
//	system("pause");
//	return 0;
//}

////////////////////////////////
//ָ��������

class Person
{
public:
	//��Ա����
	void Show();
	
	//��Ա����

	char* _name;
	int _age;
};

void Person::Show()
{
	cout << _name << endl;
	cout << _age << endl;
}

int main()
{
	Person p;
	p._name = "peter";
	p._age = 6;
	p.Show();

	Person*ptr = &p;
	ptr->Show();

	cout << sizeof(p) << endl;

	Person p1;
	p1._name = "xxx";
	p1._age = 18;
	p1.Show();

	system("pause");
	return 0;
}