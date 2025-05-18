#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M, root;
int **connect;
int *length;
int *DFS_LOG;
int *BFS_LOG;
int *LOG;
void init(){
    scanf("%d %d %d", &N, &M, &root);
    DFS_LOG = (int*)malloc(sizeof(int) *(N+1));
    BFS_LOG = (int*)malloc(sizeof(int) *(N+1));
    LOG     = (int*)calloc(0, sizeof(int) *(N+1));
    connect =(int**)malloc(sizeof(int*) *(N+1));
    length  = (int*)calloc(0, sizeof(int) *(N+1));
    for(int i=0, from, to; i<M;++i){
        scanf("%d %d", &from, &to);
        connect[from][length[from]++] = to;
        connect[to][length[from]++] = from;
    }
}

void DFS(int n){
    printf("%d ", n);
    for(int i=0; i<);
}

void BFS(int n){

}

void main(){
    init();
    DFS(root);

    BFS(root);

    return 0;
}