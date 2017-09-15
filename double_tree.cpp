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

void create_double_tree (node *current) {
    node *temp = createnode(current -> data);
    temp -> left = current -> left;
    temp -> right = NULL;
    current -> left = temp;
}

void convert_to_double(node *root) {
    if (root) {
        convert_to_double(root -> left);
        create_double_tree(root);
        convert_to_double(root -> right);
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
    convert_to_double(root);
    inorder(root,V);
    for(int i = 0; i < V.size(); i++)
        cout<<V[i]<<" ";
    return 0;
}

