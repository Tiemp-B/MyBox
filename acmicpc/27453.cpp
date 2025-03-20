#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define I_MAX 2147483647

int N, M, K;
pair<int, int> start;
pair<int, int> goal;
vector<vector<int>> field;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

struct hist{
    pair<int, int> loc;
    pair<int, int> before;
    int b1, b2, far;
    unordered_map<int, int> lg; // y*10000 + x : 4bit 데이터 d에 따른 이전 장소 보관관
    hist(pair<int, int> now, pair<int, int> bef, unordered_map<int, int> l={}, int f=0, int bb1=0, int bb2=0, int d=0){
        loc = now;
        before = bef;
        far = f;
        b1 = bb1;
        b2 = bb2;
        lg = l;
        lg[now.first * 10000 + now.second] |= 1<<d;
    }
    bool operator<(const hist &d) const{
        return far < d.far;
    }
};

bool operator==(pair<int, int> a, pair<int, int> b){
    return a.first == b.first && a.second == b.second;
}

void init(){
    cin >> N >> M >> K;
    field.resize(N, vector<int>(M));

    for(int i=0; i<N; i++){
        for(int j=0; j<M ;j++){
            char temp;
            cin >> temp;
            if(temp =='S'){
                start = {i, j};
                field[i][j] = 0;
            }
            else if(temp == 'H'){
                goal = {i, j};
                field[i][j] = 0;
            }else if(temp == 'X'){
                field[i][j] = -1;
            } else{
                field[i][j] = temp -'0';
            }
        }
    }
}

void calc(){
    queue<hist> q;
    priority_queue<hist> pq;
    
    pq.push(hist(start, {-1, -1}));

    int ans = I_MAX;

    while(!pq.empty()){
        hist now = pq.top();
        pq.pop();

        if(now.loc == goal){
            if(ans > now.far){
                ans = now.far;
            }
            break;
            // continue;
        }

        int prob = now.b1 + now.b2;

        for(int d=0; d<4; d++){
            int ny = now.loc.first + dy[d];
            int nx = now.loc.second + dx[d];
            
            bool flag = ny<0 || nx<0 || ny == N || nx == M;
            if(flag) continue; // 범위 밖
            flag = make_pair(ny, nx) == now.before; // 이전 장소
            flag |= field[ny][nx] == -1; // 벽
            flag |= (prob + field[ny][nx]) > K; //  조건 확인
            if(flag) continue; 
            if(now.lg[ny*10000 + nx] & (1 << d))// 해당 장소는 현 위치에서 진입한 적이 있음
                continue;

            pq.push(hist({ny, nx}, now.loc, now.lg, now.far+1, field[ny][nx], now.b1, d));
            
        }

    }

    if(ans == I_MAX)
        ans = -1;
    
    cout << ans;

}

int main(){
    init();

    calc();

    return 0;
}