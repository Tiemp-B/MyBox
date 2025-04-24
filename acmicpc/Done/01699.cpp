#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int mem[100001]={};

void init(int N){
    for(int t=1; t<=316; ++t){
        int sq = t*t;
        for(int i=sq;i<=N; ++i){
            if(mem[i] == 0)
                mem[i] = mem[i-sq]+1;
            if(mem[i-sq]+1 < mem[i])
                mem[i] = mem[i-sq]+1;
        }
    }
}// 32ms

void init2(){
    for(int i=1;i<100001;++i)
        mem[i] = i;

    for(int i=2;i<316;++i){
        int sq = i*i;
        for(int t=0;t+sq<=100000; ++t){
            if(mem[t+sq]>mem[t]+1)
                mem[t+sq]=mem[t]+1;
        }
    }

}// 24ms

int sqs[316]={};
void init3(){
    for(int i=1; i<316;++i) sqs[i] = i*i;
    mem[1] = 1;
    
    for(int i=0; i<100001; ++i){
        for(int sq=1;sq<316;++sq){
            if(i+sqs[sq]>100000) break;
            if(mem[i+sqs[sq]]==0)
                mem[i+sqs[sq]] = mem[i]+1;
            else if(mem[i+sqs[sq]] > mem[i]+1)
                mem[i+sqs[sq]] = mem[i]+1; 
        }
    }
}// 28ms

void init4(int N){
    for(int i=1;i<=N;++i)
        mem[i] = i;

    for(int i=2;i*i<=N;++i){
        int sq = i*i;
        for(int t=0;t+sq<=N; ++t){
            if(mem[t+sq]>mem[t]+1)
                mem[t+sq]=mem[t]+1;
        }
    }
    cout << mem[N] << endl;
}// 24

void init5(int N){
    vector<bool> visited(N+1, false);
    queue<pair<int, int>> q;
    q.push({N, 0}); // {남은 값, 단계}
    int left, step, sq;
    while(!q.empty()){
        left = q.front().first;
        step = q.front().second;
        q.pop();
        if(left == 0){
            cout << step;
            break;
        }
        for(int i=sqrt(left), cnt=0; cnt<100 && i>0; --i, ++cnt){
            sq = i*i;
            if(!visited[left-sq]){
                q.push({left-sq, step+1});
                visited[left-sq] = true;
            }
        }
    }
}

int main(){
    int N;
    cin >>N;
    init5(N);
    // cout <<mem[N]<<endl;


    return 0;
}

// 최소 시간 4ms...