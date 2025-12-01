#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> v;
unordered_map<int, long long int > x_cnt, y_cnt;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, x, y;
    cin >>N;
    for(int i=0; i<N;++i){
        cin >>x >>y;
        v.push_back({x, y});
        x_cnt[x]++;
        y_cnt[y]++;
    }
    long long int ans =0;
    for(auto e : v){
        ans += (x_cnt[e.first]-1)*(y_cnt[e.second]-1);
    }
    cout <<ans;

    return 0;
}