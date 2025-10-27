#include <iostream>
#include <vector>
using namespace std;

int N, M, ans=0, i1=1, i2=1;
vector<int> S, P1, P2;
int upBound = 1000000007;

void init(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >>N >>M; //N:~5000
    S.resize(N);
    P1.resize(M+1);
    P2.resize(M+1);
    for(auto &e : S) cin >>e;
}

void recur(int idx){
    if(idx == N) {
        ans++;
        if (ans == upBound) ans = 0;
        return;
    } 
    if(P1[i1-1] < S[idx] && i1 <= M)
    {
        P1[i1++] = S[idx];
        recur(idx+1);
        i1--;
    }
    if(P2[i2-1] < S[idx] && i2 <= M)
    {
        P2[i2++] = S[idx];
        recur(idx+1);
        i2--;
    }
}

int main(){
    init();
    recur(0);    
    cout <<ans;
    return 0;
}