#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[]={1, 0, -1, 0};
int dx[]={0, 1, 0, -1};

int N, M;
vector<string> field;
vector<vector<int>> cnt;

void init(){
    cin >>N >>M;
    field.resize(N);
    cnt.resize(N+1, vector<int>(M+1, 0));
    for(int i=0; i<N;++i) cin >> field[i];
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    field[0][0] = 'g';
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        
        for(int d=0; d<4;++d){
            int ny = now.first + dy[d];
            int nx = now.second + dx[d];
            if(ny<0||nx<0||ny==N||nx==M) continue;
            if(field[ny][nx] == '1') field[ny][nx] = 'b'; // 1은 'b'로
            if(field[ny][nx] != '0') continue;
            field[ny][nx] = 'g'; // 접근 가능한 0은 'g'로 
            q.push({ny, nx});
        }
    }
    for(int i=0; i<N;++i){
        for(int j=0; j<M;++j){
            if(field[i][j] == '0'||field[i][j] == '1') field[i][j] = 'b';
            cnt[i+1][j+1] = (int)(field[i][j] == 'b') + cnt[i][j+1] + cnt[i+1][j] - cnt[i][j];
        }
    }
}

inline int rectSum(int sy, int sx, int ey, int ex){
    return cnt[ey][ex] - cnt[sy-1][ex] - cnt[ey][sx-1] + cnt[sy-1][sx-1];
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    int Q; cin >>Q;
    while(Q--){
        int sy,sx,ey,ex;
        cin >> sy >>sx>>ey>>ex;
        int c= rectSum(sy,sx,ey,ex);
        if(c==0) cout <<"Yes\n";
        else     cout <<"No "<<c<<"\n";
    }
    return 0;
}


/*
6 7
0000000
0111000
0101110
0111010
0001110
0000000
4
*/