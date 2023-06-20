/*
	main file
	used for several test cases
*/

#include <iostream>
#include "stack_arr.h"
#include "stack_ll.h"

using namespace std;

int main()
{
	stack_arr<double> my_stack;

	my_stack.push(1.24);
	my_stack.push(6.75);
	my_stack.push(8.98);
	cout << my_stack.top() << "\n";

	my_stack.pop();
	cout << my_stack.top();

	cout << "\n";
	stack_ll<char> my_stack2;

	my_stack2.push('a');
	my_stack2.push('b');
	my_stack2.push('c');
	cout << my_stack2.top() << "\n";

	my_stack2.pop();
	cout << my_stack2.top();
}

