#include <stdio.h>
#include <stdlib.h>

int main(){
    int W, H, N;
    scanf("%d %d %d", &W, &H, &N);
    int ans = 0;
    int y, x;
    scanf(" %d %d", &y, &x);

    for(int i=1, ny, nx; i<N;++i){
        scanf(" %d %d", &ny, &nx);
        int dy = ny-y;
        int dx = nx-x;
        
        if(dy*dx <=0){
            ans += abs(dy) +abs(dx);
        }else{
            if(abs(dy) <abs(dx)){
                ans += abs(dx);
            }else{
                ans += abs(dy);
            }
        }
        y = ny;
        x = nx;
    }
    printf("%d", ans);

    return 0;
}