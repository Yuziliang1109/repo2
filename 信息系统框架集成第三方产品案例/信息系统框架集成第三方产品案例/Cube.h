#pragma once
#include"Shape.h"
class Cube:public Shape
{
public:
	Cube(int a, int b, int c);
	~Cube();
	virtual double SurfaceArea();
	virtual double  Volume();
private:
	int a;
	int b;
	int c;
};

