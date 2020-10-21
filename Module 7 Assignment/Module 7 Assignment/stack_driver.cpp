/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Ryan Milrad
TOTAL POINTS:  25
DUE DATE:  10/20/2020
COURSE:  COP 3530
Assignment Name:  Assignment#5
Professor:  Dr. Bullard

Description:  driver for the stack class assignment
******************************************************************************************************************************************************/




#include "stack.h"


int main() {
	string postfix = "";
	string answer = "y";
	stack s;

	do {
		//cout << "please enter a postfix expression: " << endl;
		getline(cin, postfix);
		s.evaluate(postfix);
		//stack infix = postfix
		cout << "enter another expression? (y/n): ";
		cin >> answer;
		cin.ignore();
	} while (answer == "y" || answer == "Y");
	return 0;
}