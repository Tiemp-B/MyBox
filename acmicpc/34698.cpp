#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node{
    int idx;
    vector<int> from, to;

};

int N, M, Q;

vector<node> v;
vector<vector<int>> far(2001, vector<int>(2001, -1));

void init(){
    cin >>N >>M;
    v.resize(N+1);
    for(int i=0, a, b; i<M;++i){
        cin >>a >>b;
        v[b].from.push_back(a);
        v[a].to.push_back(b);
    }
}

void bfs(int stt){
    queue<int> q;
    q.push(stt);
    far[stt][stt]=0;
    while(!q.empty()){
        int p = q.front(); q.pop();
        for(auto nx : v[p].to){
            if(far[stt][nx]==-1 || far[stt][nx] > far[stt][p]+1){
                far[stt][nx]= far[stt][p]+1;
                q.push(nx);
            }
        }
    }
}

void calc(){
    for(int i=1; i<=N; ++i){
        bfs(i);
    }
    cin >>Q;

    bool flag = false;
    while(Q-->0){
        flag = true;
        int a, b, k;
        cin >>a >>b >>k;
        vector<pair<int, int>> vv(k);
        for(auto &e : vv) {
            cin >>e.second;
            e.first = far[a][e.second];
        }
        vv.push_back({far[a][b], b});
        sort(vv.begin(), vv.end());
        int n=a;
        if(far[a][b] == -1 || far[a][b] < k+1) flag = false;
        int length=0;
        for(auto e : vv){
            length += far[n][e.second];
            if(far[n][e.second]==-1){
                flag = false;
                break;
            }else{
                n = e.second;
            }
        }
        flag &= (length==far[a][b]);

        if(flag) cout <<"YES\n";
        else cout <<"NO\n";
    }
}


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr)->sync_with_stdio(false);
    init();
    calc();

    return 0;
}

/*
7 7
1 2
1 3
2 4
3 5
4 6
5 6
6 7
7
1 2 0
1 6 2 2 4
1 6 2 3 5
1 6 2 2 3
1 6 2 4 5
1 7 3 2 4 6
1 7 3 2 5 6

6 7
1 2
1 4
2 3
3 4
4 3
5 6
4 5

7 7
1 2 
1 3
2 4
3 5
4 6
5 6
6 7
*/