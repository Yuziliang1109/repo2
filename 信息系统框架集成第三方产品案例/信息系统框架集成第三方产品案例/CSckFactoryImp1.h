#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"CSocketProtcol.h"
using namespace std;
class CSckFactoryImp1:public CSocketProtcol
{
public:
	virtual int cltSocketInit( /*out*/);

	//�ͻ��˷�����
	virtual int cltSocketSend(unsigned char* buf /*in*/, int len /*in*/) ;

	//�ͻ����ձ���
	virtual int cltSocketRev(unsigned char* outbuf /*in*/, int* outlen /*in out*/) ;

	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory() ;

private:
	unsigned char* p;
	int len;
};

