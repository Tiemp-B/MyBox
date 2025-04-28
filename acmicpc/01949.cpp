#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct node{
    int idx;
    int popul;
    vector<int> connect;
    node(int i, int p){
        idx = i;
        popul = p;
    }
};

int N, ans=0, total=0;
vector<int> population;
vector<vector<bool>> graph;
vector<node> nodes;

void init(){
    cin >>N;
    population.resize(N+1, 0);
    graph.resize(N+1, vector<bool>(N+1, false));
    nodes.resize(N+1);
    for(int i=1; i<=N;++i){
        cin >> population[i];
        total += population[i];
        nodes[i] = node(i, population[i]);
    }
    for(int i=0, f, t;i<N-1;++i){
        cin >>f >>t;
        graph[f][t] = true;
        graph[t][f] = true;
        nodes[f].connect.push_back(t);
        nodes[t].connect.push_back(f);
    }
}

struct group{
    int score_A=0, score_B=0;
    int group_id=0;
};

void dfs(int now, int prev){
    
}

void calc(){
    int start;
    for(start = 1; start<=N && nodes[start].connect.size()!=1;++start);
    
    // i 노드까지 포함된 경우 최대 규모


    


}

int main(){
    init();
    return 0;
}