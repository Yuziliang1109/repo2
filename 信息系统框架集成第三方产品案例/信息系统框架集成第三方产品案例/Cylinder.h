#pragma once
#include"Shape.h"
class Cylinder:public Shape
{
public:
	Cylinder(int r, int l);
	~Cylinder();

	virtual double SurfaceArea();
	virtual double  Volume();
private:
	int r;
	int l;
};


