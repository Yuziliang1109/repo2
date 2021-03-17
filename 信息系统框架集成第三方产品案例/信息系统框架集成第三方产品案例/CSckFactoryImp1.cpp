#include "CSckFactoryImp1.h"
#define _CRT_SECURE_NO_WARNINGS


int CSckFactoryImp1::cltSocketInit( /*out*/)
{
	p = NULL;
	len = 0;
	return 0;
}

//客户端发报文
int CSckFactoryImp1::cltSocketSend(unsigned char* buf /*in*/, int len /*in*/)
{
	if (buf == NULL)
	{
		return -1;
	}
	this->len = len;
	p = new unsigned char[this->len];
	memcpy(p, buf, this->len);
	return 0;
}


//客户端收报文
int CSckFactoryImp1::cltSocketRev(unsigned char* outbuf /*in*/, int* outlen /*in out*/)
{
	if (outbuf == NULL || outlen == NULL)
	{
		return -1;
	}
	*outlen = this->len;
	strncpy((char*)outbuf, (char*)p,  this->len);
	return 0;
}


//客户端释放资源
int CSckFactoryImp1::cltSocketDestory()
{
	if (p != NULL)
	{
		delete[]p;
	}
	return 0;
}
