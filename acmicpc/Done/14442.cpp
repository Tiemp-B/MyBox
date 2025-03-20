#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define I_MAX 2147483647

using namespace std;

// 전역 변수
int N, M, K;
char mp[1000][1000];
int mem[1000][1000][11];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

struct node{
    int y;
    int x;
    int k;
    node(int i, int j, int t){
        y = i;
        x = j;
        k = t;
    }
};

// 함수
void init(){
    cin >> N >> M >> K;
    memset(mem, I_MAX, sizeof(mem));  // 전체 초기화

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M;j++){
            for(int k=0; k<=K;k++){
                cout <<mem[i][j][k] << " ";
            }
            cout << endl;
            mp[i][j] = s[j];
        }
    }
}

void bfs(){
    queue<node> q;
    q.push(node(0, 0, 0));
    mem[0][0][0] = 1;

    while(!q.empty()){
        node now = q.front();
        q.pop();
        for(int d=0; d<4 ;d++){
            int ny = now.y + dy[d];
            int nx = now.x + dx[d];

            if(ny<0 || nx< 0 || ny==N || nx==M)
                continue;
            
            if(mp[ny][nx]=='1'){ // 다음 장소 벽
                if(now.k == K) // 벽부수기 제한
                    continue;
                if(mem[ny][nx][now.k+1] > mem[now.y][now.x][now.k] +1){
                    mem[ny][nx][now.k+1] = mem[now.y][now.x][now.k] +1;
                    q.push(node(ny, nx, now.k+1));
                }
            }else{ // 다음 장소 길
                if(mem[ny][nx][now.k] > mem[now.y][now.x][now.k] +1){
                    mem[ny][nx][now.k] = mem[now.y][now.x][now.k] +1;
                    q.push(node(ny, nx, now.k));
                }
            }
        }
    }
    int ans = I_MAX;
    for(int k=0; k<=K; k++){
        if(mem[N-1][M-1][k] < ans)
            ans = mem[N-1][M-1][k];
    }
    if (ans == I_MAX)
        ans = -1;

    cout <<ans;
}

int main(){
    init();

    bfs();

    return 0;
}