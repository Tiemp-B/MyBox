#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct dat{
    int l=0;
    int r=0;
    int m=0;
    dat() = default;
};

bool cmp(const pair<int, dat>&a, const pair<int, dat>&b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, dat>> v;
    unordered_map<int, int> mp;

    for(int i=0; i<N;++i){
        int A, B, T;
        cin >>A >>B;
        T = A-B;
        mp[T]++;
        if(mp[T]==1) v.push_back({T, dat()});
    }

    sort(v.begin(), v.end(), cmp);
    int l=0, r=N-mp[v[0].first];
    for(int i=0; i<v.size()-1;++i){
        v[i].second.l = l;
        v[i].second.r = r;

        l += mp[v[i].first];
        r -= mp[v[i+1].first];
        v[i].second.m = mp[v[i].first];
    }
    v.back().second.l=l;
    v.back().second.r=0;
    v.back().second.m=mp[v.back().first];

    int m = v.size()/2;
    int S=-1, E=-1;
    for(auto e : v){
        if(e.second.l+ e.second.m == e.second.r)
            S = e.first;
        else if(e.second.r +e.second.m == e.second.l)
            E = e.first;
        
        if(S!=-1 && E!= -1) break;
    }

    cout << E-S+1;
    

    return 0;
}