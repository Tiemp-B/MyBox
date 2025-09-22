#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >>N;
    vector<pair<int, int>> v(N);
    for(int i=0, d, t;i <N;++i){
        cin >> v[i].second>>v[i].first;
    }
    sort(v.begin(), v.end(), greater<>());
    int ans = 1000000001;
    for(auto e : v){
        if(ans>=e.first)
            ans = e.first-e.second;
        else
            ans -= e.second;
    }
    cout <<ans;
    return 0;
}