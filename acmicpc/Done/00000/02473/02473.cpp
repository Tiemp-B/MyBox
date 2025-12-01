#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N; // 3~5000
vector<long long> v;
bool fullNeg=true, fullPos=true;

void init(){
    cin >>N;
    v.resize(N);
    for(auto &e : v) {
        cin >> e;
        if(e>0) fullNeg=false;
        if(e<0) fullPos=false;
    }
    sort(v.begin(), v.end());
}

void calc(){
    if(fullNeg){
        cout <<v[N-3]<<" "<<v[N-2]<<" "<< v[N-1];
        return;
    }else if(fullPos){
        cout <<v[0]<<" "<<v[1]<< " "<<v[2];
        return;
    }
    long long mn = 3000000000;
    int ans[3]={0,0,0};
    for(int s=0; s<N &&mn!=0;++s){
        for(int e= s+2; e<N && mn!=0;++e){
            // 이분 탐색
            int ss = s+1, ee=e-1;
            int mm = (ss+ee)/2;
            long long target = -(v[s]+v[e]);
            while(ss <= ee){
                int mm = (ss+ee)/2;
                if(v[mm] == target){
                    mn = 0;
                    ans[0] = v[s];
                    ans[1] = v[mm];
                    ans[2] = v[e];
                    break;
                }
                long long sm = abs(v[s]+v[mm]+v[e]);
                if(sm < mn){
                    mn = sm;
                    ans[0] = v[s];
                    ans[1] = v[mm];
                    ans[2] = v[e];
                }
                if(v[mm] < target){
                    ss = mm+1;
                }else if(v[mm]>target){
                    ee = mm-1;
                }
            }
        }
    }
    cout <<ans[0] <<" "<<ans[1]<<" "<<ans[2];
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    init();
    calc();
    return 0;
}