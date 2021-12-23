#include"AriportRoutes.h"
AriportRoutes::AriportRoutes() {

}
AriportRoutes::AriportRoutes(string endden, string flight, string plane, string planetime, int pangernumber,int remain)
{

	this->endden = endden;
	this->flight = flight;
	this->plane = plane;
	this->planetime = planetime;
	this->pangernumber = pangernumber;
	this->remain = remain;
}

void AriportRoutes::setData(string endden, string flight, string plane, string planetime, int pangernumber,int remain) 
{
	this->endden = endden;
	this->flight = flight;
	this->plane = plane;//""
	this->planetime = planetime;
	this->pangernumber = pangernumber;
	this->remain = remain;

}
string AriportRoutes::getendden() {
	return this->endden;
}
string AriportRoutes::getflight() {
	return this->flight;
}
string AriportRoutes::getplane() {
	return this->plane;
}
string AriportRoutes::getplanetime() {
	return this->planetime;
}
int AriportRoutes::getpangernumber() {
	return this->pangernumber;
}
int AriportRoutes::getremain() {
	return this->remain;
}
void AriportRoutes::setremain(int remain) {
	this->remain = remain;
}