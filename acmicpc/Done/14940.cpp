#include <iostream>
#include <queue>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int main(){
    int N, M;
    cin >>N >>M;
    int**avail = new int*[N];
    int**road = new int*[N];
    bool**been = new bool*[N];
    pair<int, int> start;
    for(int i=0;i<N; i++){
        avail[i] = new int[M]();
        road[i] = new int[M]();
        been[i] = new bool[M]();
        for(int j=0; j<M;j++){
            cin>>avail[i][j];
            if(avail[i][j] == 2){
                start.first=i;
                start.second=j;
                been[i][j] = true;
            }
        }
    }
    
    queue<pair<int, int>> q;
    
    q.push(start);
    
    while(!q.empty()){
        auto now= q.front(); q.pop();
        
        for(int d=0; d<4; ++d){
            int ny = now.first +dy[d];
            int nx = now.second+dx[d];
            if(ny<0||nx<0||ny>=N||nx>=M) continue;
            if(avail[ny][nx] == 0) continue;
            if(road[ny][nx]<= road[now.first][now.second]+1&&been[ny][nx]) continue;
            road[ny][nx] = road[now.first][now.second]+1;
            been[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    for(int i=0; i<N;i++){
        for(int j=0; j<M; j++){
            if(avail[i][j]== 1&&road[i][j]==0)
                cout << -1<<" ";
            else
                cout <<road[i][j]<<" ";
        }
        cout <<endl;
    }
    
    
    return 0;
}