#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "itcast_comm.h"
//#include "memwatch.h"
#include "itcastlog.h"

/*
���涨����һ��socket�ͻ��˷��ͱ��Ľ��ܱ��ĵ�api�ӿ�
��д�����׽ӿ�api�ĵ��÷���
*/

/*
1 �Ȱѻ������ʵ�� �汾����
2 �ڴ�й¶���
3 ��־
4 �汾�Ż�
*/
//�����ײ�⣨�����ӿڣ����ṩ����һ�ֻ��� ��������ĳ�־���Ĳ��ԡ�
typedef int (*EncData)(unsigned char* inData, int inDataLen, unsigned char* outData, int* outDataLen);


typedef struct _SCK_HANDLE 
{
	char		version[16];
	char		serverip[16];
	int		serverport;
	unsigned char *	buf ;
	int				buflen;
	EncData			myEncData;

}SCK_HANDLE;


//�ͻ��˳�ʼ��
ITCAST_FUNC_EXPORT(int)
cltSocketInit(void **handle) //5day after
{
	SCK_HANDLE		*sh = NULL;
	int				rv = 0;

	ITCAST_LOG(__FILE__, __LINE__,LogLevel[1], rv,"func cltSocketInit() Begin");

	if (handle == NULL)
	{
		rv = -1;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketInit(): check handle == NULL [%d]", rv);
		return rv;
	}
	//�����ڴ沢��ʼ��
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		rv = -2;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketInit(): malloc err [%d]", rv);
		return rv;
	}
	memset(sh, 0, sizeof(SCK_HANDLE));

	//��ֵ
	strcpy(sh->version, "0.0.1");
	strcpy(sh->serverip, "192.168.0.211");
	sh->serverport = 8888;

	//����
	*handle = sh;

	ITCAST_LOG(__FILE__, __LINE__,LogLevel[1], rv,"func cltSocketInit() End");

	return rv;
}
/*
//�ͻ��˷�����
ITCAST_FUNC_EXPORT(int)
cltSocketSendAndEnc(void* handle, EncData myEncDatafuncback, unsigned char* buf, int buflen)
{
	int				rv = 0;
	SCK_HANDLE		*sh = NULL;
	char data[4096] = { 0 };
	int datalen = 0;
	if (handle == NULL)
	{
		rv = -4;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend(): check handle == NULL [%d]", rv);
		return rv;
	}
	if (buf == NULL || buflen<=0)
	{
		rv = -5;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend(): (buf == NULL || len<=0) [%d]", rv);
		return rv;
	}
	if (myEncDatafuncback==NULL)
	{
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], rv, "myEncDatafuncback==NULL [%d]", rv);
		return rv;
	}
	rv = myEncDatafuncback(buf, buflen, data, &datalen);
	if (rv != 0)
	{
		rv = -6;
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], rv, "func myEncDatafuncback()[%d]", rv);
		return rv;
	}


	sh = (SCK_HANDLE *)handle;
	sh->buf = (unsigned char *)malloc(sizeof(char)* datalen);
	if (sh->buf == NULL)
	{
		rv = -7;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend() buflen:%d)", buflen);
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend() check (handle->buf == NULL)) [%d]", rv);
		return rv;
	}

	//�ѷ��͵ı������ݣ��洢 handle ������֮��
	memcpy(sh->buf, data, datalen);
	sh->buflen = datalen;

	return rv;
}*/

ITCAST_FUNC_EXPORT(int)
cltSocketSendAndEnc2(void* handle, unsigned char* buf, int buflen)
{
	int				rv = 0;
	SCK_HANDLE* sh = NULL;
	char data[4096] = { 0 };
	int datalen = 0;
	if (handle == NULL)
	{
		rv = -4;
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], rv, "func cltSocketSend(): check handle == NULL [%d]", rv);
		return rv;
	}
	if (buf == NULL || buflen <= 0)
	{
		rv = -5;
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], rv, "func cltSocketSend(): (buf == NULL || len<=0) [%d]", rv);
		return rv;
	}



	sh = (SCK_HANDLE*)handle;
	if (sh->myEncData == NULL)
	{
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], rv, "sh->myEncData == NULL [%d]", rv);
		return rv;
	}
	rv = sh->myEncData(buf, buflen, data, &datalen);
	if (rv != 0)
	{
		rv = -6;
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], rv, "func  sh->myEncData()[%d]", rv);
		return rv;
	}
	sh->buf = (unsigned char*)malloc(sizeof(char) * datalen);
	if (sh->buf == NULL)
	{
		rv = -7;
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], rv, "func cltSocketSend() buflen:%d)", buflen);
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], rv, "func cltSocketSend() check (handle->buf == NULL)) [%d]", rv);
		return rv;
	}

	//�ѷ��͵ı������ݣ��洢 handle ������֮��
	memcpy(sh->buf, data, datalen);
	sh->buflen = datalen;

	return rv;
}
//�ͻ����ձ���
ITCAST_FUNC_EXPORT(int)
cltSocketRev(void *handle, unsigned char *buf, int *buflen)
{
	int			rv = 0;
	SCK_HANDLE	*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev: check handle == NULL [%d]", rv);
		return rv;
	}
	if (buflen == NULL)
	{
		rv = -5;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev: (buflen == NULL) [%d]", rv);
		return rv;
	}

	sh = (SCK_HANDLE *)handle;

	//��ֵ ���������е����ݣ�copy��buf�ռ���
	//֧�ֶ��ε��ã���һ�ε����󳤶� �ڶ��ε��ÿ��԰�����copy buf��
	if (buf != NULL)
	{
		memcpy(buf, sh->buf, sh->buflen);
		//buf[ci->buflen] = '\0';
	}
	*buflen = sh->buflen;

	return rv;
}
//�ͻ����ͷ���Դ
ITCAST_FUNC_EXPORT(int)
cltSocketDestory(void *handle)
{
	SCK_HANDLE *sh = NULL;
	sh = handle; 
	if (sh != NULL)
	{
		free(sh->buf);
		free(sh);
	}
	return 0;
}

/////////////////�ڶ���apiʵ��/////////////////////////////////////////////////


//�ͻ��˳�ʼ��
ITCAST_FUNC_EXPORT(int)
cltSocketInit2(void **handle) //5day after
{
	SCK_HANDLE		*sh = NULL;
	int				rv = 0;

	ITCAST_LOG(__FILE__, __LINE__,LogLevel[1], rv,"func cltSocketInit2() Begin");

	if (handle == NULL)
	{
		rv = -1;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketInit2(): check handle == NULL [%d]", rv);
		return rv;
	}
	//�����ڴ沢��ʼ��
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		rv = -2;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketInit2(): malloc err [%d]", rv);
		return rv;
	}
	memset(sh, 0, sizeof(SCK_HANDLE));

	//��ֵ
	strcpy(sh->version, "0.0.1");
	strcpy(sh->serverip, "192.168.0.211");
	sh->serverport = 8888;

	//����
	*handle = sh;

	ITCAST_LOG(__FILE__, __LINE__,LogLevel[1], rv,"func cltSocketInit2() End");

	return rv;
}

//�ͻ��˷�����
ITCAST_FUNC_EXPORT(int)
cltSocketSend2(void *handle, unsigned char *buf,  int buflen)
{
	int				rv = 0;
	SCK_HANDLE		*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend2(): check handle == NULL [%d]", rv);
		return rv;
	}
	if (buf == NULL || buflen<=0)
	{
		rv = -5;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend2(): (buf == NULL || len<=0) [%d]", rv);
		return rv;
	}

	sh = (SCK_HANDLE *)handle;
	sh->buf = (unsigned char *)malloc(sizeof(char)*buflen);
	if (sh->buf == NULL)
	{
		rv = -6;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend2() buflen:%d)", buflen);
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend2() check (handle->buf == NULL)) [%d]", rv);
		return rv;
	}

	//�ѷ��͵ı������ݣ��洢 handle ������֮��
	memcpy(sh->buf, buf, buflen);
	sh->buflen = buflen;

	return rv;
}
//�ͻ����ձ���
ITCAST_FUNC_EXPORT(int)
cltSocketRev2(void *handle, unsigned char **buf, int *buflen)
{
	int			rv = 0;
	SCK_HANDLE	*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev2: check handle == NULL [%d]", rv);
		return rv;
	}
	if (buflen == NULL)
	{
		rv = -5;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev2: (buflen == NULL) [%d]", rv);
		return rv;
	}
	sh = (SCK_HANDLE *)handle;


	//�����ڴ����ݴ���
	*buf = (char *)malloc(sh->buflen);
	if (*buf == NULL)
	{
		rv = -6;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev2: (buflen == NULL) [%d]", rv);
		return rv;
	}
	memcpy(*buf, sh->buf, sh->buflen);

	*buflen = sh->buflen;

	return rv;
}

ITCAST_FUNC_EXPORT(int)
cltSocketRev2_Free(unsigned char **buf)
{
	int rv = 0;
	unsigned char * tmp = *buf;
	if (buf == NULL)
	{
		rv = -7;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev2: (buflen == NULL) [%d]", rv);
		return rv;
	}
	if (tmp != NULL)
	{
		free(tmp);
	}
	*buf = NULL;
}

//�ͻ����ͷ���Դ
ITCAST_FUNC_EXPORT(int)
cltSocketDestory2(void **handle)
{
	SCK_HANDLE *sh = NULL;
	sh = *handle; 
	if (sh != NULL)
	{
		free(sh->buf);
		free(sh);
	}
	*handle = NULL;
	return 0;
}
ITCAST_FUNC_EXPORT(int)
cltSocketSetH(void* handle, EncData myEncData)
{
	if (handle == NULL)
	{
		return -1;
	}
	SCK_HANDLE* sh = handle;
	sh->myEncData = myEncData;
	return 0;
}
