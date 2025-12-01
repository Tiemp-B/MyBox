#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/*
1. cin.tie()->sync_... 잊지 말 것.
2. 선언하는 것은 최대한 적고 재사용이 가능하게끔. 23줄의 q 선언이 for문 내에 들어가면 12ms 증가함
*/

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M>>K;
    vector<vector<int>> field(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M));
    for(auto &e1: field)
        for(auto &e : e1) cin >> e;
    unordered_set<int> st;
    queue<pair<int, int>> q;
    int ans =0;
    for(int y=0;y<N;++y){
        for(int x=0;x<M;++x){
            if(visited[y][x]) continue;
            ans++;
            q.push({y, x});
            visited[y][x] = true;

            while(!q.empty()){// 
                auto now = q.front(); 
                q.pop();
                for(int d=0; d<4;++d){
                    int ny = now.first + dy[d];
                    int nx = now.second + dx[d];
                    if(ny<0 ||nx<0||ny==N||nx==M) continue;
                    if(visited[ny][nx]) continue;
                    if(abs(field[now.first][now.second] - field[ny][nx]) > K) continue;
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
    cout << ans;
    return 0;
}