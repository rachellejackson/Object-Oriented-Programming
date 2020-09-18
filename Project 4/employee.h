#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {

private:
	int empNum;
	string name;
	string address;
	string phone;

protected:
	Employee(ifstream& in);

	//constructor
	Employee(int, string, string, string);

public: 

	//destructor
	virtual~Employee();

	//getters
	int getEmpNum() const;
	const string& getName() const;
	const string& getAddr() const;
	const string& getPhone() const;


	//setters
	void setName(const string& name);
	void setAddress(const string& address);
	void setPhone(const string& phone);

	//functions
	virtual double calcPay() const = 0;
	virtual void printCheck() const;
	virtual void write(ofstream& out);
};

#endif
