#include <iostream>
#include <queue>
using namespace std;

void calc(){
    int money[21], m, ans=0, target;
    int mem[21][10001] = {};
    cin >>m;
    for(int i=1; i<=m ; ++i){
        cin>>money[i];
    }
    cin >>target;
    mem[0][0] = 1;
    int cnt1=0, cnt2=0;
    // for(int c=1;c<=m;++c){
    //     for(int i=0;i<=target;++i){
    //         int now = 0;
    //         while(now<=target && i-now>=0){
    //             cnt1++;
    //             now += money[c];
    //         }  
    //     }
    // }

    for(int c=1;c<=m;++c){
        for(int i=0;i<=target;++i){
            mem[c][i] +=mem[c-1][i];
            if(i-money[c]>=0)
                mem[c][i] += mem[c][i-money[c]]; 
            cnt2++;
        }
    }
    cout << mem[m][target]<<endl;
}

int main(){
    int T;
    cin >>T ;
    
    for(int tc=0; tc<T; ++tc){
        calc();
    }

    return 0;
}