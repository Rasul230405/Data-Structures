// avl_tree_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <algorithm>
using namespace std;

struct avl {
	int data;
	avl* right;
	avl* left;
};

avl* getNewNode(int data)
{
	avl* t = new avl();
	t->left = NULL;
	t->right = NULL;
	t->data = data;
	return t;
}

class avl_tree {
public:

	avl_tree() {  }
	int height(avl* t);
	int difference(avl* t);
	avl* insert(avl*, int);
	avl* rr_rotate(avl* p);
	avl* ll_rotate(avl* p);
	avl* rl_rotate(avl* p);
	avl* lr_rotate(avl* p);
	avl* balance(avl* p);
	void inorder(avl* t);
};

int avl_tree::height(avl* t)
{
	int h = 0;
	if (t != NULL) {
		int right_height = height(t->right);
		int left_height = height(t->left);
		h = left_height - right_height;
	}
	return h;
}

int avl_tree::difference(avl* t)
{
	int right = height(t ->right);
	int left = height(t->left);
	return left - right;
}

avl* avl_tree::rr_rotate(avl* parent)
{
	avl* t;
	t = parent->right;
	parent->right = t->left;
	t->left = parent;
	return t;
}

avl* avl_tree::ll_rotate(avl* parent)
{
	avl* t;
	t = parent->left;
	parent->left = t->right;
	t->right = parent;
	return t;
}

avl* avl_tree::rl_rotate(avl* parent)
{
	avl* t;
	t = parent->right;
	parent->right = ll_rotate(t);
	return rr_rotate(parent);
}

avl* avl_tree::lr_rotate(avl* parent)
{
	avl* t;
	t = parent->left;
	parent->left = rr_rotate(t);
	return ll_rotate(parent);
}

avl* avl_tree::balance(avl* t)
{
	int balance_factor = difference(t);
	if (balance_factor > 1) {
		if (difference(t->left) > 0) t = ll_rotate(t);
		else t = lr_rotate(t);
	}
	else if (balance_factor < -1) {
		if (difference(t->right) > 0) t = rl_rotate(t);
		else t = rr_rotate(t);
	}
	return t;
}

avl* avl_tree::insert(avl* t, int d)
{
	if (t == NULL) {
		t = new avl;
		t->data = d;
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	if (d < t->data) {
		t->left = insert(t->left, d);
		t = balance(t);
	}
	else if (d >= t->data) {
		t->right = insert(t->right, d);
		t = balance(t);
	}
	return t;
}

void avl_tree::inorder(avl* t) {
	if (t == NULL)
		return;
	inorder(t->left);
	cout << t->data << " ";
	inorder(t->right);
}

int main() {
	avl* k = NULL;
	avl_tree avl;
	k = avl.insert(k, 10);
	k = avl.insert(k, 5);
	k = avl.insert(k, 6);
	avl.inorder(k);
}

