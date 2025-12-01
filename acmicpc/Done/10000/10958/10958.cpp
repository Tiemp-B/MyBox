#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

ll N, M;
vector<ll> v;
int v_size=0;

void init(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >>N >>M;
    v.resize(N);
    ll temp;
    for(int i=0;i<N;++i){
        cin >>temp;
        if(M<temp) continue;
        v[v_size++] = temp;
    }
    sort(v.begin(), v.begin()+v_size);
    N = v.size();
    N=v_size;
}

void sum(int stt, int ed, vector<ll> &box){
    for(int i=stt, t; i<ed; ++i){
        t = box.size();
        for(int j=0; j<t;++j){
            box.push_back(box[j] + v[i]);
        }
    }
}

void calc(){
    vector<ll> p1={0}, p2={0};
    sum(0, N/2, p1);
    sum(N/2, N, p2);
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    ll ans =0;
    for(auto e: p1){
        ans += upper_bound(p2.begin(), p2.end(), M-e) - p2.begin();
    }
    cout <<ans;
}

int main(){
    init();
    calc();
    return 0;
}