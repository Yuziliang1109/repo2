#include<iostream>
using namespace std;
#include"Shape.h"
#include"Cube.h"
#include "Sphere.h"
#include "Cylinder.h"

int Cal_SurfaceAreaVolume(Shape* sp)
{
	int ret = 0;
	ret = sp->SurfaceArea();
	if (ret != 0)
	{
		cout << "sp->SurfaceArea()err:" << ret << endl;
		return ret;
	}
	ret = sp->Volume();
	if (ret != 0)
	{
		cout << "sp->SurfaceArea()err:" << ret << endl;
		return ret;
	}
	return 0;
}
int main01()
{
	Shape* sp = NULL;
	Cube* cb = new Cube(10,20,30);
	Sphere* sph = new Sphere(10);
	Cylinder* cy = new Cylinder(10, 20);
	int ret = 0;

	ret = Cal_SurfaceAreaVolume(cb);
	if (ret != 0)
	{
		cout << "Cal_SurfaceAreaVolume err:" << ret << endl;
		goto End;
	}
	ret = Cal_SurfaceAreaVolume(sph);
	if (ret != 0)
	{
		cout << "Cal_SurfaceAreaVolume err:" << ret << endl;
		goto End;
	}
	ret = Cal_SurfaceAreaVolume(cy);
	if (ret != 0)
	{
		cout << "Cal_SurfaceAreaVolume err:" << ret << endl;
		goto End;
	}

End:
	
	system("pause");
	return ret;
}