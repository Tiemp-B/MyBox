#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int cnt=0;
    vector<int> nex;
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<node> v(N+1);

    for(int i=0; i<M;++i){
        int a, b;
        cin >> a >> b;
        v[a].nex.push_back(b);
        v[b].cnt++;
    }
    queue<int> q;
    for(int i=1; i<=N;++i){
        if(v[i].cnt == 0)
            q.push(i);
    }

    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout << f<<" ";
        for(auto e : v[f].nex){
            if(--v[e].cnt == 0)
                q.push(e);
        }
    }
    
    return 0;
}