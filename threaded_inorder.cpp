#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
    bool rightnode;
};

node* createnode(int data) {
    node* new_node = new node();
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> rightnode = true;
    return new_node;
}

void inorder_form_threaded (node *root, vector<int> &V, vector<node*> &V_node) {
    if (root) {
        inorder_form_threaded(root -> left, V, V_node);
        V.push_back(root -> data);
        if (V_node.size() >= 1) {
            if (!V_node[V_node.size() - 1] -> right) {
                V_node[V_node.size() - 1] -> right = root;
                V_node[V_node.size() - 1] -> rightnode = false;
            }
        }
        V_node.push_back(root);
        inorder_form_threaded(root -> right, V, V_node);
    }
}

void inorder_through_thread(node * root) {
    int flag = 1;
    while(root) {
        if (root -> left != NULL && flag == 1)
            root  = root -> left;
        else {
            flag = 1;
            cout<<root -> data<<" ";
            if (root -> rightnode == false)
                flag = 0;
            root = root -> right;
        }
    }
}

int main() {
    vector<int> V;
    vector<node *> V_node;
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
    inorder_form_threaded(root, V, V_node); // to form thread
    inorder_through_thread(root); // to get inorder using thread
    //for(int i = 0; i < 9; i++)
      //  cout<<V[i]<<" "<< V_node[i] -> rightnode <<endl;
    return 0;
}
