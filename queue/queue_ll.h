#pragma once
/*
	This header file contains linked-list-based implementation of queue
	Let's say we have linked list like this:

	1 -> 2 -> 3 -> NULL
  front      rear

  delete operation is implemented on the front side of queue(linked list)
  insert operation is implemented on the rear side of queue(linked list)
  In this case time complexity of deletion and insertion is O(1)

*/
#include <cstddef>

class Node {
public:
	int data;
	Node* next;
};

class queue_ll {
private:
	Node* f;	// front
	Node* rear;
public:
	queue_ll() :f(NULL), rear(NULL) { };

	void push(int n); // insert element to the rear side of queue
	void pop();		// delete the element that is on the front of queue
	int front();	// returns the element on the front of queue	
	int empty();	// returns 1 if empty, otherwise 0
};

void queue_ll::push(int n)
{
	Node* temp = new Node();
	temp->data = n;
	if (rear == NULL) {
		rear = f = temp;
	}
	else {
		temp->next = rear->next;
		rear->next = temp;
		rear = temp;
	}
}

void queue_ll::pop()
{
	if (f == NULL) return;

	Node* temp = f;
	if (rear == f) {
		rear = f = NULL;
		delete temp;
	}
	else {
		f = temp->next;
		delete temp;
	}
}

int queue_ll::front()
{
	return f->data;
}

int queue_ll::empty()
{
	if (rear == NULL) return 1;
	return 0;
}

