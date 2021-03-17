#pragma once

#include<iostream>
using namespace std;
class CEncDesProtoocol
{
public:
	CEncDesProtoocol()
	{

	}
	virtual ~CEncDesProtoocol()
	{

	}
	virtual int EncData(unsigned char* plain, int plainlen, unsigned char* cryptdata, int *cryptdatalen) = 0;
	virtual int DeccData(unsigned char* cryptdata, int cryptdatalen, unsigned char* plain, int* plainlen) = 0;
};