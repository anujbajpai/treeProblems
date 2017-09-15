#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>

using namespace std;

struct ladder{
    int source, dest;
};

int get_min_ladder(int current_ladder, int source, ladder ladders[], int final_dest, vector<vector<int> > &ladder_ahead_store) {
    int min_subladder = INT_MAX, flag = 0, cnt = 0;
    for(int i = 1; i < ladder_ahead_store[current_ladder].size(); i++) {
        int check = 0;
        flag = 1;
        check = get_min_ladder(ladder_ahead_store[current_ladder][i], ladders[current_ladder].dest, ladders, final_dest, ladder_ahead_store);
        if(min_subladder > check)
            min_subladder = check;
    }
    if(!flag) {
       // cout<<ladders[current_ladder].source<<" "<<source<<" "<<final_dest<<" "<<ladders[current_ladder].dest<<endl;
        cnt += ((ladders[current_ladder].source - source) / 6) + ((final_dest - ladders[current_ladder].dest) / 6);
        if(((ladders[current_ladder].source - source) % 6) > 0)
            ++cnt;
        if (((final_dest - ladders[current_ladder].dest) % 6) > 0)
            ++cnt;
    }
    else {
        cnt += ((ladders[current_ladder].source - source) / 6) + min_subladder;
        if (((ladders[current_ladder].source - source) % 6) > 0)
            ++cnt;
    }
    //cout<<"current "<<current_ladder<<" "<<cnt<<endl;
    return cnt;
}

int read_all_ladder(int quant_ladder, ladder ladders[], int final_dest, vector<vector<int> > &ladder_ahead_store) {
    int min_chances, source = 0;
    for(int i = 1; i <= quant_ladder; i++) {
        int chances;
        chances = get_min_ladder(i, source, ladders, final_dest, ladder_ahead_store);
        //cout<<"final "<<i <<" "<<chances<<endl;
        if( i == 1)
            min_chances = chances;
        if( min_chances > chances)
            min_chances = chances;
    }
    return min_chances;
}

void get_ahead_ladders(int quant_ladder,ladder ladders[], vector<vector<int> > &ladder_ahead_store) {
    for(int i = 1; i <= quant_ladder; i++) {
        for(int j = 1; j <= quant_ladder; j++) {
            if(ladder_ahead_store[i].empty())
                ladder_ahead_store[i].push_back(0);
            if(i == j)
                continue;
            if(ladders[i].dest < ladders[j].source)
                ladder_ahead_store[i].push_back(j);
        }
    }
}

void input(int quant_ladder,ladder ladders[]) {
    cout<<"Enter Details of Ladders\n";
    for(int i = 1; i <= quant_ladder; i++) {
        cout<<"Enter Source\n";
        cin>>ladders[i].source;
        cout<<"Enter Destination\n";
        cin>>ladders[i].dest;
    }
}

int main() {
    int final_dest, quant_ladder;
    cout<<"Enter Destination\n";
    cin>>final_dest;
    cout<<"Enter number of Ladders\n";
    cin>>quant_ladder;
    struct ladder ladders[quant_ladder + 1];
    input(quant_ladder, ladders);
    vector<vector<int> > ladder_ahead_store(quant_ladder + 1);
    get_ahead_ladders(quant_ladder, ladders, ladder_ahead_store);
    cout<<"Minimum Throws Required TO Reach Destination Are -> ";
    cout<<read_all_ladder(quant_ladder, ladders, final_dest, ladder_ahead_store);
    return 0;
}
