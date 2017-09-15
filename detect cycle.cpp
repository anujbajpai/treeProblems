#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

bool check_cycle(int current_index, int &flag, vector<string> &check, vector<vector<int> > &graph) {
    if(check[current_index] == "white")
        check[current_index] = "grey";
    else if(check[current_index] == "grey") {
        return 1;
    }
    for(int j = 0; j < graph[current_index].size(); j++) {
        flag = check_cycle(graph[current_index][j], flag, check, graph);
        if(flag)
            break;
    }
    check[current_index] = "black";
    return flag;
}

bool detect_cycle(int num_vertices, vector<string> &check, vector<vector<int> > &graph) {
    int final_check = 0, flag = 0;
    for(int i = 0; i < num_vertices; i++) {
        final_check = check_cycle(i, flag, check, graph);
        if(final_check)
            break;
    }
    return final_check;
}

void graph_input(int num_edges, vector<vector<int> > &graph) {
    for(int i = 0; i < num_edges; i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
}

int main () {
    int num_vertices, num_edges;
    cout<<"Number of Verices\n";
    cin>>num_vertices;
    cout<<"number of edges\n";
    cin>>num_edges;
    vector<vector<int> > graph(num_vertices);
    vector<string> check(num_vertices);
    for(int i =0 ; i < num_vertices; i++)
        check[i] = "white";
    graph_input(num_edges, graph);
    cout<<detect_cycle(num_vertices, check, graph);
    return 0;
}
