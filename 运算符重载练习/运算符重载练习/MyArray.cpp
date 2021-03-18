#include "MyArray.h"


MyArray::MyArray()
{
	len = 0;
	p = NULL;
}
MyArray::MyArray(int len)
{
	this->len = len;
	p = new int[len];
}
MyArray::MyArray(const MyArray& obj)
{
	len = obj.len;
	p = new int[len];
	for (int i = 0; i < len; i++)
	{
		p[i] = obj.p[i];
	}
}
MyArray::~MyArray()
{
	if (p != NULL)
	{
		delete[]p;
		p = NULL;
		len = 0;
	}
}
MyArray& MyArray::operator=(MyArray& obj)
{
	if (p != NULL)
	{
		delete[]p;
		p = NULL;
		len = 0;
	}
	len = obj.len;
	p = new int[len];
	for (int i = 0; i < len; i++)
	{
		p[i] = obj.p[i];
	}
	return *this;
}
int& MyArray::operator[](int i)
{
	return p[i];
}
ostream& operator<<(ostream& out, MyArray& obj)
{
	for (int i = 0; i < obj.len; i++)
	{
		out << obj.p[i] << endl;
	}
	return out;
}
bool MyArray::operator==(MyArray& obj)
{
	if (len != obj.len)
	{
		return true;
	}
	for (int i = 0; i < len; i++)
	{
		if (p[i] != obj[i])
		{
			return false;
		}
	}
	return true;
}