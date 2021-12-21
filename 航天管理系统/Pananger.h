#pragma once
#include<iostream>
#include<string>
#include"AriportRoutes.h"
using namespace std;
class Pananger {
public:
	Pananger* next;
	Pananger();
	Pananger(string name, int titlenumber,string flight);
	string getNnme();
	string getFlight();
	int getTitlenumber();
	void setName(string name);
	void setFlight(string flight);
	void setTitlenumber(int titlenumber);
	//string getName();
	//string getFlight();
	//AriportRoutes getAriportRoutes();
	
private:
	string name;
	int titlenumber;//¶©Æ±¶î
	string flight;//º½°àºÅ
	
};
