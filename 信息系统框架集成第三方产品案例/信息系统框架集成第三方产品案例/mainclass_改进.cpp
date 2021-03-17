#include<iostream>
using namespace std;
#include"Shape.h"
#include"Cube.h"
#include "Sphere.h"
#include "Cylinder.h"

class Kuangjia
{
private:
	Shape* sp;
public:
	Kuangjia(Shape* sp)
	{
		this->sp = sp;
	}

	int Cal_SurfaceAreaVolume01()
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
	void deleteObj()
	{
		delete sp;
	}
};

int main()
{
	//父类指针指向子类new的新对象
	Shape* sp = NULL;
	//sp= new Cube(10, 20, 30);
	//sp= new Sphere(10);
	sp = new Cylinder(10, 20);
	Kuangjia* kuangjia = new Kuangjia(sp);
	int ret = 0;
	ret = kuangjia->Cal_SurfaceAreaVolume01();
	if (ret != 0)
	{
		cout << "kuangjia->Cal_SurfaceAreaVolume01() err:" << ret << endl;
		goto End;
	}

End:
	kuangjia->deleteObj();
	delete kuangjia;
	system("pause");
	return ret;
}