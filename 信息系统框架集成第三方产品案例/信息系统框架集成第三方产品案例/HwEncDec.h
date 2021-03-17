#pragma once
#include<iostream> 
using namespace std;
#include"CEncDesProtoocol.h"
#include"des.h"
class HwEncDec:public CEncDesProtoocol
{
public:

	virtual int EncData(unsigned char* plain, int plainlen, unsigned char* cryptdata, int* cryptdatalen);
	virtual int DeccData(unsigned char* cryptdata, int cryptdatalen, unsigned char* plain, int* plainlen);

};

