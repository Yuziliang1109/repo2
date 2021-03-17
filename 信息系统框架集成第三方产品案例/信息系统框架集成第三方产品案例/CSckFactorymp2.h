#pragma once
#include"CSocketProtcol.h"
class CSckFactorymp2 :public CSocketProtcol
{
private:
	unsigned char* p;
	int len;
public:
	virtual int cltSocketInit( /*out*/) ;

	//客户端发报文
	virtual int cltSocketSend(unsigned char* buf /*in*/, int len /*in*/);

	//客户端收报文
	virtual int cltSocketRev(unsigned char* outbuf /*in*/, int* outlen /*in out*/);

	//客户端释放资源
	virtual int cltSocketDestory();


};

