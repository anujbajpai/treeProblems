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

void discover(node *root, vector<int> V) {
    int flag = 0;
    V.push_back(root -> data);
    if (root -> left) {
        flag ++;
        discover(root -> left, V);
    }
    if (root -> right) {
        flag ++;
        discover(root -> right, V);
    }
    if (flag == 0) {
        for(int i = 0; i <= V.size() - 1; i++)
            cout<<V[i]<<" ";
        cout<<endl;
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
   discover(root, V);
    return 0;
}
