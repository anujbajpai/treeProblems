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

int identical_tree (node *root1, node *root2) {
    if (root1 == NULL && root2  == NULL)
        return 0;
    if (root1 != NULL && root2 != NULL) {
        if (root1 -> data == root2 -> data) {
            int temp = identical_tree(root1 ->left, root2 -> left);
            if (!temp) {
                return identical_tree(root1 ->right, root2 -> right);
            }
            else
                return 1;
        }
        else
            return 1;
    }
    else
        return 1;
}

int main() {
    node *root1, *root2;
    root1 = createnode(1);
    root2 = createnode(1);
    root1 -> left = createnode(2);
    root2 -> left = createnode(2);
    //root2 -> right = createnode(3);
    root1 -> left -> left = createnode(4);
    root2 -> left -> left = createnode(4);
    root1 -> left -> left -> right = createnode(6);
    //root1 -> left -> right = createnode(5);
    //root2 -> left -> right = createnode(5);
    //root2 -> left -> right -> right = createnode(6);
    //root2 -> right -> right= createnode(6);
    //root -> right -> left= createnode(7);
    //root -> right -> left -> right = createnode(8);
    //root -> right -> right -> right= createnode(9);
    cout<<identical_tree (root1,root2);// 0 for identical else 1
    return 0;
}


