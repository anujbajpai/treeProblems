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

int height_tree(node * temp, int &max_cnt, int cnt) {
    if(!temp)
       return 0;
    int flag = 0;
    if(temp -> left) {
        cnt++;
        flag = 1;
        height_tree(temp -> left, max_cnt, cnt);
    }
    if (temp -> right) {
        if (!flag)
            cnt++;
        height_tree(temp -> right, max_cnt, cnt);
    }
    else {
        if(max_cnt < cnt)
            max_cnt = cnt;
        return max_cnt + 1;
    }


}

void get_level_order(bool itr, int i, node *temp) {
    if(i == 0) {
        cout<< temp->data<<" ";
    }
    else {
        i--;
        if (itr) {
            if (temp -> left) {
                get_level_order(itr, i, temp->left);
            }
            if(temp -> right) {
                get_level_order(itr ,i, temp -> right);
            }
        }
        else {
            if (temp -> right) {
                get_level_order(itr, i, temp->right);
            }
            if(temp -> left) {
                get_level_order(itr, i, temp -> left);
            }
        }
    }
}

void spiral_order(node *root, int &max_cnt, int cnt) {
   bool itr = 0;
   for(int i = 0; i < height_tree(root, max_cnt, cnt); i++) {
        get_level_order(itr, i, root);
        itr = !itr;
   }
}

int main() {
    int cnt = 0, max_cnt = 0;
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
    spiral_order(root, max_cnt, cnt);
    return 0;
}
