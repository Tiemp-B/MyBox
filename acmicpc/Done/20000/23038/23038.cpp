#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int N, M;
//vector<vector<char>> field;
char field[1200][1200];

void init(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N*3;++i)
        scanf("%s",field[i]);
}

void calc(){
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            int r = 1 +i*3;
            int c = 1 +j*3;
            if(field[r][c] == '.'){
                field[r][c] = '#';
                continue;
            }

            // right
            if(field[r][c+1]=='#')
                field[r][c+2] = '#';
            // left
            if(field[r][c-1]=='#')
                field[r][c-2]='#';
            // up
            if(field[r-1][c]=='#')
                field[r-2][c]='#';
            // down
            if(field[r+1][c]=='#')
                field[r+2][c]='#';
        }
    }
    
    for(int i=0; i<3*N;++i)
        printf("%s\n", field[i]);
}

int main(){
    init();
    calc();
    return 0;
}