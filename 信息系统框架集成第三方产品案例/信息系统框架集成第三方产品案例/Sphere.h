#pragma once
#include"Shape.h"
class Sphere :public Shape
{
public:
	Sphere(int r);
	~Sphere();
	virtual double SurfaceArea();
	virtual double  Volume();
private:
	int r;
};

