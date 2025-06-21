#include <stdio.h>

int main(){
    int K, D, A;
    scanf("%d/%d/%d",&K, &D, &A);
    int ans;
    char resp[2][5]={
        "gosu",
        "hasu"
    };
    if(D==0 || K+A<D)
        printf("%s", resp[1]);
    else
        printf("%s", resp[0]);

    return 0;
}