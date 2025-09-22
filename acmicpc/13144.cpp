#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> v2; // 다음 v[i] 의 값이 나오는 곳
vector<int> vmp;

void init(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >>N;
    v.resize(N+1);
    v2.resize(N+1,N+1);
    vmp.resize(100001, 0);
    for(int i=1; i<=N;++i) {
        cin >>v[i];
        if(vmp[v[i]]==0) vmp[v[i]]=i;
        else{
            v2[vmp[v[i]]] = i;
            vmp[v[i]] = i;
        }
    }
    int mx= v2[N];
    for(int i=N; i>0;--i){
        v2[i] = min(mx, v2[i]);
        mx = v2[i];
    }
}

void calc(){
    long long ans = 0, temp;
    for(int i=1;i<=N;++i)
        ans += v2[i]-i;
    cout <<ans;
}

int main(){
    init();
    calc();
    return 0;
}