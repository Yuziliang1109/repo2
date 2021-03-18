#pragma once
#include<iostream>
using namespace std;

class MyArray
{
private:
	int len;
	int* p;
public:
	MyArray();
	MyArray(int len);
	MyArray(const MyArray& obj);
	~MyArray();
public:
	MyArray& operator=(MyArray& obj);
	int& operator[](int i);
	friend ostream& operator<<(ostream& out, MyArray& obj);
	bool operator==(MyArray& obj);
};

