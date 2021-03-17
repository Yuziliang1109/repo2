#pragma once
#include<iostream>
using namespace std;
template<typename T>
class MyVector
{
	friend ostream& operator<<<T>(ostream& out, MyVector& obj);
public:
	MyVector(int len);
	MyVector(const MyVector& obj);
	~MyVector();
public:
	T& operator[](int i);
	MyVector& operator=(const MyVector& obj);
	

private:
	int len;
	T* p;
};

