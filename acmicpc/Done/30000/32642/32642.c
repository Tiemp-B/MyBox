#include <stdio.h>


int main(){
    long long int total = 0;
    long long int rage = 0;

    int N;
    scanf("%d", &N);

    for(int i=0, rain=0; i<N; ++i){
        scanf("%d",&rain);
        if(rain)
            rage++;
        else
            rage--;
        total += rage;
    }

    printf("%lld", total);

    return 0;
}