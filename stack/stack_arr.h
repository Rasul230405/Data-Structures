/*
	This header file contains array-based implementation of stack
	MAX_SIZE is used as a length of the array for sake of simplicity
*/

#include <iostream>
#define MAX_SIZE 128

template <class T>
class stack_arr {
private:
	T A[MAX_SIZE];
	int t;      // indicates the index of last added element

public:
	stack_arr() :t(-1) { };  // top is assigned value -1 to indicate that the array is empty

	void push(T n);   // add element to stack
	void pop();       // delete element from stack
	T top();		  // return the value of last element in stack
	int IsEmpty();    // returns 1 if stack is empty, 0 if stack is not empty
};

template <class T>
void stack_arr<T>::push(T n)
{
	if (t + 1 == MAX_SIZE) return;    // if stack is full, new element cannot be added
	t += 1;
	A[t] = n;
}

template <class T>
void stack_arr<T>::pop()
{
	if (t == -1) return;             // if stack is empty, we cannot delete anything
	t -= 1;
}

template <class T>
T stack_arr<T>::top()
{
	return A[t];
}

template <class T>
int stack_arr<T>::IsEmpty()
{
	if (t == -1) return 1;
	else return 0;
}
