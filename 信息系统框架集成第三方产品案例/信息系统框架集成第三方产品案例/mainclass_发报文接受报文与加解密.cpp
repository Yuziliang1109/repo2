#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"CSocketProtcol.h"
#include"CSckFactoryImp1.h"
#include"CSckFactorymp2.h"
#include"CEncDesProtoocol.h"
#include"HwEncDec.h"

int SocketSendRec02(CSocketProtcol* cs, CEncDesProtoocol* ce, unsigned char* buf, int len, unsigned char* outbuf, int* outlen)
{
	int ret = 0;
	unsigned char cryptdata[4096] = { 0 };
	int cryptdatalen = 0;
	ret = cs->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}
	ret = ce->EncData(buf, len, cryptdata, &cryptdatalen);
	cout << cryptdata << cryptdatalen << endl;
	if (ret != 0)
	{
		goto End;
	}
	ret = cs->cltSocketSend(cryptdata, cryptdatalen);
	if (ret != 0)
	{
		goto End;
	}
	ret = cs->cltSocketRev(cryptdata, &cryptdatalen);
	if (ret != 0)
	{
		goto End;
	}

	ret = ce->DeccData(cryptdata, cryptdatalen, outbuf, outlen);
	//cout << outbuf << outlen << endl;
	if (ret != 0)
	{
		goto End;
	}
End:
	ret = cs->cltSocketDestory();
	return 0;
}
void deleteF02(CSocketProtcol* cs, CEncDesProtoocol* ce)
{
	delete cs;
	delete ce;
}
int main01()
{
	int ret = 0;
	CSocketProtcol* cs = NULL;
	CEncDesProtoocol* ce = NULL;
	unsigned char buf[4096] = { 0 };
	int len;
	unsigned char outbuf[4096] = { 0 };
	int outlen = 0;
	strcpy((char*)buf, "dfwegwrtgrwtgrtgwgwtrg");
	len = 7;
	//cs = new CSckFactoryImp1;
	cs = new CSckFactorymp2;
	ce = new HwEncDec;
	ret = SocketSendRec02(cs, ce, buf, len, outbuf, &outlen);
	if (ret != 0)
	{
		cout << "SocketSendRec()err:" << ret << endl;
		return ret;
	}
	cout << outbuf << outlen << endl;

	deleteF02(cs, ce);//ÐéÎö¹¹º¯ÊýÏ¸½Ú

	//delete cs;
	system("pause");
	return ret;
}