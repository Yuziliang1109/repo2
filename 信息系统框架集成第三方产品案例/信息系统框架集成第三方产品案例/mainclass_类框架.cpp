#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"CSocketProtcol.h"
#include"CSckFactoryImp1.h"
#include"CSckFactorymp2.h"
#include"CEncDesProtoocol.h"
#include"HwEncDec.h"

//多继承在抽象类中的使用         
//框架类有两个实现方法：多继承        组合也可以
class AAAAAAA
{
public:
	AAAAAAA(CSocketProtcol* cs, CEncDesProtoocol* ce)
	{
		this->cs = cs;
		this->ce = ce;
	}
	~AAAAAAA()
	{

	}

	int SocketSendRec( unsigned char* buf, int len, unsigned char* outbuf, int* outlen)
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
	void deleteF()
	{
		delete cs;
		delete ce;
	}
private:
	CSocketProtcol* cs ;
	CEncDesProtoocol* ce;
};

int main()
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
	AAAAAAA* aa = new AAAAAAA(cs, ce);
	ret=aa->SocketSendRec(buf, len, outbuf, &outlen);
	//ret = SocketSendRec(cs, ce, buf, len, outbuf, &outlen);
	if (ret != 0)
	{
		cout << "aa->SocketSendRec()err:" << ret << endl;
		return ret;
	}
	cout << outbuf << outlen << endl;
	aa->deleteF();
	//deleteF(cs, ce);//虚析构函数细节

	delete aa;
	system("pause");
	return ret;
}