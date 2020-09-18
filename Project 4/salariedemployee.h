#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H
#include <string>
#include "employee.h"
using namespace std;

class SalariedEmployee : public Employee {
private:
	double salary;

public:
	SalariedEmployee(ifstream&);

	//constructor
	SalariedEmployee(int empNum, string name, string address, string phone, double salary);

	//getter
	double getSalary();

	//setter
	void setSalary(double);

	//functions
	virtual double calcPay() const;
	virtual void printCheck() const;
	virtual void write(ofstream& out);
};

#endif
