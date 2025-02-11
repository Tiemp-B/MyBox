#include <stdio.h>
#include <stdlib.h>


int main(){
    int N;
    scanf("%d", &N);

    int x[10001] = {};
    int y[10001] = {};

    for(int i=0; i<N; i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    x[N] = x[0];
    y[N] = y[0];
    float ans=0.f;
    for(int i=0; i<N; i++){
        ans += x[i]*y[i+1];
        ans -= y[i]*x[i+1];
    }
    ans /= 2;
    ans = abs(ans);
    printf("%.1f", ans);

    return 0;
}