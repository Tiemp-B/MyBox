#include <stdio.h>

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int field[101][101]={};

    for(int n=0; n<N; ++n){
        int sx, sy, ex, ey;
        scanf(" %d %d %d %d", &sx, &sy, &ex, &ey);
        for(int x=sx ; x<=ex; ++x)
            for(int y=sy ; y<=ey; ++y)
                field[y][x]++;
    }

    int ans =0;
    for(int y = 1; y<101; ++y)
        for(int x=1 ; x<101; ++x)
            if(field[y][x]>M)
                ans++;
    
    printf("%d", ans);

    return 0;
}