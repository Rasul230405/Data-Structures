#pragma once
/*
	This header file contains array-based implementation of queue
	Let's say we have array like this:
	       
	front -> 1 2 3 4 5 6 <- rear
	         0 1 2 3 4 5
			   indexes

	delete operation is implemented on the front side of queue
	insert operation is implemented on the rear side of queue
	deletion:
		increase front index 
	insertion:
		increase rear index and
		put new element rear index of array
  
*/
#define MAX_SIZE 128


class queue_arr {
private:
	int A[MAX_SIZE];
	int rear;     // pushed to index rear
	int f;	  // poped from front index
public:
	queue_arr() : rear(-1), f(-1) { };
	void push(int n); // insert element to the rear side of queue
	void pop();		// delete the element that is on the front of queue
	int front();	// returns the element on the front of queue	
	int empty();	// returns 1 if empty, otherwise 0
};

void queue_arr::push(int n)
{
	if (rear == MAX_SIZE - 1) return;	// if array is full, new element cannot be added
	if (rear == -1) {
		++rear;
		++f;
		A[rear] = n;
	}
	else {
		++rear;
		A[rear] = n;
	}
}

void queue_arr::pop()
{
	if (empty()) return;	// if array is empty, we cannot delete anything
	if (f == rear) f = rear = -1;
	else ++f;
}

int queue_arr::front()
{
	return A[f];
}

int queue_arr::empty()
{
	if (rear == -1) return 1;
	return 0;
}