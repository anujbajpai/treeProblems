#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <map>
#include <vector>
#include <utility>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;


struct node {
    int data, level;
    struct node *left, *right;
};

node* createnode(int data) {
    node* new_node = new node();
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> level = 0;
    return new_node;
}

int height_tree (node * temp, int cnt, int &max_cnt) {
    if(!temp)
        return 0;
    int flag = 0;
    if (temp -> left) {
        flag = 1;
        cnt++;
        height_tree(temp -> left, cnt, max_cnt);
    }
    if (temp -> right) {
        if (!flag)
            cnt++;
        height_tree(temp -> right, cnt, max_cnt);
    }
    if(max_cnt < cnt)
        max_cnt = cnt;
    return max_cnt + 1;
}

bool if_balanced(node *temp, int &var) {
    int cnt = 0, max_cnt = 0;
    if (temp) {
        int L = 0, R = 0;
        L = height_tree(temp -> left, cnt, max_cnt);
        R = height_tree(temp -> right, cnt, max_cnt);
        int diff = L - R;
        if (diff != 0 && diff != 1 && diff != -1) {
            var = 0;
            return var;
        }
        if(temp -> left) {
            if_balanced(temp -> left, var);
        }
        if(temp -> right) {
            if_balanced(temp -> right, var);
        }
   }
   return var;
}



int main() {
    int var = 1;
    node *root= NULL;
    root = createnode(1);
    root -> left = createnode(2);
    root -> right = createnode(3);
    root -> left -> left = createnode(4);
    root -> left -> left  -> right = createnode(11);
    root -> left -> left  -> right -> left = createnode(12);
    root -> left -> left -> left = createnode(10);
    root -> left -> right = createnode(5);
     root -> left -> right -> left = createnode(15);
    root -> left -> right  -> right= createnode(13);
     root -> left -> right  -> right -> right = createnode(14);
    root -> right -> right= createnode(6);
    root -> right -> left= createnode(7);
    //root -> right -> left -> right = createnode(8);
    root -> right -> right -> right= createnode(9);
    cout<<if_balanced(root, var);
    return 0;
}

