#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double taxableIncome;
	char marritalStatus;
	double taxesPaid;
	char anotherCalculation;

	cout << "Please enter in your taxable income." << endl;
	cout << "(This must be a positive value):" << endl;
	cin >> taxableIncome;

	while (taxableIncome < 0) {
		cout << endl << "Please enter in your taxable income." << endl;
		cout << "(This must be a positive value):" << endl;
		cin >> taxableIncome;
	}

	cout << "Please enter m if married and filing joint return," << endl;
	cout << "or s if filing a single return:" << endl;
	cin >> marritalStatus;

	while (marritalStatus != 'm' && marritalStatus != 's') {
		cout << "Please enter m if married and filing joint return," << endl;
		cout << "or s if filing a single return:" << endl;
		cin >> marritalStatus;
	}

	if (marritalStatus == 's') {
		if (taxableIncome < 864) {
			taxesPaid = (taxableIncome - 0) * 0.023 + 0;
		}
		else if (taxableIncome < 2589) {
			taxesPaid = (taxableIncome - 863) * 0.033 + 25;
		}
		else if (taxableIncome <= 4313) {
			taxesPaid = (taxableIncome - 2588) * 0.052 + 85;
		}
		else {
			taxesPaid = (taxableIncome - 4313) * 0.075 + 181;
		}
		cout << "Your taxable income is $" << fixed << setprecision(2) << taxableIncome << endl;
		cout << "and you are filing a single return." << endl;
		cout << "Your income tax will be $" << fixed << setprecision(2) << taxesPaid << endl;
	}


	else if (marritalStatus == 'm') {
		if (taxableIncome < 1727) {
			taxesPaid = (taxableIncome - 0) * 0.023 + 0;
		}
		else if (taxableIncome < 5177) {
			taxesPaid = (taxableIncome - 1726) * 0.033 + 40;
		}
		else if (taxableIncome <= 8626) {
			taxesPaid = (taxableIncome - 5176) * 0.052 + 175;
		}
		else {
			taxesPaid = (taxableIncome - 8626) * 0.075 + 390;
		}
		cout << "Your taxable income is $" << fixed << setprecision(2) << taxableIncome << endl;
		cout << "and you are filing a joint return." << endl;
		cout << "Your income tax will be $" << fixed << setprecision(2) << taxesPaid << endl;
	}

	cout << "Would you like to do another calculation (y or n)?" << endl;
	cin >> anotherCalculation;

	while (anotherCalculation != 'y' && anotherCalculation != 'n') {
		cout << endl << "Would you like to do another calculation (y or n)?" << endl;
		cin >> anotherCalculation;
	}

	if (anotherCalculation == 'y') {
		return main();
	}

	return 0;
}
