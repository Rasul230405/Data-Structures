/*
    This file contains implementation of deque data structure
*/

#include <iostream>
#define SIZE 128
using namespace std;

class deque {
private:
    int A[SIZE];
    int front;
    int rear;
public:

    deque() : front(-1), rear(-1) { };
    void insert_at_front(int data);
    void insert_at_rear(int data);
    void delete_at_front();
    void delete_at_rear();
    bool empty(); 
    int get_rear();
    int get_front();
};

int main()
{
    deque d;
    d.insert_at_rear(5);
    d.insert_at_rear(6);
    d.insert_at_front(8);
    d.delete_at_front();
    cout << d.get_front();  // 5
}

void deque::insert_at_front(int data)
{
    if (empty()) {
        front = rear = 0;
        A[front] = data;
        return;
    }
    if (front < 1) {
        front = SIZE - 1;
        A[front] = data;
    }
    else {
        front -= 1;
        A[front] = data;
    }
}

void deque::insert_at_rear(int data)
{
    if (empty()) {
        front = rear = 0;
        A[rear] = data;
        return;
    }
    if (rear == SIZE - 1) {
        rear = 0;
        A[rear] = data;
    }
    else {
        rear += 1;
        A[rear] = data;
    }
}

void deque::delete_at_front()
{
    if (empty()) return;
    if (front == rear) {
        front = rear = -1;
        return;
    }
    if (front == SIZE - 1) {
        front = 0;
        return;
    }
    ++front;
}

void deque::delete_at_rear()
{
    if (empty()) return;
    if (front == rear) {
        front = rear = -1;
        return;
    }
    if (rear == 0) {
        rear = SIZE - 1;
        return;
    }
    --rear;
    
}

bool deque::empty()
{
    if (front == -1) return true;
    return false;
}

int deque::get_rear()
{
    if (empty()) cerr << "deque is empty\n";
    else return A[rear];
}

int deque::get_front()
{
    if (empty()) cerr << "deque is empty\n";
    else return A[front];
}
