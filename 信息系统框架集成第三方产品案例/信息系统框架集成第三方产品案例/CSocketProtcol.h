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
	//�ͻ��˳�ʼ�� 
	virtual int cltSocketInit( /*out*/) = 0;

	//�ͻ��˷�����
	virtual int cltSocketSend(unsigned char* buf /*in*/, int len /*in*/) = 0;

	//�ͻ����ձ���
	virtual int cltSocketRev(unsigned char* outbuf /*in*/, int* outlen /*in out*/) = 0;

	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory() = 0;

};

