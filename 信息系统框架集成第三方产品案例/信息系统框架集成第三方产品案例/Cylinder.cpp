#include "Cylinder.h"
double Cylinder::SurfaceArea()
{
	cout << "Բ����ı������" << 2 * 3.14 * r * r + 2 * 3.14 * r * l << endl;
	return 0;
}
double  Cylinder::Volume()
{
	cout << "Բ����������" << 3.14 * r * r * l << endl;
	return 0;
}
Cylinder::Cylinder(int r, int l)
{
	this->r = r;
	this->l = l;
}
Cylinder::~Cylinder()
{

}