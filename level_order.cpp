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

void bfs(queue<node *> Q, vector<pair<int, int> > &V) {
    while(!Q.empty()) {
        node *temp = Q.front();
        Q.pop();
        V.push_back(make_pair(temp -> data, temp -> level)) ;
        if (temp -> left) {
            temp -> left -> level = temp -> level + 1;
            Q.push(temp -> left);
        }
        if (temp -> right) {
            temp -> right -> level = temp -> level + 1;
            Q.push(temp -> right);
        }
    }
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

void get_nodes_at_level(node *node_temp, int level_cnt) {
    if (level_cnt == 0) {
        cout<<node_temp -> data<<" ";
        return;
    }
    else {
        level_cnt --;
        if (node_temp -> left) {
            get_nodes_at_level(node_temp -> left, level_cnt);
        }
        if (node_temp -> right) {
            get_nodes_at_level(node_temp -> right, level_cnt);
        }
    }

}


void get_nodes_by_order(node *root, int max_cnt, int cnt) {
    for(int i = 0; i < height_tree(root, max_cnt, cnt); i++) {
        cout<<"Level "<<i<<endl;
        get_nodes_at_level(root, i);
        cout<<endl;
  }
}


int main() {
    node *root= NULL;
    int max_cnt = 0, cnt = 0;
    vector<pair<int, int> > V;
    queue<node *> Q;
    root = createnode(1);
    root -> left = createnode(2);
    root -> right = createnode(3);
    root -> left -> left = createnode(4);
    root -> left -> right = createnode(5);
    root -> right -> right= createnode(6);
    root -> right -> left= createnode(7);
    root -> right -> left -> right = createnode(8);
    root -> right -> right -> right= createnode(9);
    get_nodes_by_order(root, max_cnt, cnt);
    //get_nodes_at_level(root, 2); // to know the nodes at particular level
    //alternate call bfs();
    //Q.push(root);
    //bfs(Q,V);
    return 0;
}




