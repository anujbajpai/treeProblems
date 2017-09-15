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

void get_max_path (node *temp, vector<vector<int> > &store, vector<int> newstore, int sum, int &max_sum, int &sum_index) {
    newstore.push_back(temp -> data);
    sum += temp->data;
    store.push_back(newstore);
    if (max_sum < sum) {
        max_sum = sum;
        sum_index = store.size() - 1;
    }
    if(temp -> left) {
        get_max_path(temp -> left, store, newstore, sum, max_sum, sum_index);
    }
    if(temp -> right) {
        get_max_path(temp -> right, store, newstore, sum, max_sum, sum_index);
    }
}

vector<int> send_each_node(node *temp, int &max_till, vector<int> &final_store) {
    vector<int> L, R;
    int L_sum = 0, R_sum = 0;
    vector<vector<int> > store;
    vector<int> newstore;
    int sum = 0, max_sum = -100, sum_index = 0, final_score = 0;
    get_max_path(temp, store, newstore, sum, max_sum, sum_index);
     cout<<"root1 "<<temp -> data<<"max "<<max_sum<<endl;
    if(temp -> left) {
        L = send_each_node(temp -> left, max_till, final_store);
        for(int h = 0; h < L.size(); h++)
            L_sum += L[h];
    }
   cout<<"root2 " <<temp -> data << "sum "<<L_sum<<endl;
    if(temp -> right) {
        R = send_each_node(temp -> right, max_till, final_store);
        for(int h = 0; h < R.size(); h++)
            R_sum += R[h];
    }
    cout<<"root3 " <<temp -> data << "sum "<<R_sum<<endl;
    if (max_sum < L_sum + R_sum + temp -> data ) {
          if (max_till < L_sum + R_sum + temp -> data) {
                max_till = L_sum + R_sum + temp -> data;
              final_store.clear();
              for(int h = 0; h < L.size(); h++)
                final_store.push_back(L[h]);
              final_store.push_back(temp -> data);
              for(int h = 0; h < R.size(); h++)
                    final_store.push_back(R[h]);
            cout<<"in "<<endl;
            return final_store;
          }
    }
    else {
        if(max_till < max_sum) {
            max_till = max_sum;
            final_store.clear();
            cout<<"out "<<endl;
            for(int j = 0; j < store[sum_index].size(); j++)
                final_store.push_back(store[sum_index][j]);
            return final_store;
        }
    }
    cout<<temp -> data<<" "<<max_till<<endl;
    vector<int> fake;
    return fake;
}

int main() {
    int max_till = 0;
    vector<int> final_store;
    node *root;
    root = createnode(10);
    root -> left = createnode(2);
    root -> right = createnode(10);
    root -> left -> left = createnode(20);
    root -> left -> right = createnode(1);
    root -> right -> right= createnode(-25);
    //root -> right -> left= createnode(7);
    //root -> right -> left -> right = createnode(8);
    root -> right -> right -> right = createnode(4);
    root -> right -> right -> left = createnode(3);
    send_each_node(root, max_till, final_store);
 //   cout<<max_till;
    //for(int j = 0; j < final_store.size(); j++)
      //      cout<<final_store[j]<<" ";
    return 0;
}
