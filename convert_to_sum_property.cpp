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

void check_arbitary(node * temp) {
    if(temp) {
        check_arbitary(temp -> left);
        cout<<temp -> data <<" ";
        check_arbitary(temp -> right);
    }
}

int travel_tree (node * temp) {
    if(temp) {
        int sum = 0, R = 0, L = 0;
        L = travel_tree(temp -> left);
        R = travel_tree(temp -> right);
        if (R == 1 && L == 1) {
            sum += temp -> left -> data + temp -> right -> data;
            if(sum < temp -> data) {
                temp -> left -> data += temp -> data - sum;
            }
            else if(sum > temp -> data) {
                temp -> data += sum - temp -> data;
            }
        }
        else if (R == 0 && L == 1) {
            sum += temp -> left -> data;
            if(sum < temp -> data) {
                temp -> left -> data += temp -> data - sum;
            }
            else if(sum > temp -> data) {
                temp -> data += sum - temp -> data;
            }
        }
        else if ( R == 1 && L == 0) {
            sum += temp -> right -> data;
            if(sum < temp -> data) {
                temp -> right -> data += temp -> data - sum;
            }
            else if(sum > temp -> data) {
                temp -> data += sum - temp -> data;
            }
        }
        return 1;
    }
    else
        return 0;
}

int main() {
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
    travel_tree(root);
    check_arbitary(root);
    return 0;
}
