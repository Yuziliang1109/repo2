#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"CSocketProtcol.h"
#include"CSckFactoryImp1.h"
#include"CSckFactorymp2.h"


int SocketSendRec01(CSocketProtcol* cs,unsigned char* buf,int len,unsigned char *outbuf,int*outlen)
{
	int ret = 0;
	ret=cs->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}
	if (ret != 0)
	{
		goto End;
	}
	ret = cs->cltSocketSend(buf, len);
	if (ret != 0)
	{
		goto End;
	}
	ret = cs->cltSocketRev(outbuf, outlen);
	if (ret != 0)
	{
		goto End;
	}
	if (ret != 0)
	{
		goto End;
	}
	End:
	ret = cs->cltSocketDestory();
	return 0;
}
void deleteF01(CSocketProtcol* cs)
{
	delete cs;

}
int main02()
{
	int ret = 0;
	CSocketProtcol* cs = NULL;
	unsigned char buf[4096] = { 0 };
	int len;
	unsigned char outbuf[4096] = { 0 };
	int outlen = 0;
	strcpy((char*)buf, "dfwegwrtgrwtgrtgwgwtrg");
	len = 7;
	//cs = new CSckFactoryImp1;
	cs = new CSckFactorymp2; 
	ret = SocketSendRec01(cs, buf, len, outbuf, &outlen);
	if (ret != 0)
	{
		cout << "SocketSendRec()err:" << ret << endl;
		return ret;
	}
	cout << outbuf << outlen << endl;
	
	deleteF01(cs);//ÐéÎö¹¹º¯ÊýÏ¸½Ú

	//delete cs;
	system("pause");
	return ret;
}