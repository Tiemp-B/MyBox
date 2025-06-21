#include <stdio.h>

int field[9][9];
int row[9][10] = {};
int col[9][10] = {};
int block[3][3][10] = {};

int calc(int index){
    if(index == 81){
        return 1;
    }
    int y = index/9;
    int x = index%9;
    
    if(field[y][x]!=0)
        return calc(index+1);

    int avail[10]={0};
    
    for(int i=0;i<9;++i){
        avail[field[y][i]] |= 1;
        avail[field[i][x]] |= 1;
    }
    for(int ii=0; ii<3;++ii){
        for(int jj=0; jj<3; ++jj){
            avail[field[(y/3)*3 + ii][(x/3)*3 + jj]] |= 1;
        }
    }

    for(int i=1; i<10;++i){
        if(avail[i]) continue;
        field[y][x] = i; 
        int done = calc(index +1);
        if(done) return done;
    }
    field[y][x] = 0;
    return 0;
}


int main(void){
    int log_idx=0;
    for(int i=0; i<9;++i){
        char temp[10];
        scanf(" %s", temp);
        for(int j=0; j<9;++j){
            int num = temp[j]-'0';
            field[i][j] = num;
            if(num){
                row[i][num] = 1;
                col[j][num] = 1;
                block[i/3][j/3][num] = 1;
            }
        }
    }

    calc(0);

    for(int i=0; i<9;++i){
        for(int j=0; j<9; ++j){
            printf("%d", field[i][j]);
        }
        printf("\n");
    }



    return 0;
}

/*
  012345678 
0 143600509
1 002109400
2 000704000
3 300502006
4 060000050
5 700803004
6 000401000
7 009205800
8 804000107
*/