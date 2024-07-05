#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

struct pos{
    int y;
    int x;
    int dist;

    bool operator<(const pos next) const{
        return dist > next.dist;
    }  
};

int calc(int w, int h){
    int sy, ex;
    vector<pair<int,int>> dust;
    int mat[20][20] = {};
    for(int i=0; i<h; i++){
        for(int j=0; j<w ;j++){
            char c;
            cin >>c;
            if(c == 'o'){
                sy = i;
                ex = j; 
            }else if(c == '*'){
                dust.push_back(make_pair(i, j));
            }else if(c == 'x'){
                mat[i][j] = -1;
            }
        }
    }
    dust.push_back({sy,ex});
    int d = dust.size();
    int **graph = new int*[d];
    cout <<"dustsize: "<<dust.size()<<endl;
    for(int i=0; i<dust.size(); i++) {
        graph[i] = new int[d]();
    }
    
    for(int i=0; i<d ;i++){
        int map[20][20]={};
        bool visit[20][20]={};
        visit[dust[i].first][dust[i].second] = true;
        queue<pair<int,int>> q;
        q.push({dust[i].first, dust[i].second});//y, x
        while(!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int d=0; d<4; d++){
                int ny = y + dy[d];
                int nx = x + dx[d];

                if(ny<0||ny>=h || nx<0||nx>=w) continue;
                if(visit[ny][nx]) continue; visit[ny][nx] = true;
                if(map[ny][nx] <= map[y][x]+1)continue;
                q.push({ny, nx});
            }
        }
        for(int t=0; t<dust.size(); t++){
            graph[i][t] = map[dust[t].first][dust[t].second];
        }
    }

    for(int i=0; i<dust.size(); i++){
        for(int j=0; j<dust.size();j++){
            cout <<graph[i][j] <<"  ";
        }
        cout <<endl;
    }
}

int main(){
    while(true){
        int w, h;
        cin >>w >>h;
        if(w==0&&h==0) break;
        calc(w, h);
    }

    return 0;
}