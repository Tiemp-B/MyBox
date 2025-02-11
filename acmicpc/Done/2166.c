#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d", &N);

    long long x[10001] = {};
    long long y[10001] = {};

    for(int i=0; i<N; i++){
        scanf("%ld %ld", &x[i], &y[i]);
    }
    x[N] = x[0];
    y[N] = y[0];

    double ans=0.f;
    for(int i=0; i<N; i++){
        ans += x[i]*y[i+1];
        ans -= y[i]*x[i+1];
    }
    ans /= 2;
    printf("%.1f", (ans<0 ? -ans : ans));

    return 0;
}
