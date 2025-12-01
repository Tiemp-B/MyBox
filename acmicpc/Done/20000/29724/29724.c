#include <stdio.h>

int main(){
    int N;
    scanf("%d\n",&N);

    int weight =0 ;
    int apple_price=0;
    for(int box=0; box<N;++box){
        char T;
        int W, H, L;
        scanf(" %c %d %d %d", &T, &W, &H, &L);
        if(T=='B'){
            weight += 120*50;
        }else{
            W /= 12;
            H /= 12;
            L /= 12;
            weight += W*H*L*500 + 1000;
            apple_price += W*H*L*4000;
        }
    }

    printf("%d\n%d", weight, apple_price);

    return 0;
}