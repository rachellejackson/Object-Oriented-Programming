#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "employee.h"
#include "hourlyemployee.h"
using namespace std;

//Getting information from file
HourlyEmployee::HourlyEmployee(ifstream& in): Employee(in) {

	if (!in.is_open()) {
		throw runtime_error("Couldn't open file for input");
	}
	string line;

	getline(in, line);
	hourlyWage = stod(line);

	getline(in, line);
	hoursWorked = stod(line);
}

//constructor
HourlyEmployee::HourlyEmployee(int empNum, string name, string address, string phone, double hourlyWage, double hoursWorked) : Employee(empNum, name, address, phone) {
	this->hourlyWage = hourlyWage;
	this->hoursWorked = hoursWorked;
}

//getters
double HourlyEmployee::getHourlyWage() const {
	return hourlyWage;
}
double HourlyEmployee::getHoursWorked() const {
	return hoursWorked;
}

//setters
void HourlyEmployee::setHourlyWage(double wage) {
	hourlyWage = wage;
}
void HourlyEmployee::setHoursWorked(double hours) {
	hoursWorked = hours;
}

//functions
//Calculates Pay
double HourlyEmployee::calcPay() const {
	double grossPay;
	double netPay;
	double fhoursWorked = getHoursWorked();
	double fhourlyWages = getHourlyWage();

	if (fhoursWorked < 40) {
		grossPay = fhourlyWages * fhoursWorked;
		netPay = 0.725 * grossPay;
	}

	else {
		grossPay = fhourlyWages * (40 + 1.5 * (fhoursWorked - 40));
		netPay = 0.725 * grossPay;
	}

	return netPay;
}

//Prints check
void HourlyEmployee::printCheck() const {
	Employee::printCheck();
	cout << "Hourly wage: " << getHourlyWage() << endl;
	cout << "Hours worked: " << getHoursWorked();
}

//prints information to file 
void HourlyEmployee::write(ofstream& out) {
	Employee::write(out);
	out << getHourlyWage() << endl;
	out << getHoursWorked() << endl;
}
