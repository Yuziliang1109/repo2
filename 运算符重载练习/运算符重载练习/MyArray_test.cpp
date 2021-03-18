#include<iostream>
using namespace std;
#include "MyArray.h"


void main()
{
	MyArray my1(5);
	for (int i = 0; i < 5; i++)
	{
		my1[i] = i + 9;
	}
	cout << my1;
	MyArray my2(6);
	my2 = my1;
	cout << my2;
	MyArray my3(my2);
	cout << my3;
	if (my1==my2)
	{
		cout << "my1=my2" << endl;
	}
	else
	{
		cout << "my1!=my2" << endl;
	}
	system("pause");
	return ;
}
