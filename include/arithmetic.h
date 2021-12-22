#ifndef _ARITHMETIC_
#define _ARITHMETIC_

#include <string>
#include <vector>
#include <iostream>
#include "stack.h"
using namespace std;
class Lexem
{
private:
	string oper;
	double value;
	bool istype;
public:
	Lexem() {};
	Lexem(const double& t_value) {
		value = t_value;
		istype = true;
	}
	Lexem(const char& t_operation) {
		oper = t_operation;
		istype = false;
	}
	Lexem(const string & t_operation) {
		oper = t_operation;
		istype = false;
	}
	void printLex() {
		if (istype) {
			cout << value << " ";
		}
		else {
			cout << oper << " ";
		}
	}
	double GetValue() {
		return value; 
	}
	string GetOperation() { 
		return oper; }
	bool GetType() { 
		return istype; 
	}
	bool operator==(const Lexem&x)const
	{
		if (istype == x.istype && istype==true)
		{
			if(value == x.value)
			{
				return(true);}
			else 
			{
				return(false); 
			}
		}
		else if (istype == x.istype && istype == false)
		{
			if (oper == x.oper)
			{
				return(true);
			}
			else
			{
				return(false);
			}
		}
	}
	bool operator!=(const Lexem&x)const
	{
		if ((*this) == x)
			return(false);
		else
			return(true);
	}
	int priority();
};
class Arithmetic
{
private:
	vector<Lexem> lexm;
public:
	Arithmetic() {};
	void vectorLexem(string& str);
	void Postfix();
	double calculation();
	void print() {
		for (int i = 0; i < lexm.size(); i++) {
			Lexem lexeme(lexm[i]);
			lexeme.printLex();
		}
	}
	void PutVariable(Arithmetic& s)
	{
		double x,y,z;
		for (int i = 0; i < s.lexm.size(); i++)
		{
			if ((s.lexm[i].GetOperation() == "x"))
			{
				cout << "Enter x" << endl;
				cin >> x;
				if (cin.fail())
				{
					throw "Incorrect input.";
				}
				break;
				
			}	
		}
		for (int i = 0; i < s.lexm.size(); i++)
		{
			if ((s.lexm[i].GetOperation() == "y"))
			{
				cout << "Enter y" << endl;
				cin >> y;
				if (cin.fail())
				{
					throw "Incorrect input.";
				}
				break;

			}

		}
		for (int i = 0; i < s.lexm.size(); i++)
		{
			if ((s.lexm[i].GetOperation() == "z"))
			{
				cout << "Enter z" << endl;
				cin >> z;
				if (cin.fail())
				{
					throw "Incorrect input.";
				}
				break;

			}

		}
		for (int i = 0; i < s.lexm.size(); i++)
		{
			if ((s.lexm[i].GetOperation() == "x"))
			{
				Lexem A(x);
				s.lexm[i] = A;

			}
			if ((s.lexm[i].GetOperation() == "y"))
			{
				Lexem A(y);
				s.lexm[i] = A;

			}
			if ((s.lexm[i].GetOperation() == "z"))
			{
				Lexem A(z);
				s.lexm[i] = A;

			}

		}
	}
	bool checkBrackets();
    bool Correct();
};

#endif 

