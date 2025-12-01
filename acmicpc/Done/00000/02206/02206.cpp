#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

#define I_MAX 2147483647

using namespace std;

// 전역 변수부부
struct node{
    int y;
    int x;
    bool crash = false;
    node(int i, int j, bool c){
        y = i;
        x = j;
        crash = c;
    }
};

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

bool mp[1000][1000]={};
int mem_walk[1000][1000]={};
int mem_break[1000][1000]={};

int N, M;

void init(){
    cin >> N >>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M;j++){
            char temp;
            cin >> temp;
            mem_break[i][j] = I_MAX;
            mem_walk[i][j] = I_MAX;
            if(temp == '0')
                mp[i][j] = false;
            else
                mp[i][j] = true;
        }
    }    
}

int bfs(){
    queue<node> q;
    mem_walk[0][0] = 1;
    q.push(node(0, 0, false));

    while(!q.empty()){
        node now = q.front();
        q.pop();

        for(int d=0 ;d< 4; d++){
            int ny = now.y + dy[d];
            int nx = now.x + dx[d];

            if(ny<0 ||nx <0 || ny>=N || nx>= M)
                continue;
            
            if(now.crash){// 이전에 벽을 부쉈음
                if(mp[ny][nx])// 이제 벽을 못부숨
                    continue;
                if(mem_break[now.y][now.x] +1 > mem_walk[ny][nx])
                    continue;
                if(mem_break[ny][nx] > mem_break[now.y][now.x] +1){
                    mem_break[ny][nx] = mem_break[now.y][now.x] +1;
                    q.push(node(ny, nx, true));
                }
            }else{// 부수지 않음
                if(mp[ny][nx]){// 벽 부수기
                    if(mem_break[ny][nx] > mem_walk[now.y][now.x] + 1){
                        mem_break[ny][nx] = mem_walk[now.y][now.x] + 1;
                        q.push(node(ny, nx, true));
                    }
                }else{  // 벽 아닌 곳 가기
                    if(mem_walk[ny][nx] > mem_walk[now.y][now.x] + 1){
                        mem_walk[ny][nx] = mem_walk[now.y][now.x] + 1;
                        q.push(node(ny, nx, false));
                    }
                }
            }
        }
    }

    if(mem_break[N-1][M-1] > mem_walk[N-1][M-1]){
        return mem_walk[N-1][M-1];
    }else if(mem_break[N-1][M-1] < mem_walk[N-1][M-1]){
        return mem_break[N-1][M-1];
    }else if(mem_break[N-1][M-1] == I_MAX){
        return -1;
    }else{
        return mem_break[N-1][M-1];
    }
}

void printArr(){
    cout << "break"<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%3d ", mem_break[i][j]);
        }
        cout << endl;
    }
    cout << "walk"<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%3d ", mem_walk[i][j]);
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    
    int ans = bfs();
    
    // printArr();

    cout << ans;
    return 0;
}


/*
7 8
01000000
01111110
01001000
01101011
11101000
10001110
00000000
14

5 8
00000000
11111110
00000000
01111111
00000000


8 9
000000000
110111110
000000000
011111111
010001000
000100010
111111110
000000000

1 10
0111100000
*/