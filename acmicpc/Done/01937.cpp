#include <iostream>
#include <vector>
using namespace std;

int n, ans = 0;
vector<vector<int>> mp;
vector<vector<int>> mem;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void calc1();

/*
f(현재 위치) = max(이동 가능 위치) + 1
*/

void init(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n;
    mp.resize(n, vector<int>(n, 0));
    mem.resize(n, vector<int>(n, -1));

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin >> mp[i][j];
}

int main(){
    init();
    calc1();
    cout << ans;
    return 0;
}

int dfs(int y, int x){
    if(mem[y][x] != -1) return mem[y][x];
    mem[y][x] = 1;
    for(int d=0;d<4;++d){
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny<0||nx<0||ny==n||nx==n) continue;
        if(mp[y][x] <= mp[ny][nx]) continue; // 작은 지역으로만 이동. 이전 지역이 제외됨됨
        int data = dfs(ny,nx);
        if(mem[y][x] < data+1)
            mem[y][x] = data+1; 
    }
    return mem[y][x];
}

void calc1(){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int out = dfs(i,j);
            if(out > ans)
                ans = out;
        }
    }
} // 32 ms