#ifndef _STACK_
#define _STACK_
#include <stdio.h>
#include <iostream>
const int SIZE = 100;
template <class ValType>
class TStack
{
protected:
	ValType* stack;
	int top;
	int s;
	int elemsize;
public:
	TStack(int n = SIZE);
	~TStack() { delete[]stack; };
	bool isEmpty();
	ValType pop();
	void isFull();
	void push(const ValType& val);
	void clear();
	ValType getTop();
	int size();
};
template <class ValType>
TStack<ValType>::TStack(int n)
{
	if (n <= 0)
	{
		throw "Error length";
	}
	else {
		stack = new ValType[n];
		s = n;
		top = -1;
		elemsize = 0;
	}

}
template <class ValType>
bool TStack<ValType>::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <class ValType>
ValType TStack<ValType>::pop()
{
	if (isEmpty())
	{
		throw ("Stack is empty");
	}
	elemsize--;
	return stack[top--];

}
template <class ValType>
void TStack<ValType>::isFull()
{
    s = (s+1) * 2;
	ValType* newstack = new ValType[s];
	for (int i = 0; i < top+1; i++)
	{
		newstack[i] = stack[i];
	}
	delete[]stack;
	stack = newstack;
}
template <class ValType>
void TStack<ValType>::push(const ValType &val)
{
	if (top >= s - 1)
	{
		isFull();
	}
	
	top++;
	stack[top] = val;
	elemsize++;
}
template <class ValType>
void TStack<ValType>::clear()
{
	elemsize = 0;
	top = -1;
	delete[] stack;
	stack = new ValType[s];
}
template <class ValType>
ValType TStack<ValType>::getTop()
{
	if (isEmpty())
	{
		throw("Stack is empty");
	}
	return stack[top];
}
template <class ValType>
int TStack<ValType>::size()
{
	return elemsize;
}

#endif 
