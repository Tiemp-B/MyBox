#include <iostream>
#include <cstdio>
using namespace std;

int field[1025][1025];
int mem[1025][1025]={};
int N, M;

int value(int y1, int x1, int y2, int x2){
    // printf("%d - %d - %d + %d\n",mem[y1][x1],mem[y2-1][x1],mem[y1][x2-1],mem[y2-1][x2-1]);
    return mem[y1][x1] -mem[y2-1][x1] -mem[y1][x2-1] + mem[y2-1][x2-1];
}

void init(){
    cin.tie(NULL);
    cin >>N >>M;
    for(int i=1; i<=N;++i) //O(N^2)
        for(int j=1;j<=N;++j){
            cin >> field[i][j];
            mem[i][j] = mem[i][j-1]+mem[i-1][j]-mem[i-1][j-1]+field[i][j];
        }
    // for(int i=1;i<=N;++i){
    //     for(int j=1;j<=N;++j)
    //         cout <<mem[i][j] <<" ";
    //     cout <<endl;
    // }
}

void query(){
    cin.tie(NULL); cout.tie(NULL);
    for(int i=0, y1,x1,y2,x2;i<M;++i){
        cin >> y1 >>x1 >>y2 >>x2;
        int out=0;
        if(y1<=y2 &&x1<=x2)
            out = value(y2,x2,y1,x1);
        else if(y1<=y2 && x1>=x2)
            out = value(y2,x1,y1,x2);
        else if(y1>=y2 && x1<=x2)
            out = value(y1,x2,y2,x1);
        else    
            out = value(y1,x1,y2,x2);
        printf("%d\n", out);
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    init();
    query();
    return 0;
}