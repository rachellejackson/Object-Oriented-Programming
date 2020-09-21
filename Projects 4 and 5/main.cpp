#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "employee.h"
#include "hourlyemployee.h"
#include "salariedemployee.h"
using namespace std;

int main()
{
	//Show user the menu options and get input
	cout << "This program has two options:" << endl;
	cout << "1 - Create a data file, or" << endl;
	cout << "2 - Read data from a file and print paychecks." << endl;
	cout << "Please enter (1) to create a file or (2) to print checks :" << endl;

	int option = -1;
	cin >> option;
	cin.clear();
	cin.ignore(1024, '\n');

	//Option 1: Write to a file
	if (option == 1)
	{
		//Prompt for a file name and create employees
		string fileName;
		cout << "Please enter a file name: " << endl;
		getline(cin, fileName);

		vector<Employee*> payroll;
		payroll.push_back(new HourlyEmployee(1, "H. Potter", "Privet Drive", "201-9090", 12.00, 45.0));
		payroll.push_back(new SalariedEmployee(2, "A. Dumbledore", "Hogwarts", "803-1230", 1200));
		payroll.push_back(new HourlyEmployee(3, "R. Weasley", "The Burrow", "892-2000", 10.00, 35.0));
		payroll.push_back(new SalariedEmployee(4, "R. Hagrid", "Hogwarts", "910-8765", 1000));

		//Write employees to a file
		try
		{
			//===================================================================
			/* Use the fileName and payroll variables created above to open a
			 * file output stream, write the employees' data to the file using
			 * each object's write method, and close the file stream.
			 */
			 //YOUR CODE STARTS HERE
			ofstream outFS;
			outFS.open(fileName);

			for (unsigned int i = 0; i < payroll.size(); ++i) {
				payroll.at(i)->write(outFS);
			}
			
			outFS.close();

			 //YOUR CODE ENDS HERE
			 //===================================================================
			cout << "Data file created ... you can now run option 2." << endl << endl;
		}
		catch (runtime_error& e)
		{
			cout << e.what() << endl;
		}

		//Clean up payroll
		for (unsigned int i = 0; i < payroll.size(); i++)
		{
			delete payroll.at(i);
		}
		payroll.clear();
	}
	//Option 2: Read from a file
	else if (option == 2)
	{
		//Prompt for a file name
		string fileName;
		cout << "Please enter a file name: " << endl;
		getline(cin, fileName);

		vector<Employee*> payroll;

		//Read employees from a file (assumes 4 employees, ordered Hourly Salaried Hourly Salaried)
		try
		{
			//===================================================================
			/* Use the fileName and payroll variables above to open a file input
			 * stream, read 4 employees' data from the file using the
			 * HourlyEmployee and SalariedEmployee classes' ifstream&
			 * constructors methods, add the employees to the payroll, print the
			 * check of each employee using the printCheck method, and close the
			 * file stream.
			 */
			 //YOUR CODE STARTS HERE
			ifstream input(fileName);

			payroll.push_back(new HourlyEmployee(input));
			payroll.push_back(new SalariedEmployee(input));
			payroll.push_back(new HourlyEmployee(input));
			payroll.push_back(new SalariedEmployee(input));

			for (unsigned int i = 0; i < payroll.size(); ++i) {

				payroll.at(i)->printCheck();
			}

			input.close();

			 //YOUR CODE ENDS HERE
			 //===================================================================
		}
		catch (runtime_error& e)
		{
			cout << e.what() << endl;
		}

		//Clean up payroll
		for (unsigned int i = 0; i < payroll.size(); i++)
		{
			delete payroll.at(i);
		}
		payroll.clear();
	}
	//Invalid option
	else
	{
		cout << "Invalid menu input" << endl;
	}

	return 0;
}
