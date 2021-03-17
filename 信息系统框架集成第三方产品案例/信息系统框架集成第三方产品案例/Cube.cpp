#include "Cube.h"


Cube::Cube(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
Cube::~Cube()
{

}
double Cube::SurfaceArea()
{
	cout << "正方体的表面积：" << 2 * a * b + 2 * a * c + 2 * b * c << endl;
	return 0;
}
double  Cube::Volume()
{
	cout << "正方体的体积：" << a * b * c << endl;
	return 0;
}