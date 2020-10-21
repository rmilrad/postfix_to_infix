/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Ryan Milrad
TOTAL POINTS:  25
DUE DATE:  10/20/2020
COURSE:  COP 3530
Assignment Name:  Assignment#5
Professor:  Dr. Bullard

Description:  header for the stack class assignment
******************************************************************************************************************************************************/



#pragma once

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <iomanip>
#include <string>
#include <string.h>
using namespace std;

class node {
public:
	string expression;
	node* next = 0;
};

class stack {
public:
	stack();
	~stack();
	void evaluate(const string& s);
	string first();
	void pop();
	void push(const string& s);
	void print();
private:
	node* top;
};


#endif STACK_H
