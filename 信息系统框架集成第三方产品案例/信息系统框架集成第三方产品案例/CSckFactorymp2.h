#pragma once
#include"CSocketProtcol.h"
class CSckFactorymp2 :public CSocketProtcol
{
private:
	unsigned char* p;
	int len;
public:
	virtual int cltSocketInit( /*out*/) ;

	//�ͻ��˷�����
	virtual int cltSocketSend(unsigned char* buf /*in*/, int len /*in*/);

	//�ͻ����ձ���
	virtual int cltSocketRev(unsigned char* outbuf /*in*/, int* outlen /*in out*/);

	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory();


};

