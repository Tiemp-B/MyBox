#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long T, n,m;
vector<long long> A, B;
vector<long long> sA, sB;
unordered_map<long long , long long> AA, BB;

void psum(const vector<long long> &v, const vector<long long> &sV, unordered_map<long long, long long> &mp){
    // cout <<"----: "<< sV.size()<<endl;
    for(int s=0; s<v.size();++s){// 0~n
        for(int e=s+1; e<v.size();++e){// s+1~n
            long long interval = sV[e] - sV[s];
            // cout <<s <<" "<< e <<" : "<<interval <<endl;
            mp[interval]++;
        }
    }

}

void init(){
    cin >>T;
    cin >>n;
    A.resize(n+1);
    sA.resize(n+1, 0);
    for(int i=1; i<=n;++i){
        cin >>A[i];
        sA[i] = sA[i-1]+A[i];
    }    
    cin >> m;
    B.resize(m+1);
    sB.resize(m+1);
    for(int i=1; i<=m;++i){
        cin >> B[i];
        sB[i] = sB[i-1]+B[i];
    }
    
    psum(A, sA, AA);
    psum(B, sB, BB);
}

void calc(){
    long long ans = 0;
    for(auto e : AA){
        long long need = T-e.first;
        ans += e.second * BB[need];
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