#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct node{
    int data;
    struct node *left, *right, *parent;
};

node * createnode(int fill_it) {
    node *new_node = new node();
    new_node -> data = fill_it;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

void fun(node *root) {
    node *current = root;
    node *pre;
    while(current) {
        if (current -> left== NULL) {
            cout<<current -> data<<" ";
            current = current -> right;
        }
        else {
            pre = current -> left;
            while(pre -> right != NULL) {
                pre = pre -> right;
            }
            pre -> right = current;
            current = current -> left;
        }
    }
}

int main() {
    node *root = NULL;
    root = createnode(1);
    root -> left = createnode(2);
    root -> right = createnode(3);
    root -> left -> left = createnode(4);
    root -> left -> right = createnode(5);
    root -> right -> right= createnode(6);
    root -> right -> left= createnode(7);
    root -> right -> left -> right = createnode(8);
    root -> right -> right -> right= createnode(9);
    fun(root);
    return 0;
}
