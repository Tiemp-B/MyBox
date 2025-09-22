#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> data_field;
vector<vector<int>> value_field;
vector<vector<bool>> entry_field;

int N, M, K;
int sy, sx, ey, ex;
int mxx= 2147483647;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

void init(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> K;
    data_field.resize(N);
    value_field.resize(N, vector<int>(M, mxx));
    entry_field.resize(N, vector<bool>(M, false));
    
    for(auto &e : data_field) cin >>e;
    cin >> sy >>sx >> ey >>ex;
}


void calc(){ // 224ms
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    sy--, sx--, ey--, ex--;
    pq.push({0, {sy, sx}});
    value_field[sy][sx] = 0;

    while(!pq.empty()){
        int v = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        if(value_field[y][x] < v) continue;
        if(value_field[y][x] > value_field[ey][ex]) continue;
        for(int d=0; d<4;++d){
            for(int far=1; far<=K; ++far){
                int yy = y + dy[d]*far;
                int xx = x + dx[d]*far;
                if(yy<0||yy>=N|| xx<0||xx>=M) continue;
                if(data_field[yy][xx]=='#') break;
                if(value_field[yy][xx] <= value_field[y][x]) break;
                if(value_field[yy][xx] <= v+1) continue;
                value_field[yy][xx] = v+1;
                if(yy==ey && xx==ex) continue;
                pq.push({v+1, {yy, xx}});
            }
        }
    }
    cout << (value_field[ey][ex]==mxx?-1:value_field[ey][ex]);
}

void calc2(){ // 60ms
    queue<pair<int, int>> q;
    sy--, sx--, ey--, ex--;
    q.push({sy, sx});
    value_field[sy][sx] = 0;
    entry_field[sy][sx] = true;
    bool flag = false;
    while(!q.empty() && !flag){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        entry_field[y][x] = false;
        for(int d=0; d<4&& !flag; ++d){
            for(int far=1; far<=K && !flag;++far){
                int yy = y + dy[d]*far;
                int xx = x + dx[d]*far;
                if(yy<0||yy>=N||xx<0||xx>=M) continue;
                if(data_field[yy][xx]=='#') break;
                if(value_field[yy][xx] <= value_field[y][x]) break;
                value_field[yy][xx] = value_field[y][x] + 1;
                if(yy==ey && xx==ex) {
                    flag = true;
                    return;
                }
                if(entry_field[yy][xx]) continue;
                entry_field[yy][xx] = true;
                q.push({yy, xx});
            }
        }
    }
}

int main(){
    init();
    calc2();
    cout << (value_field[ey][ex]==mxx?-1:value_field[ey][ex]);

    return 0;
}