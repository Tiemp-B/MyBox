#define c

#ifdef cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

ll N, M, X;
vector<ll> S, C;

void init(){
    cin >>N >>M >>X;
    C.resize(N); // 재건비용
    for(int i=0; i<N; ++i) cin >>C[i];
    S.resize(M); // 동아리 예산
    for(int i=0; i<M; ++i) cin >>S[i];
    sort(C.begin(), C.end()); // O(N logN)
    sort(S.begin(), S.end(), greater<>()); // O(M logM)
}


void calc(){
    int ans=0;
    int l=0, r=(M>N)? N: M, m;
    ll sum=0;
    while(l<=r){
        m = (l+r)/2;
        sum=0;
        for(int i=0; i<m; ++i){
            sum += ((C[m-1-i]-S[i])<0? 0: (C[m-1-i]-S[i]));
        }

        if(sum > X){
            r =m-1;
        }else{
            if(ans<m) ans = m;
            l =m+1;
        }
    }
    cout <<ans;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    calc();
    return 0;
}
#else

#include <stdio.h>
#include <stdlib.h>

#define ll long long int

int N, M, X;
ll *C;
ll *S;

int up(const void *a, const void *b){
    return *(ll*)a>*(ll*)b;
}
int down(const void *a, const void *b){
    return *(ll*)a<*(ll*)b;
}

void init(){
    scanf("%d %d %d\n", &N, &M, &X);
    C = (ll*)malloc(N*sizeof(ll));
    S = (ll*)malloc(M*sizeof(ll));
    for(int i=0; i<N;++i) scanf("%lld", &C[i]);
    for(int i=0; i<M;++i) scanf("%lld", &S[i]);
    qsort(C, N, sizeof(ll), up);
    qsort(S, M, sizeof(ll), down);
}

void calc(){
    int ans=0;
    int l=0, r=(M>N)? N: M, m;
    ll sum=0;
    while(l<=r){
        m = (l+r)/2;
        sum=0;
        for(int i=0; i<m; ++i){
            sum += ((C[m-1-i]-S[i])<0? 0: (C[m-1-i]-S[i]));
        }

        if(sum > X){
            r =m-1;
        }else{
            if(ans<m) ans = m;
            l =m+1;
        }
    }
    printf("%d", ans);
}
void term(){
    free(C);
    free(S);
}

int main(){
    init();
    calc();
    term();
}

#endif


