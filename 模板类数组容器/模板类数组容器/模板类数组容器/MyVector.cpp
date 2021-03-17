#include "MyVector.h"


template<typename T>
MyVector<T>::MyVector(int len)
{
	this->len = len;
	p = new T[len];
}
template<typename T>
MyVector<T>::MyVector(const MyVector<T>& obj)
{
	len = obj.len;
	p = new T[len];
	for (int i = 0; i < len; i++)
	{
		p[i] = obj.p[i];
	}
}
template<typename T>
MyVector<T>::~MyVector()
{
	if (p != NULL)
	{
		delete[]p;
		p = NULL;
		len = 0;
	}
}
template<typename T>
T& MyVector<T>::operator[](int i)
{
	return p[i];
}
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& obj)
{
	if (p != NULL)
	{
		delete[]p;
		p = NULL;
		len = 0;
	}
	len = obj.len;
	p = new T[len];
	for (int i = 0; i < len; i++)
	{
		p[i] = obj.p[i];
	}
	return *this;
}
template<typename T>
ostream& operator<<(ostream& out, MyVector<T>& obj)
{
	for (int i= 0; i < obj.len; i++)
	{
		out << obj.p[i] << endl;
	}
	return out;
}