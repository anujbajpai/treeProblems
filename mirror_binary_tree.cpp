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

void mirror(node *root, node * root_m) {
    if (root -> right) {
        root_m -> left = createnode(root -> right -> data);
        mirror(root -> right, root_m -> left);
    }
    if (root -> left) {
        root_m -> right = createnode(root -> left -> data);
        mirror(root -> left, root_m -> right);
    }
}

void inorder (node *root, vector<int> &V) {
    if (root) {
        inorder(root -> left, V);
        V.push_back(root -> data);
        inorder (root -> right, V);
    }
}

int main() {
    vector<int> V;
    node *root, *root_m;
    root = createnode(1);
    root -> left = createnode(2);
    root -> right = createnode(3);
    root -> left -> left = createnode(4);
    root -> left -> right = createnode(5);
    root -> right -> right= createnode(6);
    root -> right -> left= createnode(7);
    root -> right -> left -> right = createnode(8);
    root -> right -> right -> right= createnode(9);
    root_m = createnode(1);
    mirror(root, root_m);
    inorder(root_m, V);
    cout<<endl;
    for(int i = 0; i < 9; i++)
        cout<<V[i]<<" ";
    return 0;
}

