#pragma once
#include<iostream>
using namespace std;

class Shape
{
public:

	virtual ~Shape()
	{

	}
public:
	virtual double SurfaceArea() = 0;
	virtual double  Volume() = 0;
};