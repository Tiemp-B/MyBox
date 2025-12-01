#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, K, cnt=0;
    scanf("%d %d", &N, &K);
    int* A = (int*)malloc(sizeof(int)*N);
    if(N==1){
        printf("0");
        return 0;
    }
    scanf("%d", &A[0]);
    for(int i=1; i<N;++i){
        scanf("%d", &A[i]);
        if(A[i-1]>=A[i]){
            A[i] += K;
            cnt++;
            if(A[i-1]>=A[i]){
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}