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

int calc_height(node * root, int cnt, int &max_cnt) { // alternate function refer level_order.cpp
    if (root -> left != NULL){
        cnt++;
        if (max_cnt < cnt)
            max_cnt = cnt;
        calc_height(root -> left, cnt, max_cnt);
        cnt--;
    }
    if (root -> right != NULL) {
        cnt++;
        if (max_cnt < cnt)
            max_cnt = cnt;
        calc_height(root -> right, cnt, max_cnt);
        cnt--;
    }
    return max_cnt + 1;
}

int main() {
    int max_cnt = 0, cnt = 0;
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
    cout<<calc_height(root, cnt, max_cnt);
    return 0;
}
