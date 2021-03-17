#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class CSocketProtcol
{
public:
	CSocketProtcol()
	{
		;
	}
	virtual ~CSocketProtcol()
	{
		;
	}
	//客户端初始化 
	virtual int cltSocketInit( /*out*/) = 0;

	//客户端发报文
	virtual int cltSocketSend(unsigned char* buf /*in*/, int len /*in*/) = 0;

	//客户端收报文
	virtual int cltSocketRev(unsigned char* outbuf /*in*/, int* outlen /*in out*/) = 0;

	//客户端释放资源
	virtual int cltSocketDestory() = 0;

};

