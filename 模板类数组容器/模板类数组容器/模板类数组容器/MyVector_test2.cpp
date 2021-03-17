#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "MyVector.cpp"
/*
��ҵҪ��
1.�Ż�Teacher�࣬�������ֱ�Ϊָ�룬���캯���з����ڴ�
2.���������ͷ��ڴ�
3.����ǳ����   ����=   ��д�������캯��
4.��Teacher��������<<
5.��ģ����������  �� int,char,Teacher,Teacher*;
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
	//Teacher�������
	//����ִ�����вι��캯��
	Teacher t1(25, "t1"), t2(26, "t2"), t3(27, "t3"), t4(28, "t4");
	//MyVector���вι���  Teacher���޲ι���
	MyVector<Teacher> tArray(4);
	//���ء���   Teacher �Ŀ�������
	tArray[0] = t1;
	tArray[1] = t2;
	tArray[2] = t3;
	tArray[3] = t4;
	for (int i = 0; i < 4; i++)
	{
		cout << tArray[i];//���ء���   Teacher��<<���������
	}
	MyVector<Teacher>tArray2(5);
	tArray2= tArray;//MyVector����=   teacher����=
	for (int i = 0; i < 4; i++)
	{
		cout << tArray2[i];
	}
	
}
void playobj1()
{
	////Teacher*�������
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