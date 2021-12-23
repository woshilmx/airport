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
	//设置航班的信息
	void setData(string endden, string flight, string plane, string planetime, int pangernumber, int remain);
	string getendden();
	string getflight();
	string getplane();
	string getplanetime();
	int getpangernumber();
	void setremain(int remain);
	int getremain();
	
private:
	string endden;//终点站名
	string flight;//航班号
	string plane;//飞机号
	string planetime;//飞行周日
	int pangernumber;//乘员定额
	int remain;//余票量
};
