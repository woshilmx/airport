#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class AriportRoutes
{
public:
	AriportRoutes();
	AriportRoutes(string endden, string flight, string plane, string planetime, int pangernumber,int remain);
	//���ú������Ϣ
	void setData(string endden, string flight, string plane, string planetime, int pangernumber, int remain);
	string getendden();
	string getflight();
	string getplane();
	string getplanetime();
	int getpangernumber();
	void setremain(int remain);
	int getremain();
	
private:
	string endden;//�յ�վ��
	string flight;//�����
	string plane;//�ɻ���
	string planetime;//��������
	int pangernumber;//��Ա����
	int remain;//��Ʊ��
};
