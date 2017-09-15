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

int count_leaf(node *temp, int &cnt) {
    if (temp -> left == NULL && temp -> right == NULL) {
        //cnt++;
        return ++cnt;
    }
    else {
        if(temp -> left) {
            count_leaf(temp -> left, cnt);
        }
        if(temp -> right) {
            count_leaf(temp -> right, cnt);
        }
    }
}

int main() {
    int cnt = 0;
    node *root;
    root = createnode(1);
    root -> left = createnode(2);
    root -> right = createnode(3);
    root -> left -> left = createnode(4);
    root -> left -> right = createnode(5);
    root -> right -> right= createnode(6);
    root -> right -> left= createnode(7);
    root -> right -> left -> right = createnode(8);
    root -> right -> right -> right= createnode(9);
    cout<<count_leaf(root, cnt);
    return 0;
}
