#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

struct log{
    int y;
    int x;
    int apple=0;
    unordered_set<int> l;
};

int main(){
    int N = 5;
    int field[5][5];
    int mem[5][5];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> field[i][j];
            mem[i][j] = 2147483647; // 거리
        }
    }
    int R, C;
    cin >> R >> C;

    queue<log> q;
    log first;
    first.y = R;
    first.x = C;
    first.apple = field[R][C];
    first.l.insert(R*10 + C);

    q.push(first);
    bool flag = false;

    while(!q.empty()){
        auto t = q.front(); q.pop();

        for(int d = 0; d< 4; d++){
            int new_y = t.y + dy[d];
            int new_x = t.x + dx[d];
            if(new_y <0||new_y>4 || new_x <0 || new_x >4)// 맵 밖으로 넘어감
                continue;
            if(field[new_y][new_x] == -1) // 벽 확인인
                continue;
            if(t.l.find(new_y*10+new_x) != t.l.end()) // 방문 확인 
                continue;
            if(t.l.size()==4)
                continue;

            log temp = t;
            temp.l.insert(new_y*10 + new_x);
            temp.y = new_y;
            temp.x = new_x;
            temp.apple += field[new_y][new_x];

            if(temp.apple == 2){
                flag = true;
                break;
            }
            q.push(temp);
        }
        if(flag)
            break;

    }

    cout << flag ? 1 : 0;

    
    return 0;
}