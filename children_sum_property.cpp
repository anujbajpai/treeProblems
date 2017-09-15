#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

node* createnode(int data) {
    node* new_node = new node();
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

bool child_sum(node * temp, int &var) {
    int sum = 0;
    if(temp -> left) {
        sum += temp -> left -> data;
        child_sum(temp -> left, var);
    }
    if(temp -> right) {
        sum += temp -> right -> data;
        child_sum (temp -> right, var);
    }
    if (temp -> left == NULL && temp -> right == NULL)
        return var;
    else {
        if(temp -> data != sum)
            var = 0;
    }
    return var;
}

int main() {
    int var = 1;
    node *root;
    root = createnode(10);
    root -> left = createnode(6);
    root -> right = createnode(4);
    root -> left -> left = createnode(4);
    root -> left -> right = createnode(2);
    root -> right -> right= createnode(1);
    root -> right -> left= createnode(3);
    root -> right -> left -> right = createnode(3);
    root -> right -> right -> right= createnode(1);
    cout<<child_sum(root, var);
    return 0;
}
