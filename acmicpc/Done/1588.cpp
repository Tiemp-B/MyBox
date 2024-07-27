#include <iostream>
#include <cstdio>

using namespace std;

long long int tri[21];
int N, L, R, S;

long long int ans[4]={0,0,0,0};

long long int table[4][21][4]; //[start][stage][cnt]

void calc(int num, long long int loc, int lv){
    int remain = N - lv;
    long long int from = loc * tri[remain];
    long long int to   = from + tri[remain]-1;
    if(from >=L && to <=R){
        ans[1] += table[num][remain][1];
        ans[2] += table[num][remain][2];
        ans[3] += table[num][remain][3];
    }else if(to<L||from >R){
        return;
    }else{
        if(num==1){
            calc(1, loc*3, lv+1);
            calc(3, loc*3+1, lv+1);
            calc(2, loc*3+2, lv+1);
        }else if(num==2){
            calc(2, loc*3, lv+1);
            calc(1, loc*3+1, lv+1);
            calc(1, loc*3+2, lv+1);
        }else if(num==3){
            calc(2, loc*3, lv+1);
            calc(3, loc*3+1, lv+1);
            calc(2, loc*3+2, lv+1);
        }
    }
}

int main(){
    tri[0] = 1;
    for(int i=0; i<20; i++) tri[i+1] = 3 * tri[i];
    cin >>S >>L >>R >>N;

    table[1][0][1] = 1;
    table[2][0][2] = 1;
    table[3][0][3] = 1;

    table[1][1][1] = 1; table[1][1][2] = 1; table[1][1][3] = 1;
    table[2][1][1] = 2; table[2][1][2] = 1; table[2][1][3] = 0;
    table[3][1][1] = 0; table[3][1][2] = 2; table[3][1][3] = 1; 

    for(int i =1 ;i < N; i++){
        for(int s = 1; s<4; s++){
            for(int n = 1; n<4; n++){
                for(int j=1; j<4; j++){
                    table[s][i+1][j] += table[s][i][n] * table[n][1][j];
                }
            }
        }
    }
    calc(S, 0, 0);
    printf("%d %d %d", ans[1], ans[2], ans[3]);

    return 0;
}