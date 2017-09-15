#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

void Merge(vector<vector<int> > &A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q, l = 1, m = 1, s = 1, w = 1;
    vector<vector<int> > L(n1+2), R(n2 + 2);
    for(int i = p; i <= q; i++) {
        L[l].push_back(A[i][0]);
        L[l].push_back(A[i][1]);
        L[l].push_back(A[i][2]);
        l++;
    }
    L[n1+1].push_back(-1);
    for(int i = q + 1; i <= r; i++) {
        R[m].push_back(A[i][0]);
        R[m].push_back(A[i][1]);
        R[m].push_back(A[i][2]);
        m++;
    }
    R[n2+1].push_back(-1);

    for(int k = p; k <= r; k++ ){
        if(L[s][0] != -1 && R[w][0] != -1) {
            if(L[s][2] < R[w][2]) {
                A[k].clear();
                A[k].push_back(L[s][0]);
                A[k].push_back(L[s][1]);
                A[k].push_back(L[s][2]);
                s++;
            }
            else {
                A[k].clear();
                A[k].push_back(R[w][0]);
                A[k].push_back(R[w][1]);
                A[k].push_back(R[w][2]);
                w++;
            }
        }
        else {

            if (L[s][0] != -1) {
                A[k].clear();
                A[k].push_back(L[s][0]);
                A[k].push_back(L[s][1]);
                A[k].push_back(L[s][2]);
                s++;
            }
            else{
                A[k].clear();
                A[k].push_back(R[w][0]);
                A[k].push_back(R[w][1]);
                A[k].push_back(R[w][2]);
                w++;
            }
        }
    }
}

void mergeSort(vector<vector<int> > &A, int p, int r) {
    int q;
    if(p < r) {
        q = (p + r) / 2;
        mergeSort(A, p, q);
        int temp = q + 1;
        mergeSort(A, temp, r);
        Merge(A, p, q, r);
    }
}

void graph_store(int num_edges, int num_vertices, vector<vector<int> > &edges, vector<int> &vertex) {
    cout<<"enter edges\n";
    for(int i = 1; i <= num_edges; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        edges[i].push_back(u);
        edges[i].push_back(v);
        edges[i].push_back(w);
    }
    for(int i = 1; i <= num_vertices; i++)
        vertex.push_back(i);
}

void graph_sort(vector<vector<int> > &edges, int num_edges) {
    mergeSort(edges, 1, num_edges);
}

int head_correct(int temp, vector<int> &head) {
    if(head[temp] == temp)
        return temp;
    else {
        head[temp] = head_correct(head[temp], head);
    }
}

void selection(int num_edges, int num_vertices, vector<bool> &check, vector<bool> &store, int cnt, vector<int> &head_store, vector<vector<int> > &edges, vector<int> &head) {
    int count_edges = 0;
    for(int i = 1; (i < num_edges) && (count_edges < num_vertices); i++) {
        if(check[edges[i][0]] == false && check[edges[i][1]] == false) {
            check[edges[i][0]] = true;
            check[edges[i][1]] = true;
            store[i] = true;
            count_edges++;
            cnt++;
            head_store[edges[i][0]] = cnt;
            head_store[edges[i][1]] = cnt;
        }
        else if((check[edges[i][0]] == false && check[edges[i][1]] == true) || (check[edges[i][0]] == true && check[edges[i][1]] == false)) {
            if(check[edges[i][0]] == false) {
                check[edges[i][0]] = true;
                head_store[edges[i][0]] = head_store[edges[i][1]];
                store[i] = true;
                count_edges++;
            }
            else {
                check[edges[i][1]] = true;
                head_store[edges[i][1]] = head_store[edges[i][0]];
                store[i] = true;
                count_edges++;
            }
        }
        else {
            head[head_store[edges[i][1]]] = head_correct(head[head_store[edges[i][1]]], head);
            if(head[head_store[edges[i][0]]] == head[head_store[edges[i][1]]]) {
                continue;
            }
            else {
                store[i] = true;
                count_edges++;
                head[head_store[edges[i][0]]] = head[head_store[edges[i][1]]];
            }
        }
    }
}

int main() {
    int num_vertices, num_edges, cnt = 0;
    vector<int> vertex(1);
    cout<<"num_vertices\n";
    cin>>num_vertices;
    vector<int> head(num_vertices +1), head_store(num_vertices+1);
    for(int i = 0; i <= num_vertices; i++)
        head[i] = i;
    cout<<"num_edges\n";
    cin>>num_edges;
    vector<bool> check(num_vertices + 1), store(num_edges+1);
    vector<vector<int> > edges(num_edges+1);
    for(int i = 0; i <= num_vertices; i++)
        check[i] = false;
    for(int i = 0; i <= num_edges; i++)
        store[i] = false;
    graph_store(num_edges, num_vertices, edges, vertex);
    graph_sort(edges, num_edges);
    selection(num_edges, num_vertices, check, store, cnt, head_store, edges, head);

    cout<<"selected order of edges of the sorted order\n";
    for(int i = 0; i <= num_edges; i++) {
        if(store[i] == true)
            cout<<i<<" ";
    }
    return 0;
}
