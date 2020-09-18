#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> homeworkScores(0);

//function that calculates grades

string CalculateLetterGrade(int totalScore) {
	if (totalScore >= 381) {
		return "A";
	}
	else if (totalScore >= 361) {
		return "A-";
	}
	else if (totalScore >= 341) {
		return "B+";
	}
	else if (totalScore >= 321) {
		return "B";
	}
	else if (totalScore >= 301) {
		return "B-";
	}
	else if (totalScore >= 281) {
		return "C+";
	}
	else if (totalScore >= 261) {
		return "C";
	}
	else if (totalScore >= 241) {
		return "C-";
	}
	else if (totalScore >= 221) {
		return "D+";
	}
	else if (totalScore >= 201) {
		return "D";
	}
	else if (totalScore >=  181) {
		return "D-";
	}
	else {
		return "fail";
	}
}

//function that validates examScore is an int and is within 0 and 100
int examValidation(int examScore, string examMessage) {
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Sorry, your input must be an integer. Please try again." << endl;
			cout << examMessage;
			cin >> examScore;
		}
		else if (examScore < 0 || examScore > 100) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Sorry, your input must be between 0 and 100. Please try again." << endl;
			cout << examMessage;
			cin >> examScore;
		}
		else {
			break;
		}
	}
	return examScore; 
}

//function that validates homework score is an int
int homeworkValidation(int homeworkScore, string homeworkMessage) {
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Sorry, your input must be an integer. Please try again." << endl;
			cout << homeworkMessage;
			cin >> homeworkScore;
		}
		else if (homeworkScore < 0 || homeworkScore > 100) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Sorry, your input must be between 0 and 100. Please try again." << endl;
			cout << homeworkMessage << endl;
			cin >> homeworkScore;
		}
		else {
			break;
		}
	}
	return homeworkScore;
}

//function that calculates the median
double FindMedianScore(vector<int>& homeworkScores){
	double median;
	sort(homeworkScores.begin(), homeworkScores.end());
	double lowerMed = homeworkScores.at(homeworkScores.size() / 2 - 1);
	double upperMed = homeworkScores.at(homeworkScores.size() / 2);
	if (homeworkScores.size() == 1) {
		median = homeworkScores.at(0);
	}
	else if (homeworkScores.size() % 2 == 0) {
		median = (upperMed + lowerMed) / 2;
	}
	else {
		median = homeworkScores.at((homeworkScores.size() - 1) / 2);
	}
	return median;
}

void homeworkInput() {
	int homework;
	string homeworkMessage = "Enter the score for a homework assignment: ";
	while (true) {
		cout << homeworkMessage;
		cin >> homework;

		if (homework == -1) {
			break;
		}
		else {
			homework = homeworkValidation(homework, homeworkMessage);
			homeworkScores.push_back(homework);
			homeworkInput();
			break;
		}
	}
}

int main() {
	int firstExam;
	string firstExamMessage = "Please enter in the score for the first exam: "; 
	int secondExam;
	string secondExamMessage = "Please enter in the score for the second exam: ";
	int finalExam;
	string finalExamMessage = "Please enter in the score for the final exam: ";
	int totalScore; 
	double median; 
	
	cout << "Dr. Dolittle's Grading Program ....." << endl;

	while (true) {
		cout << "Please enter in the score for the first exam: ";
		cin >> firstExam;
		firstExam = examValidation(firstExam, firstExamMessage);
		break;
	}

	while (true) {
		cout << "Please enter in the score for the second exam: ";
		cin >> secondExam;
		secondExam = examValidation(secondExam, secondExamMessage);
		break;
	}

	while (true) {
		cout << "Please enter in the score for the final exam: ";
		cin >> finalExam;
		finalExam = examValidation(finalExam, finalExamMessage);
		break;
	}
	
	homeworkInput();
	
	median = FindMedianScore(homeworkScores);

	totalScore = firstExam + secondExam + finalExam + median;

	CalculateLetterGrade(totalScore);

	cout << "The median homework score was " << median << endl;
	cout << "The total points earned was " << totalScore << endl;
	cout << "The letter calculated letter grade is " << CalculateLetterGrade(totalScore);
}
