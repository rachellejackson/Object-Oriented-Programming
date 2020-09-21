#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include <string>
using namespace std;

class HourlyEmployee : public Employee {
private:
	double hourlyWage;
	double hoursWorked;

public:
	HourlyEmployee(ifstream& in);

	//constructor
	HourlyEmployee(int empNum, string name, string address, string phone, double hourlyWage, double hoursWorked);

	//getters
	double getHourlyWage() const;
	double getHoursWorked() const;

	//setters
	void setHourlyWage(double wage);
	void setHoursWorked(double hours);


	//functions
	virtual double calcPay() const override;
	virtual void printCheck() const override;
	virtual void write(ofstream& out) override;
};

#endif
