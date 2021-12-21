#include "../include/arithmetic.h"
#include <cmath>
void Arithmetic::vectorLexem(string& str)
{
	string stringnum;
	double doublenum;
	int i = 0;
	while (i < str.length()) {
		if (str[i] == ' ') i++;
		if (str[i] == '+' || str[i] == '*' || str[i] == '/') 
		{ 
			Lexem operation(str[i]);
			lexm.push_back(operation);
			i++;
		}
		else if (str[i] == '-') 
		{
			if (i == 0) {
				Lexem unar_minus('_');
				lexm.push_back(unar_minus);
				i++;
				continue;
			}
			if (i > 0) 
			{
				if (lexm[lexm.size()-1].GetOperation() != ")" && lexm[lexm.size() - 1].GetType() == false && lexm[lexm.size() - 1].GetOperation() != "x" && lexm[lexm.size() - 1].GetOperation() != "y" && lexm[lexm.size() - 1].GetOperation() != "z") {
					Lexem unar_minus('_');
					lexm.push_back(unar_minus);
					i++;
				}
				else {
					Lexem minus('-');
					lexm.push_back(minus);
					i++;
				}
			}
		}
		else if (str[i] >= '0' && str[i] <= '9' || (str[i] == '.')) 
		{ 
			int pointCounter = 0;
			while (str[i] >= '0' && str[i] <= '9' || (str[i] == '.')) 
			{
				stringnum += str[i];
				i++;
				if (str[i] == '.') {
					pointCounter++;
				}
				if (pointCounter > 1) {
					throw "You have more than one point in the number";
				}
			}
			doublenum = stof(stringnum);
			Lexem number(doublenum);
			lexm.push_back(number);
			stringnum.clear(); 
		}
		else if ((str[i] == 'x') || (str[i] == 'y')|| (str[i] == 'z'))
		{
			Lexem A(str[i]);
			lexm.push_back(A);
			i++;
		}
		else if (str[i] == ')' || str[i] == '(') {
			Lexem bracket(str[i]);
			lexm.push_back(bracket);
			i++;
		}
		else { cout << str[i] << endl; throw "error symbol"; break; }
		
	}
}
void Arithmetic::Postfix()
{
	vector <Lexem> postfix;
	TStack <Lexem> operations;
	for (int i = 0; i < lexm.size(); i++)
	{
		if (lexm[i].GetType() == true|| (lexm[i].GetOperation() == "x") || (lexm[i].GetOperation() == "y") || (lexm[i].GetOperation() == "z"))
		{ 
			postfix.push_back(lexm[i]); 

		}
		else 
		{
			if (lexm[i].GetOperation() == "(") 
			{
				operations.push(lexm[i]);
				continue;
			}
			else if (lexm[i].GetOperation() == ")") 
			{
				while (operations.getTop().GetOperation() != "(") 
				{
					postfix.push_back(operations.pop());
				}
				operations.pop(); 
				continue;
			}

			if (i > 0 && lexm[i].GetOperation() == "_")
			{
				operations.push(lexm[i]);
			}
			else {
				while (!operations.isEmpty() && operations.getTop().priority() >= lexm[i].priority()) 
				{
					postfix.push_back(operations.pop());
				}
				operations.push(lexm[i]);
			}
		}
	}
	while (!operations.isEmpty()) 
	{
		postfix.push_back(operations.pop());
	}
	lexm = postfix;
}
double Arithmetic::calculation()
{
	TStack <Lexem> stack;
	Lexem lexOp1, lexOp2;
	double op1, op2, res;
	for (int i = 0; i < lexm.size(); i++) {
		if (lexm[i].GetType() == true) {
			stack.push(lexm[i].GetValue());
		}
		else if (lexm[i].GetOperation() == "_") {
			res = (-1.0) * stack.pop().GetValue();
			stack.push(res);
			continue;
		}
		else {
			lexOp2 = stack.pop();
			lexOp1 = stack.pop();
			op1 = lexOp1.GetValue();
			op2 = lexOp2.GetValue();
			if (lexm[i].GetOperation() == "+")
				res = op1 + op2;
			if (lexm[i].GetOperation() == "-")
				res = op1 - op2;
			if (lexm[i].GetOperation() == "*")
				res = op1 * op2;
			if (lexm[i].GetOperation() == "/") {
				if (op2 == 0) throw "You can't divide by zero";
				res = op1 / op2;
			}

			stack.push(res);
		}
	}
	Lexem result = stack.pop();
	return result.GetValue();
}
bool Arithmetic::checkBrackets()
{
	bool flag = true;
	int count = 0 ;
	for (int i = 0; i < lexm.size(); i++) {
		if (lexm[i] == '(') {
			count++;
			flag = false;
			if ((i < lexm.size() - 1) && (lexm[i + 1] == '+' || lexm[i + 1] == '-' || lexm[i + 1] == '*' || lexm[i + 1] == '/')) {
				throw "Operation after opening bracket";
			}
			if ((i < lexm.size() - 1) && (lexm[i + 1] == ')' )) {
				throw "You have empty brackets";
			}
			if (i > 0 &&(lexm[i - 1].GetType()||lexm[i - 1].GetOperation()=="x" || lexm[i - 1].GetOperation() == "y"|| lexm[i - 1].GetOperation() == "z")) {
				throw "Number before opening bracket";
			}
		}
		if (lexm[i] == ')') 
		{
			if ((i < lexm.size() - 1) && (lexm[i + 1] == '(')) {
				throw "Opening bracket after closing bracket";
			}
			if (i > 0 && lexm[i - 1].GetType()==false && lexm[i - 1] != ')' && lexm[i - 1].GetOperation() != "x" && lexm[i - 1].GetOperation() != "y" && lexm[i - 1].GetOperation() != "z") {
				throw "Operation before closing bracket";
			}
			if ((i < lexm.size() - 1) && (lexm[i + 1].GetType() == true || lexm[i - 1].GetOperation() == "x" || lexm[i - 1].GetOperation() == "y" || lexm[i - 1].GetOperation() == "z")) {
				throw "Number after closing bracket";
			}

			count--;
			flag = true;
		}
	}
	return (flag == true && count == 0);
}
bool Arithmetic::Correct()
{
	if (!checkBrackets()) {
		throw "You have wrong Bracket in your expression ";
	}
	else if (lexm[0] == '+' || lexm[0] == '*' || lexm[0] == '/') {
		throw "Operation is on the first place in the expression";
	}
	else if (lexm[lexm.size() - 1] == '+' || lexm[lexm.size() - 1] == '-' || lexm[lexm.size() - 1] == '*' || lexm[lexm.size() - 1] == '/') {
		throw "Operation is at the end of the expression";
	}
	else {
		for (int i = 0; i < lexm.size(); i++)
	{
			if ((i > 0) && (lexm[i-1].GetOperation() == "+" || lexm[i-1].GetOperation() == "*" || lexm[i-1].GetOperation() == "/") && lexm[i-1].GetOperation()!=")" && (lexm[i].GetOperation() == "+" || lexm[i].GetOperation() == "*" || lexm[i].GetOperation() == "/")) {
				throw "Operation after operation";
			}
			else if((i > 0)&& (lexm[i - 1].GetType() == true && lexm[i].GetType() == true) ){
				throw "Lost operation";
			}
			else if((i > 0)&& (lexm[i - 1].GetOperation() == "x" || lexm[i - 1].GetOperation() == "y" || lexm[i - 1].GetOperation() == "z")&& (lexm[i].GetOperation() == "x" || lexm[i].GetOperation() == "y" || lexm[i].GetOperation() == "z")){
				throw "Lost operation";
			}

	}
		return true;
	
	};

}
int Lexem::priority()
{
	if (oper == ")")  return 0;
	else if (oper == "(") return 1;
	else if (oper == "-") return 2;
	else if (oper == "+") return 2;
	else if (oper == "*") return 3;
	else if (oper == "/") return 3;
	else if (oper == "_") return 4;//unar minus
	else throw "error operation";
}
