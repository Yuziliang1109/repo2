#include "CSckFactorymp2.h"


int CSckFactorymp2::cltSocketInit( /*out*/)
{
	p = NULL;
	len = 0;
	return 0;
}

//�ͻ��˷�����
 int CSckFactorymp2::cltSocketSend(unsigned char* buf /*in*/, int len /*in*/)
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

//�ͻ����ձ���
int CSckFactorymp2::cltSocketRev(unsigned char* outbuf /*in*/, int* outlen /*in out*/)
{
	if (outbuf == NULL || outlen == NULL)
	{
		return -1;
	}
	*outlen = len;
	memcpy(outbuf, p, len);
	return 0;
}

//�ͻ����ͷ���Դ
int CSckFactorymp2::cltSocketDestory()
{
	if (p != NULL)
	{
		delete[]p;
	}
	return 0;
}