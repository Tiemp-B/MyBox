#include <stdio.h>

int N, M;
int queue[8];

void recur(int idx, int cnt){
    if (cnt == M){
        for(int i=0; i<M; i++)
            printf("%d ", queue[i]);
        printf("\n");
        return;
    }

    if (idx > N)
        return;

    for(int i=idx; i<=N; i++){
        queue[cnt] = i;
        recur(i+1, cnt+1);
    }
    
}

int main(){
    scanf("%d %d", &N, &M);

    recur(1, 0);    

    return 0;
}