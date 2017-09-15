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

int search_inorder(int data, vector<int> store) {
    for(int i = 0; i < store.size(); i++) {
        if (data == store[i])
            return i;
    }
    return -1;
}

int construct_tree(node * &parent, int &K, vector<int> L, vector<int> R, vector<int> preorder) {
    initial:
    vector<int> new_L, new_R;
    node *temp;
    int current_index = search_inorder(preorder[K], L);
    if (current_index >= 0) {
        if(current_index != 0){
            for(int i = 0; i < current_index; i++)
                new_L.push_back(L[i]);
        }
        for(int i = current_index + 1; i < L.size(); i++)
            new_R.push_back(L[i]);
        if(parent == NULL) {
            parent = createnode(preorder[K]);
            temp = parent;
        }
        else {
            temp = createnode(preorder[K]);
            parent -> left = temp;
        }
        K++;
        int free = -1;
        free = construct_tree(temp, K, new_L, new_R, preorder);
        if (free != -1)
            goto initial;
    }
    else if(search_inorder(preorder[K], R) >= 0) {
        int c_i = search_inorder(preorder[K], R);
        if (c_i != 0) {
            for(int i = 0; i < c_i; i++)
                new_L.push_back(R[i]);
        }
        for(int i = c_i + 1; i < R.size(); i++)
            new_R.push_back(R[i]);
        temp = createnode(preorder[K]);
        parent -> right = temp;
        K++;
        int free = -1;
        free = construct_tree(temp, K, new_L, new_R, preorder);
        if(free != -1)
            goto initial;
    }
    else {
        return preorder[K];
    }
}

void inorder_travel(node *root) {
    if(root) {
        cout<<root -> data<<" ";
        inorder_travel(root -> left);
        inorder_travel(root -> right);
    }
}

int main() {
    node *n = NULL;
    int K = 0;
    int a[] = {4, 2, 8, 11, 5, 9, 1, 12, 10, 13, 6, 3, 7};
    int b[] = {1, 2, 4, 5, 8, 11, 9, 3, 6, 10, 12, 13, 7};
    vector<int> inorder (a, a+sizeof(a)/sizeof(int));
    vector<int> preorder (b, b+sizeof(b)/sizeof(int));
    construct_tree(n, K, inorder, inorder, preorder);
    inorder_travel(n);/*
    /*root = createnode(1);
    root -> left = createnode(2);
    root -> right = createnode(3);
    root -> left -> left = createnode(4);
    root -> left -> right = createnode(5);
    root -> right -> right= createnode(6);
    root -> right -> left= createnode(7);
    root -> right -> left -> right = createnode(8);
    root -> right -> right -> right= createnode(9);
*/
    return 0;
}
