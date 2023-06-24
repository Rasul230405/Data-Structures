/*
    This file contains implementation of Binary Search Tree and its main functions
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(NULL), right(NULL) { };
};

bool search(Node* root, int data)
{
    if (root == NULL) return false;
    while (root) {
        if (data > root->data) root = root->right;
        else if (data < root->data) root = root->left;
        else return true;
    }
    return false;
}

vector<int> preorder(Node* root)
{
    vector<int> v;
    if (root == NULL) return v;
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* node = s.top();
        v.push_back(node->data);
        s.pop();

        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
        
    }

    return v;
}


vector<int> breadth_first(Node* root)
{
    vector<int> v;
    if (root == NULL) return v;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        v.push_back(node->data);
        q.pop();

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return v;
}

int find_height(Node* root)
{
    int height_left = 0;
    int height_right = 0;
    if (root == NULL) return -1;
    height_left = find_height(root->left);
    height_right = find_height(root->right);
    return max(height_left, height_right) + 1;
}

Node* find_min(Node* root)
{
    while (root->left != NULL) root = root->left;
    return root;
}

Node* insert(Node* root, int data)
{
    Node* new_node = new Node(data);
    if (root == NULL) root = new_node;
    else if (data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

/*
    There are 3 cases in deletion:
    Node that will be deleted
    1.  has NO child
    2.  has 1 child
    3. have 2 children

    In 3rd case, firstly, we should find the min in right sub-tree and copy its value to targeted node
    Then we delete duplicated node in right sub-tree
*/
Node* Delete(Node* root, int data)
{
    if (root == NULL) return root;
    else if (data <= root->data) root->left = Delete(root->left, data);
    else if (data >= root->data) root->right = Delete(root->right, data);
    else {
        // case 1: no child
        if (root->right == NULL && root->left == NULL) {
            delete root;
            root = NULL;
        }

        // case 2: 1 child
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }

        // case 2: 1 child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }

        // case 3: 2 children
        else {
            Node* temp = find_min(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}


bool bst_util(Node* root, int min_value, int max_value)
{
    if (root == NULL) return true;
    if (root->data >= min_value && root->data <= max_value
        && bst_util(root->left, min_value, root->data)
        && bst_util(root->right, root->data, max_value))
        return true;
    else
        return false;
}

// return true if binary search tree, otherwise false
bool is_binary_search_tree(Node* root)
{
    return bst_util(root, INT_MIN, INT_MAX);
}


// returns the successor of the current node in inorder traversal
Node* get_successor(Node* root, Node* current)
{
    if (root == NULL || current == NULL) return NULL;

    // case 1: Node has right subtree
    if (current->right != NULL) return find_min(current->right);

    // case 2: no right subtree
    else {
        Node* ancestor = root;
        Node* successor = NULL;
        
        while (ancestor != current) {
            if (current->data <= ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right;
        }
        return successor;
    }

}

void print_space(double n, Node* removed)
{
    for (; n > 0; n--) {
        cout << "\t";
    }
    if (removed == nullptr) {
        cout << " ";
    }
    else {
        cout << removed->data;
    }
}

void print_binary_tree(Node* root)
{
    queue<Node*> treeLevel, temp;
    treeLevel.push(root);

    int height = find_height(root) - 1;
    double numberOfElements = pow(2, (height + 1)) - 1;

    int counter = 0;
    while (counter <= height) {
        Node* removed = treeLevel.front();
        treeLevel.pop();

        if (temp.empty()) {
            print_space(numberOfElements
                / pow(2, counter + 1),
                removed);
        }
        else {
            print_space(numberOfElements / pow(2, counter),
                removed);
        }

        if (removed == nullptr) {
            temp.push(nullptr);
            temp.push(nullptr);
        }
        else {
            temp.push(removed->left);
            temp.push(removed->right);
        }

        if (treeLevel.empty()) {
            cout << endl << endl;
            treeLevel = temp;
            while (!temp.empty()) {
                temp.pop();
            }
            counter++;
        }
    }
}


int main()
{
    Node* root = new Node(9);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 15);
    root = insert(root, 12);

    cout << "Tree:\n";
    print_binary_tree(root);
   
    vector<int> v = preorder(root);

    cout << "Preorder Traversal: ";
    for (int n : v) cout << n << " ";
    cout << "\n";

    vector<int> v2 = breadth_first(root);

    cout << "Breadth-first traversal: ";
    for (int n : v2) cout << n << " ";
    cout << "\n";

    cout << "Search(5): ";
    cout << search(root, 5) << "\n";

    cout << "Is binary search tree?(1-yes, 0-no) ";
    cout << is_binary_search_tree(root) << "\n";

    cout << "Successor of 3 in inorder traversal: ";
    Node* suc = get_successor(root, root->left->left);
    cout << suc->data << "\n\n";

}

