#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "socketclientdll.h"

typedef int (*EncData)(unsigned char *inData,int inDataLen,unsigned char *outData,int *outDataLen);

int myEncData(unsigned char *inData,int inDataLen,unsigned char *outData,int *outDataLen)
{
	//
	memcpy(outData, "111111111111111111111111111111111", 10);
	*outDataLen = 10;
	return 0;
}

int main()
{
	int				rv = 0;
	void			*handle = NULL;
	unsigned char	buf[2048];
	int				buflen = 0;

	unsigned char	buf2[2048] = {0};
	int				buflen2 = 0;

	strcpy(buf, "aaaaaaaaaaaaaaaaaaaaaaaaafffffffffffffffffffffff");


	buflen = 10;
	rv = cltSocketInit(&handle);
	if (rv != 0)
	{
		printf("func cltSocketInit():%d", rv);
		return rv;
	}
	/*
	// cvtres.exe
	rv = clitSocket_SetEncFunc(handle, myEncData, NULL, 0);
	if (rv != 0)
	{
		printf("func cltSocketInit():%d", rv);
		goto End;
	}
	*/

	/*
	rv = cltSocketSend(handle, buf,  buflen);
	if (rv != 0)
	{
		printf("func cltSocketSend():%d", rv);
		goto End;
	}
	
	//	int	cltSocketSendAndEnc(void *handle, EncData myEncDatafuncback,unsigned char *buf,  int buflen);
	rv = cltSocketSendAndEnc(handle, myEncData, buf,  buflen);
	if (rv != 0)
	{
		printf("func cltSocketSend_enc():%d", rv);
		goto End;
	}
	*/
	rv= cltSocketSetH(handle, myEncData);
	if (rv != 0)
	{
		printf("func cltSocketSetH():%d", rv);
		goto End;
	}

	rv = cltSocketSendAndEnc2(handle, myEncData, buf, buflen);
	if (rv != 0)
	{
		printf("func cltSocketSend_enc():%d", rv);
		goto End;
	}

	rv = cltSocketRev(handle, buf2 , &buflen2);
	if (rv != 0)
	{
		printf("func cltSocketRev():%d", rv);
		goto End;
	}
	printf("\n%s", buf2);

End:

	rv = cltSocketDestory(handle);
	if (rv != 0)
	{
		printf("func cltSocketDestory():%d", rv);
		return rv;
	}
	system("pause");
	return 0;
}

