// queue_dt_str.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "queue_arr.h"
#include "queue_ll.h"
using namespace std;

int main()
{
    queue_arr q;
    q.push(5);
    q.push(6);
    cout << "front: " << q.front() << "\n";
    q.pop();
    cout << "front: " << q.front() << "\n";
    q.pop();
    cout << "empty? " << q.empty() << "\n\n";

    queue_ll q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    cout << "front: " << q2.front() << "\n";
    q2.pop();
    cout << "front: " << q2.front() << "\n";
    q2.pop();
    q2.pop();
    cout << "empty? " << q2.empty() << "\n";
}


