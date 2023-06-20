#pragma once
/*
	This header file contains linked list-based implementation of stack
*/

#include <iostream>

// creating linked list
template <class T>
class Node {
public:
	T data;
	Node<T>* next;
};

template <class T>
class stack_ll {
private:
	Node<T>* t;		// t refers to top element of stack
public:
	stack_ll() : t(NULL) { };

	void push(T n);		// add element to stack
	void pop();			// delete element from stack
	T top();			// return the value of last element in stack
	int IsEmpty();		// returns 1 if stack is empty, 0 if stack is not empty
};

template <class T>
void stack_ll<T>::push(T n)
{
	Node<T>* temp = new Node<T>();
	temp->data = n;
	temp->next = t;
	t = temp;
}

template <class T>
void stack_ll<T>::pop()
{
	if (IsEmpty()) return;		// if stack is empty, we cannot delete anything
	Node<T>* temp = t;
	t = temp->next;
	delete temp;
}

template <class T>
T stack_ll<T>::top()
{
	if (t == NULL) return 0;
	return t->data;
}

template <class T>
int stack_ll<T>::IsEmpty()
{
	if (t == NULL) return 1;
	return 0;
}

