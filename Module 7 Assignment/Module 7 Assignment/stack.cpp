/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Ryan Milrad
TOTAL POINTS:  25
DUE DATE:  10/20/2020
COURSE:  COP 3530
Assignment Name:  Assignment#5
Professor:  Dr. Bullard

Description: functin definitions for the stack class assignment
******************************************************************************************************************************************************/



#include "stack.h"

//default constructor
stack::stack() {
	//initiate node pointer top to an empty stack
	top = NULL;
}

//deconstructor, delete dynamic memory when out of scope
stack::~stack() {
	//loop through stack until top points to no more nodes
	while (top != NULL) {
		pop();
	}
}

//explicit value constructor
void stack::evaluate(const string& s) {
	//initialize top to nothing
	//create string variables for collecting temporary popped strings
	string left, right;
	if ((s == " " )|| (s == "")) {
		cout << endl;
		return;
	}
	for (int i = 1; i < int(s.length()); i += 2) {
		if (s[i] != ' ') {
			cout << "invalid expression" << endl;
			return;
		}
	}
	//parse string
	for (int i = 0; i < int(s.length()); i++) {
		//if char is a string, push into stack
		if (isalpha(s[i])) {
			push(string(1, s[i]));
		}
		//if operator
		else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
			if (top == 0) {
				cout << "too many operators" << endl;
				return;
			}
			//check if empty and pop first operand
			right = first();
			if (top->next == NULL) {
				cout << "too many operators" << endl;
				return;
			}
			pop();
			//repeat for left
			left = first();
			pop();
			//stack should push new expression into stack
			push("(" + left + " " + s[i] + " " + right + ")");
		}
		else {
			continue;
		}
	}
	//print final stack if all correct
	this->print();
}

//return the expression from the top node
string stack::first() {
	if (top == 0) {
		cout << "no expressions in stack" << endl;
		exit(-1);
	}
	return top->expression;
}

//pop function, pops the top node out of the stack and moves the top pointer to next node in stack
void stack::pop() {
	//if the stack is empty and no node to pop from the list
	if (top == 0) {
		cout << "too many operators" << endl;
		return;
	}
	//else pop node and move on
	node* temp;
	if (top != 0) {
		temp = top;
		top = top->next;
		delete temp;
	}
}

//push function, pushes string into new node into the stack and points top to the newly created node
void stack::push(const string& s) {
	//create temporary node
	node* temp = new node;
	//set the expression to passed string and next node to current top
	temp->expression = s;
	temp->next = top;
	//move top to the new node created
	top = temp;
}

//print function to print the final infix expression
void stack::print() {
	if (top->next != NULL) {
		cout << "too many operands" << endl;
		return;
	}
	cout << top->expression << endl;
}

