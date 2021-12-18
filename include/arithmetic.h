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
		double a;
		for (int i = 0; i < s.lexm.size(); i++)
		{
			if (s.lexm[i].GetType()==false && ((s.lexm[i].GetOperation() == "a") || (s.lexm[i].GetOperation() == "b")|| (s.lexm[i].GetOperation() == "z")))
			{
				cout << "Enter a variable" << endl;
				cin >> a;
				Lexem A(a);
				s.lexm[i] = A;
			}
		}
		
	}
	bool checkBrackets();
    bool Correct();
};

#endif 
