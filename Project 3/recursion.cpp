#include <iostream>
#include "RecursionCounter.h"
using namespace std;


int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

void recursiveHighLowGame(int lower_bound, int upper_bound)
{
	int mid;
	char answer;

	mid = (lower_bound + upper_bound) / 2;

	cout << "Is it " << mid << " (l,y,h) ? " << endl;
	cin >> answer;

	if (upper_bound < lower_bound){
		cout << "You cheated!";
	}

	else if(answer != 'l' && answer != 'h') {
		cout << "Your number is " << mid << endl;
	}

	else {
		
		if(answer == 'h') {
			if (mid - lower_bound == 1) {
				cout << "You cheated!" << endl;
			}
			else if (upper_bound - lower_bound < 3) {
				cout << "Your number is " << mid << endl;
				return;
			}
			else {
				recursiveHighLowGame(lower_bound, mid);
			}
		}
		else {
			if (upper_bound - mid == 1) {
				cout << "You cheated!" << endl;
			}
			else if (upper_bound - lower_bound == 3) {
				cout << "Your number is " << mid + 1 << endl;
				return;
			}
			else {
				recursiveHighLowGame(mid, upper_bound);
			}
		}
	}
	return;
}

void recursiveSort(int data[], int first_index, int last_index)
{
	RecursionCounter rc;

	if (first_index == last_index) {
		return;
	}
	for (int i = first_index; i < last_index + 1; i++) {
		if (data[i] < data[first_index]) {
			int temp = data[first_index];
			data[first_index] = data[i];
			data[i] = temp;
		}
	}
	recursiveSort(data, first_index + 1, last_index);
}

void hilo(int number)
{
	//This is the entry function for the recursiveHighLowGame function.
	cout << "Think of a number between 1 and " << number << endl;
	cout << "I will try and guess it with your help.\n\n";
	recursiveHighLowGame(1, number);
}

void mysort(int data[], int size)
{
	//This is the entry function for the recursiveSort function.
	recursiveSort(data, 0, size - 1);
}

int main() {
	 //Play a guessing game with the user
	hilo(100);
	cout << endl;

	//Create an unsorted array, use mysort() to sort it, and display the result
	int data[] = { 4, 2, 3, 5, 1 };
	mysort(data, 5);
	cout << "Sorted result:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << data[i] << endl;
	}
	cout << endl;
}
