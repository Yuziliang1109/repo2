#include "Sphere.h"

double Sphere::SurfaceArea()
{
	cout << "球的表面积：" << 4 * 3.14 * r * r << endl;
	return 0;
}
double  Sphere::Volume()
{
	cout << "球的体积：" << 3.14 * r * r * r << endl;
	return 0;
}
Sphere::~Sphere()
{

}
Sphere::Sphere(int r)
{
	this->r = r;
}