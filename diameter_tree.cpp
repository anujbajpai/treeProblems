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

int height_tree(node* temp, int cnt, int &max_cnt) {
    int flag = 0;
    if (temp -> left) {
        flag = 1;
        cnt ++;
        height_tree(temp -> left, cnt, max_cnt);
    }
    if(temp -> right) {
        if (!flag)
            cnt++;
        height_tree(temp -> right, cnt, max_cnt);
    }
    if (cnt > max_cnt)
        max_cnt = cnt;

    return max_cnt +1;
}

int diameter(node * root, int cnt, int max_cnt) {
    int  L, R;
    L = height_tree(root-> left, cnt, max_cnt);
    R = height_tree(root -> right, cnt, max_cnt);
    return L +R +1;

}

int main() {
    int cnt = 0, max_cnt = 0;
    node *root;
    root = createnode(1);
    root -> left = createnode(2);
    root -> right = createnode(3);
    root -> left -> left = createnode(4);
    root -> left -> right = createnode(5);
    root -> left -> right -> left = createnode(14);

    root -> left -> right -> right = createnode(15);
    root -> right -> right= createnode(6);
    //root -> right -> left= createnode(7);
    //root -> right -> left -> right = createnode(8);
    root -> right -> right -> right= createnode(9);
    root -> right -> right -> right -> left = createnode(10);

    root -> right -> right -> right -> left-> left = createnode(11);

    root -> right -> right -> right -> left-> right = createnode(12);
     root -> right -> right -> right -> right = createnode(13);
    cout<<diameter(root, cnt, max_cnt);
    //cout<<height_tree(root, cnt, max_cnt);
    return 0;
}
