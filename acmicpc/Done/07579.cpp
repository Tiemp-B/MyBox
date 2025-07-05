#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <deque>
using namespace std;

int N, M;
int tot_cost = 1; // N*M 최대 100 * 100
vector<int> c;
vector<int> m;
deque<pair<float, pair<int, int>>> v;
vector<vector<int>> mem;
deque<int> item;

void init(){
    cin >> N >>M;
    c.resize(N+1);
    m.resize(N+1);
    
    for(int i=1; i<=N;++i) cin >> m[i];
    for(int i=1; i<=N;++i) {
        cin >> c[i];
        tot_cost += c[i];
    }
    for(int i=1; i<=N;++i){
        if(c[i]==0) {
            M -= m[i];
            continue;
        }
        v.push_back({((float)c[i])/((float)m[i]), {c[i], m[i]}});
    }
    sort(v.begin(), v.end());

    v.push_front({-1, {-1, -1}});
    mem.resize(v.size(), vector<int>(tot_cost, 0));
}

void calc(){
    if( M<=0) {
        cout << 0;
        return;
    }
    int ans = 10001;
    for(int i=1; i<v.size();++i){ // N * N * c
        int cc = v[i].second.first;
        int mm = v[i].second.second;

        for(int bound_cost=0; bound_cost<tot_cost;++bound_cost){
            if(mem[i-1][bound_cost]>mem[i][bound_cost]) mem[i][bound_cost] = mem[i-1][bound_cost];
            if(bound_cost < cc) continue;
            if(mem[i-1][bound_cost] < mem[i-1][bound_cost-cc]+mm) mem[i][bound_cost] = mem[i-1][bound_cost-cc] + mm;
            if(mem[i][bound_cost] >=M){
                if(ans > bound_cost)
                    ans = bound_cost;               
            }
        }
    }
    cout <<ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    init();
    calc();
    return 0;
}