#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, S, prev_end=0;
    cin >>N >> M >>S;
    vector<pair<int, int>> used(N);
    for(auto &e:used) cin>>e.first>>e.second;
    sort(used.begin(), used.end());
    for(auto e : used){
        if(e.first-prev_end>=M) break;
        prev_end=e.first+e.second;
    }
    if(S-prev_end>=M) cout <<prev_end;
    else cout << -1;
    return 0;
}