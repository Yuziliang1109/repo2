#include "HwEncDec.h"
#include"des.h"
int HwEncDec::EncData(unsigned char* plain, int plainlen, unsigned char* cryptdata, int* cryptdatalen)
{
	int ret = 0;
	ret=DesEnc(plain, plainlen, cryptdata, cryptdatalen);
	if (ret != 0)
	{
		cout << "DesEnc() err:" << ret << endl;
		return ret;
	}
	return ret;
}
int HwEncDec::DeccData(unsigned char* cryptdata, int cryptdatalen, unsigned char* plain, int* plainlen)
{
	int ret = 0;
	ret = DesDec(cryptdata, cryptdatalen, plain, plainlen);
	if (ret != 0)
	{
		cout << "DesDec() err:" << ret << endl;
		return ret;
	}
	return ret;
	return 0;
}