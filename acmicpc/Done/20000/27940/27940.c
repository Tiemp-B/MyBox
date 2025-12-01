#include <stdio.h>

int main(){
    int N, K, M;

    scanf("%d %d %d", &N, &M, &K);
    int rain=0, far=N;
    
    for(int i=1, t, r;i<=M;++i){
        scanf("%d %d", &t, &r);// t: 범위, r: 강수량
        if(far>t) far = t;
        rain += r;
        if(rain > K){
            printf("%d %d", i, far);
            return 0;
        }
    }

    printf("-1");

    return 0;
}