#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> field(N);
    for(auto &e: field) cin >>e;

    vector<vector<bool>> visited1(N, vector<bool>(N));
    vector<vector<bool>> visited2(N, vector<bool>(N));
    int normal=0, blind=0;
    queue<pair<int, int>> q;

    for(int i=0; i<N;++i){
        for(int j=0; j<N;++j){
            if(!visited1[i][j]){
                normal++;
                visited1[i][j]=true;
                q.push({i,j});
                while(!q.empty()){
                    auto [y, x] = q.front(); q.pop();
                    for(int d=0; d<4;++d){
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if(ny<0||nx<0||ny==N||nx==N) continue;
                        if(visited1[ny][nx]) continue;
                        if(field[ny][nx] != field[y][x]) continue;
                        visited1[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
            if(!visited2[i][j]){
                blind++;
                visited2[i][j]=true;
                q.push({i, j});
                while(!q.empty()){
                    auto [y, x] = q.front(); q.pop();
                    for(int d=0; d<4;++d){
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if(ny<0||nx<0||ny==N||nx==N) continue;
                        if(visited2[ny][nx]) continue;
                        switch (abs(field[ny][nx]-field[y][x])){
                            case 0:
                                visited2[ny][nx] = true;
                                q.push({ny, nx});
                                break;
                            case abs('R'-'G'):
                                visited2[ny][nx] = true;
                                q.push({ny, nx});
                                break;
                        }
                    }
                }
            }   
        }
    }
    cout << normal <<" "<<blind;

    return 0;
}