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
	cout << "������ı������" << 2 * a * b + 2 * a * c + 2 * b * c << endl;
	return 0;
}
double  Cube::Volume()
{
	cout << "������������" << a * b * c << endl;
	return 0;
}