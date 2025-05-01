#include <iostream>
#include <vector> 
#include <cstdio>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> mem;
vector<vector<int>> connection;
vector<vector<int>> score;

void init(){
    cin >>N;
    mem.resize(N+1, vector<int>(3, 0)); // 3N 4
    score.resize(N+1, vector<int>(3,0)); // 3N 4
    connection.resize(N+1); // N 4
    for(int i=1,a,b;i<N;++i){
        cin >>a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }
    for(int i=1;i<=N;++i){
        scanf("%d %d %d", &score[i][0], &score[i][1], &score[i][2]);
    }
}

void calc(){
    vector<int> order;
    deque<int> q= {1};
    vector<bool> visit(N+1, false); // N 1
    vector<vector<int>> child_list(N+1,vector<int>()); // N 4
    vector<vector<map<int, int>>> color_log(N+1,vector<map<int, int>>(3));// 
    while(!q.empty()){
        int now = q.front(); q.pop_front();
        order.push_back(now);
        visit[now] = true;
        for(int e : connection[now]){
            if(!visit[e]){
                q.push_back(e);
                child_list[now].push_back(e);
            }
        }
    } 
    for(int i=N-1; i>=0;--i){
        for(int color=0; color<3;++color){// 현재의 색
            int max_value = 0;
            for(int child : child_list[order[i]]){ // 하위 항목
                int big_one=0;
                for(int child_color=0; child_color<3;++child_color){
                    if(child_color == color) continue;
                    if(big_one <= mem[child][child_color]){
                        big_one = mem[child][child_color];
                        color_log[order[i]][color][child]= child_color;
                    }
                }
                max_value += big_one;
            }
            mem[order[i]][color] = max_value + score[order[i]][color];
        }
    }
    int start_color, mx=0;
    char color_type[]={'R','G','B'};
    for(int i=0;i<3;++i){
        if(mx<mem[1][i]){
            mx = mem[1][i];
            start_color = i;
        }
    }
    cout << mx <<endl;
    vector<int> color_mem(N+1);
    color_mem[1] = start_color;
    for(int i=0;i<N;++i){
        int now = order[i];
        for(int child : child_list[now]){
            color_mem[child] = color_log[now][color_mem[now]][child];
        }
    }
    
    for(int i=1;i<=N;++i)
        printf("%c", color_type[color_mem[i]]);
}

struct node{
    int parent;
    int score[3];
    vector<int> children;
};

void init(){
    cin >>N;
    mem.resize(N+1, vector<int>(3, 0)); // 3N 4
    score.resize(N+1, vector<int>(3,0)); // 3N 4
    connection.resize(N+1); // N 4
    for(int i=1,a,b;i<N;++i){
        cin >>a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }
    for(int i=1;i<=N;++i){
        scanf("%d %d %d", &score[i][0], &score[i][1], &score[i][2]);
    }
}


//dfs의 최대: 64000 정도
int main(){
    init();
    calc();

    return 0;
}