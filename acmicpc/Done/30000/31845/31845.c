#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){ // 내림차순
    return (*(int*)b - *(int*)a);
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    int *arr = (int*)malloc(N*sizeof(int));

    for(int i=0; i<N;++i){
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    int head=0, tail=N-1, score=0;

    for(int i=0; i<M&&arr[i]>0;++i){
        score += arr[i];
        head++;
        tail--;
        if(tail<head) break;
    }

    printf("%d", score);

    return 0;
}