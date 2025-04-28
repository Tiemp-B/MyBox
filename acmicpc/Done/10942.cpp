#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

// #define DEBUG
using namespace std;

int N, M;
int el[2001];
int mem[2001][2001] ={};

void init(){
    cin >> N;
    for(int i=1;i<=N;++i)//O(N)
        cin >> el[i];
} // O(N)

int recur(int s, int e){ // O(1~N/2)
    // 저장 데이터 읽기
    if(mem[s][e]!=0) return mem[s][e];
    // s가 e보다 커지면 이전 항목은 대칭성을 가진다.
    if(s>=e) return mem[s][e]=1;
    // S번째 E번째 원소가 다르면 대칭성을 가지지 못한다.
    if(el[s] != el[e]) return mem[s][e] = -1;
    // S원소, E원소가 동일하면 상위 항목의 대칭성을 따라간다.
    int ret = recur(s+1,e-1);
    return mem[s][e] = ret;
}
// 시간 초과 코드. 최대한 간결화가 핵심이었다.
// int recur(int s, int e){ // O(1~N/2)
//     // 저장 데이터 읽기
//     if(mem[s][e]==1) return 1;
//     else if(mem[s][e]==-1) return -1;
//     // s원소, e원소 불일치
//     if(s>e) return 1;
//     else if(s==e) return mem[s][e]=1;
//     if(el[s] != el[e]) {
//         mem[s][e] = -1;
//         return -1;
//     }
//     int ret = recur(s+1,e-1);
//     switch(ret){
//         case -1:
//             mem[s][e]=-1;
//             return -1;
//             break;
//         case 1:
//             mem[s][e]=1;
//             return 1;
//             break;
//     }
// }

void resp(){
    cin >>M;
    for(int i=0,s,e; i<M; ++i){
        cin >> s>>e;
        int out = recur(s,e);
        if(out == -1) out =0;
        printf("%d\n", out);
    }
}

#ifdef DEBUG
#include <random>
void rand_init(){
    cout <<"start"<<endl;
    N=2000;
    random_device rd;
    uniform_int_distribution<int> dist(1, 10);

    M=1000000;
    uniform_int_distribution<int> dist2(1,2000);

    vector<pair<int, int>> query;

    for(int i=1;i<=N;++i){
        el[i] = dist(rd);
    }

    for(int i=0;i<M;++i){
        int s = dist2(rd);
        int e = dist2(rd);
        while(e<s)
            e = dist2(rd);
        query.push_back({s, e});
    }

    for(int i=1;i<N;++i){
        mem[i][i] = 1;
        if(el[i]!=el[i+1])
            mem[i][i+1] = -1;
    }
    mem[N][N] =1;


    for(auto q: query){
        int s = q.first;
        int e = q.second;
        
        int out = recur(s,e);
        if(out ==1 && s!=e){
            for(;s<=e;++s){
                cout <<el[s]<<" ";
            }
            cout <<endl;
        }
    }
    cout <<"end"<<endl;
}
#endif

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    init();
    resp();
    // rand_init();
    return 0;
}
