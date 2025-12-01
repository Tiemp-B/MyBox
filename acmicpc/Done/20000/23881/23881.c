#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int* mem = (int*)malloc(sizeof(int)*N);
    
    for(int i=0; i<N;++i){
        scanf("%d",&mem[i]);
    }

    for(int last=N-1; last>=0; --last){
        int mx=0, mx_idx=0;
        for(int i=0; i<=last;++i){
            if(mx<mem[i]){
                mx_idx = i;
                mx = mem[i];
            }
        }
        if(mx_idx == last) continue;
        if(--K){
            mem[mx_idx] = mem[last];
            mem[last] = mx;
        }else{
            if(mx < mem[last])
                printf("%d %d", mx, mem[last]);
            else
                printf("%d %d", mem[last], mx);
            return 0;
        }
    }
    printf("-1");

    return 0;
}