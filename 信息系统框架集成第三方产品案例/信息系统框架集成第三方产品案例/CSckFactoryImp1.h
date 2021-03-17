#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"CSocketProtcol.h"
using namespace std;
class CSckFactoryImp1:public CSocketProtcol
{
public:
	virtual int cltSocketInit( /*out*/);

	//客户端发报文
	virtual int cltSocketSend(unsigned char* buf /*in*/, int len /*in*/) ;

	//客户端收报文
	virtual int cltSocketRev(unsigned char* outbuf /*in*/, int* outlen /*in out*/) ;

	//客户端释放资源
	virtual int cltSocketDestory() ;

private:
	unsigned char* p;
	int len;
};

