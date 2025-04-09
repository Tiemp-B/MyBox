#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt=0;
int choco[40][40]={};
int dy[] = { 0, 1};
int dx[] = {1, 0};
vector<vector<int>> connections={{}}; // i 노드가 연결된 노드 번호

struct Info{
    bool visited= false;
    bool loop= false;
    vector<int> lines;
    pair<int, int> loc;
    Info(int y, int x) {
        loc = {y, x};
    }
};

vector<Info> uf;
vector<Info> cuf;

void init(){
    cin >>N;
    uf.push_back(Info(-1, -1));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++){
            char temp;
            cin >> temp;
            if (temp != '.'){
                choco[i][j] = ++cnt;
                uf.push_back(Info(i, j));
            }
        }
    }
    connections.resize(cnt+1, {});
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(choco[i][j] == 0)
                continue;
            // connections.push_back({});
            for(int d=0; d<2;d++){
                int y = i+dy[d];
                int x = j+dx[d];
                if(y<0||x<0||y==N||x==N)
                    continue;
                if(choco[y][x] == 0)
                    continue;
                connections[choco[i][j]].push_back(choco[y][x]);
                connections[choco[y][x]].push_back(choco[i][j]);
            }
        }
    }
}

vector<int> dfs_log; // <목적지, 사용 간선선>
int ban;
int line_count = 0;
bool flag= false;

void dfs(int now, int parent){
    if(cuf[now].visited){
        flag = true;
        return;
    }else{
        dfs_log.push_back(now);
        cuf[now].visited = true;
        line_count++;
        for(auto e : connections[now]){
            if( e == ban)
                continue;
            else if(e == parent)
                continue;
            dfs(e, now);
            if(flag)
                return;
        }
    }
}


void func(){
    int ans =0;
    vector<pair<int, int>> li;
    for(ban=1; ban<=cnt; ++ban){
        cuf = uf;
        line_count = 0;
        flag = false;
        if( ban == 1)
            dfs(2, 0);
        else
            dfs(1, 0);
        // cout <<endl;
        // cout << line_count<<endl;
        if(line_count== cnt-1 && !flag)
            ans++;
        else
            continue;
        li.push_back(uf[ban].loc);
    }
    cout <<ans<<endl;
    for(auto e : li){
        cout << e.first+1<<" "<<e.second+1<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    func();
    return 0;
}
/*
15
###############
#.............#
#.............#
#.............#
#.............#
#.............#
#.............#
#.............#
#.............#
#.............#
#.............#
#.............#
#.............#
#.............#
###############
*/