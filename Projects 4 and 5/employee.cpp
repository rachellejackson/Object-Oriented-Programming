#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "employee.h"

using namespace std;

//Reads in information
Employee::Employee(ifstream& in) {

	if (!in.is_open()) {
		throw runtime_error("Couldn't open file for input");
	}

	in >> empNum;

	if (in.eof())
	{
		throw runtime_error("No data");
	}

	else if (in.fail()) {
		throw runtime_error("Problem with data");
	}
	
	else if (in.bad()) {
		throw runtime_error("Problem with data");
	}

	in.ignore();

	getline(in, name);
	if (in.eof()) {
		throw runtime_error("Problem with data");
	}

	getline(in, address);
	if (in.eof()) {
		throw runtime_error("Problem with data");
	}

	getline(in, phone);
	if (in.eof()) {
		throw runtime_error("Problem with data");
	}
}

//constuctor
Employee::Employee(int empNum, string name, string address, string phone)
{
	this->empNum = empNum;
	this->name = name;
	this->address = address;
	this->phone = phone;
}

//destructor
Employee :: ~Employee() {

}


//Getters definitions
int Employee::getEmpNum() const{
	return empNum;
}
const string& Employee::getName()const {
	return name;
}
const string& Employee::getAddr() const{
	return address;
}
const string& Employee::getPhone() const{
	return phone;
}


//Setters definitions

void Employee::setName(const string& name) {
	this->name = name;
}
void Employee::setAddress(const string& address) {
	this->address = address;
}
void Employee::setPhone(const string& phone) {
	this->phone = phone;
}


//does this need calcPay here?

void Employee::write(ofstream& out) {

	if (!out.is_open()) {
		throw runtime_error("Couldn't open file for input");
	}

	out << getEmpNum() << endl;
	out << getName() << endl;
	out << getAddr() << endl;
	out << getPhone() << endl;
}

void Employee::printCheck() const {
	cout << "....................UVU Computer Science Dept................................." << endl << endl;
	cout << fixed << setprecision(2);
	cout << "Pay to the order of" << getName() << "....................................$" << calcPay() << endl << endl;
	cout << "United Community Credit Union" << endl << ".............................................................................." << endl << endl;
}
