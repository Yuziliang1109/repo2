#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "MyVector.cpp"
/*
作业要求：
1.优化Teacher类，属性名字变为指针，构造函数中分配内存
2.析构函数释放内存
3.避免浅拷贝   重载=   重写拷贝构造函数
4.在Teacher类中增加<<
5.在模板数组类中  存 int,char,Teacher,Teacher*;
*/
class Teacher
{
public:
	Teacher()
	{
		age = 0;
		name = NULL;
	}
	Teacher(int age, const char* name)
	{
		this->age = age;
		this->name = new char[32] ;
		//name = { 0 };
		strcpy(this->name, name);
	}

	~Teacher()
	{
		if (name != NULL)
		{
			delete[]name;
			name = NULL;
			age = 0;
		}
	}
	Teacher(const Teacher& obj)
	{
		age = obj.age;
		name = new char[32];
		strcpy(name, obj.name);
	}
public:
	Teacher& operator=(Teacher& obj)
	{
		if (name != NULL)
		{
			delete[]name;
			name = NULL;
			age = 0;
		}
		age = obj.age;
		name = new char[32];
		strcpy(name, obj.name);
		return *this;
	}
	void print()
	{
		cout << name << ";" << age << endl;
	}

	friend ostream& operator<<(ostream& out, Teacher& obj);
private:
	int age;
	char* name;
};

ostream& operator<<(ostream& out, Teacher& obj)
{
	out << obj.name<<";"<<obj.age<< endl;
	return out;
}
void playobj()
{
	//Teacher类的数组
	//这里执行了有参构造函数
	Teacher t1(25, "t1"), t2(26, "t2"), t3(27, "t3"), t4(28, "t4");
	//MyVector的有参构造  Teacher的无参构造
	MyVector<Teacher> tArray(4);
	//重载【】   Teacher 的拷贝构造
	tArray[0] = t1;
	tArray[1] = t2;
	tArray[2] = t3;
	tArray[3] = t4;
	for (int i = 0; i < 4; i++)
	{
		cout << tArray[i];//重载【】   Teacher的<<运算符重载
	}
	MyVector<Teacher>tArray2(5);
	tArray2= tArray;//MyVector重载=   teacher重载=
	for (int i = 0; i < 4; i++)
	{
		cout << tArray2[i];
	}
	
}
void playobj1()
{
	////Teacher*类的数组
	Teacher t1(25, "t1"), t2(26, "t2"), t3(27, "t3"), t4(28, "t4");
	Teacher* p1 = &t1;
	Teacher* p2 = &t2;
	Teacher* p3 = &t3;
	Teacher* p4 = &t4;
	MyVector<Teacher*>tArray(4);
	tArray[0] = p1;
	tArray[1] = p2;
	tArray[2] = p3;
	tArray[3] = p4;
	for (int i = 0; i < 4; i++)
	{
		cout << *tArray[i] << endl;
	}

}
void main()
{
	playobj();
	playobj1();
	system("pause");
	return;

}