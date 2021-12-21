#include"Pananger.h"
Pananger::Pananger() {

}
Pananger::Pananger(string name,int titlenumber,string flight) {
	this->name = name;
	this->flight = flight;
	this->titlenumber = titlenumber;
}
string Pananger::getNnme() {
	return this->name;
}
string Pananger::getFlight() {
	return this->flight;
}
void Pananger::setName(string name) {
	this->name = name;

}
void Pananger::setFlight(string flight) {
	this->flight = flight;
}
int  Pananger::getTitlenumber() {
	return this->titlenumber;
}
void  Pananger::setTitlenumber(int titlenumber) {
	this->titlenumber = titlenumber;
}