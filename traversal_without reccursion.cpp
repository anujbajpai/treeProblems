#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct node{
    int data;
    struct node *left, *right, *parent;
};

node * createnode(int fill_it, node *temp) {
    node *new_node = new node();
    new_node -> data = fill_it;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> parent = temp;
    return new_node;
}

void optimized_inorder(node *temp, stack<node*> S) {
    node *play = temp;
    printf("the modify inorder is here\n");
    S.push(temp);
    while(!S.empty() || play != NULL) {
        if (play != NULL) {
            if (play != temp)
                S.push(play);
            play = play -> left;
        }
        else {
            play = S.top();
            cout<<play -> data<<endl;
            play = play -> right;
            S.pop();
        }
    }
}

void inorder(node *temp, stack<node*> S) {
    printf("the inorder is here\n");
    stack<node*> extreme;
    S.push(temp);
    while(!S.empty()) {
        node *play = S.top();
        S.pop();
        extreme.push(play);
        if (play -> right != NULL)
            S.push(play ->right);
        if (play -> left != NULL)
            S.push(play ->left);
        else{
            if (!S.empty()) {
                while(extreme.empty() == false && S.top() -> parent -> data >= extreme.top() -> data) {
                    cout<<extreme.top() -> data<<endl;
                    extreme.pop();
                }
            }
            else {
                while(!extreme.empty()) {
                    cout<<extreme.top() -> data<<endl;
                    extreme.pop();
                }
            }
        }
    }
}

void postorder(node *temp, stack<node*> S) {
    int aux[13], k = 0;
    S.push(temp);
    while(!S.empty()) {
        node *play = S.top();
        aux[k++] = S.top() -> data;
        S.pop();
        if (play -> left != NULL)
            S.push(play -> left);
        if (play -> right != NULL)
            S.push(play -> right);
        //cout<<S.top() -> data<<endl;
    }
    printf("The Post Order is ->\n");
    for(int i = 12 ; i >= 0; i--)
        printf("%d\n", aux[i]);
}

void preorder(node *temp, stack<node*> S) {
    printf("The preorder is here -> \n");
    S.push(temp);
    while(!S.empty()) {
        printf("%d\n", S.top() -> data);
        node *play = S.top();
        S.pop();
        if (play -> right != NULL)
            S.push(play -> right);
        if (play -> left != NULL)
            S.push(play -> left);
    }
}

void random_traverse(node *temp, stack<node*> S) {
    printf("The Random Traverse is as follows\n");
    if (temp) {
        S.push(temp);
        while(S.empty() == false) {
            node *play = S.top();
            S.pop();
            if (play -> left != NULL)
                S.push(play -> left);

            if (play -> right != NULL)
                S.push(play -> right);
            cout<<play -> data<<endl;
        }
    }
}

int main() {
    stack<node*> store;
    node *root;
    root = createnode(100, NULL);
    root -> right = createnode(150, root);
    root -> left = createnode(50, root);
    root -> left -> left = createnode(25, root -> left);
    root -> left -> left -> left = createnode(15, root -> left -> left);
    root -> left -> left -> left -> left = createnode(5, root -> left -> left -> left);
    root -> left -> left -> left -> left -> right = createnode(10, root -> left -> left -> left -> left);
    root -> left -> left -> left -> left -> right -> left = createnode(7, root -> left -> left -> left -> left -> right);
    root -> left -> left -> left -> left -> right -> right = createnode(13, root -> left -> left -> left -> left -> right);
    root -> left -> left -> left -> left -> right -> left -> left = createnode(6, root -> left -> left -> left -> left -> right -> left);
    root -> left -> right = createnode(75, root -> left);
    root -> right -> left = createnode(125, root -> right);
    root -> right -> left -> left = createnode(115, root -> right -> left);
    optimized_inorder(root, store);
    printf("\n");
    inorder(root, store);
    printf("\n");
    postorder(root, store);
    printf("\n");
    preorder(root, store);
    printf("\n");
    random_traverse(root, store);
    return 0;
}
