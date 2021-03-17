#include "Cylinder.h"
double Cylinder::SurfaceArea()
{
	cout << "圆柱体的表面积：" << 2 * 3.14 * r * r + 2 * 3.14 * r * l << endl;
	return 0;
}
double  Cylinder::Volume()
{
	cout << "圆柱体的体积：" << 3.14 * r * r * l << endl;
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