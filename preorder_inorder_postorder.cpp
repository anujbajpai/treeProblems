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

void inorder (node *root, vector<int> &V) {
    if (root) {
        inorder(root -> left, V);
        V.push_back(root -> data);
        inorder (root -> right, V);
    }
}

void preorder (node *root, vector<int> &V) {
    if (root) {
        V.push_back(root -> data);
        preorder(root -> left, V);
        preorder (root -> right, V);
    }
}

void postorder (node *root, vector<int> &V) {
    if (root) {
        postorder(root -> left, V);
        postorder (root -> right, V);
        V.push_back(root -> data);
    }
}



int main() {
    vector<int> V;
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
    postorder(root, V);
    for(int i = 0; i < 9; i++)
        cout<<V[i]<<" ";
    return 0;
}
