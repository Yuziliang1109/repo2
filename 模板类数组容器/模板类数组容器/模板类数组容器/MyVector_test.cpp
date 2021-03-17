#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
using namespace std;
#include "MyVector.cpp"

class Teacher
{
public:
	Teacher()
	{
		age = 0;
		strcpy(this->name, "");
	}
	Teacher(int age, const char* name)
	{
		this->age = age;
		strcpy(this->name, name);
	}
	void print()
	{
		cout << name << ";" << age << endl;
	}
private:
	int age;
	char name[32];
};


//int 型数组
void playobj()
{
	MyVector<int> my1(5);
	for (int i = 0; i < 5; i++)
	{
		my1[i] = i + 1;
	}
	cout << my1 << endl;
	MyVector<int> my2 = my1;
	cout << my2 << endl;

	MyVector<int>my3(10);
	my3 = my2;
	cout << my3 << endl;
}

//char型数组
void playobj1()
{
	MyVector<char> my1(5);
	for (int i = 0,j=97; i < 5; i++,j++)
	{
		my1[i] = j;
	}
	cout << my1 << endl;
	MyVector<char> my2 = my1;
	cout << my2 << endl;

	MyVector<char>my3(10);
	my3 = my2;
	cout << my3 << endl;
}
//Teacher型数组
void playobj2()
{
	Teacher t1(31, "t1"), t2(32, "t2"), t3(33, "t3"), t4(34, "t4"), t5(35, "t5");
	MyVector<Teacher>tArray(5);
	tArray[0] = t1;
	tArray[1] = t2;
	tArray[3] = t3;
	tArray[2] = t4;
	tArray[4] = t5;
	for (int i = 0; i < 5; i++)
	{
		tArray[i].print();
	}
}
void main()
{
	//playobj();
	//playobj1();
	playobj2();
	system("pause");
	return ;
}

/*
作业要求：
1.优化Teacher类，属性名字变为指针，构造函数中分配内存
2.析构函数释放内存
3.避免浅拷贝   重载=   重写拷贝构造函数
4.在Teacher类中增加<<
5.在模板数组类中  存 int,char,Teacher,Teacher*;
*/