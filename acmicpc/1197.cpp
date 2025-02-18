#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

/*
최소 스패닝 트리 Minimum Spanning Tree
모든 정점들을 가장 적은 수의 간선과 비용으로 연결하는 것
*/

struct line{
    int from;
    int to;
    long long value;

    line(int a, int b, long long c){
        from = a;
        to = b;
        value = c;
    }

    bool operator<(const line &a) const{
        return a.value < value;
    }
};

int V, E;
priority_queue<line> pq; 
vector<int> mem; 
vector<vector<int>> graph;

int get_head(int e){
    if(mem[e] == e)
        return e;
    else
        mem[e] = get_head(mem[e]);
    return mem[e];
}

void kruskal(){
    long long ans = 0;
    int cnt = 0;
    
    while(cnt < V -1){
        auto top = pq.top();
        pq.pop();

        int from_head = get_head(top.from);
        int to_head = get_head(top.to);

        if(from_head == to_head){
            continue;
        }else if(from_head < to_head){
            mem[to_head] = from_head;
            get_head(top.to);
        }else{
            mem[from_head] = to_head;
            get_head(top.from);
        }
        ans += top.value;
        cnt++;
    }

    cout << ans;
}


void init(){
    cin >> V >> E;
    
    //graph.resize(V+1);
    
    for(int i=0; i<=V; i++){
        mem.push_back(i);
        //graph[i].resize(V+1, 0);
    }
    
    for(int i=0; i<E; i++){
        long long from, to, value;
        cin >> from >> to >> value;
        //graph[from][to] = value;
        //graph[to][from] = value;
        pq.push(line(from, to, value));
    }
}

int main(){
    init();
    kruskal();
    
    return 0;
}