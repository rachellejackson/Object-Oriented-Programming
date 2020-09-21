#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "employee.h"
#include "salariedemployee.h"

using namespace std;

//Getting information from file
SalariedEmployee::SalariedEmployee(ifstream& in) :Employee(in) {
	if (!in.is_open()) {
		throw runtime_error("Couldn't open file for input");
	}
	string line;

	getline(in, line);
	salary = stod(line);
}

SalariedEmployee::SalariedEmployee(int empNum, string name, string address, string phone, double salary) : Employee(empNum, name, address, phone) {
	this->salary = salary;
}

//getter
double SalariedEmployee::getSalary() {
	return salary;
}

//setter
void SalariedEmployee::setSalary(double) {
	this->salary = salary;
}

//functions
//Calculates Pay
double SalariedEmployee::calcPay() const {

	double netPay;

	netPay = salary * 0.6726;

	return netPay;
}

//Prints check
void SalariedEmployee::printCheck() const {
	Employee::printCheck();
	cout << "Salary: " << salary;
}

//prints information to file 
void SalariedEmployee::write(ofstream& out) {

	Employee::write(out);

	out << getSalary() << endl;
}
