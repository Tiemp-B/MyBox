#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M, root;
int **graph;
int *visited;
void init(){
    scanf("%d %d %d", &N, &M, &root);
    visited = (int*)malloc(sizeof(int)*(N+1));
    memset(visited, 0, sizeof(int)*(N+1));
    graph = (int**)malloc(sizeof(int*) * (N+1));
    for(int i=0; i<=N;++i){
        graph[i] = (int*)malloc(sizeof(int)*(N+1));
        memset(graph[i], 0, sizeof(int)*(N+1));
    }
    for(int i=0;i<M;++i){
        int f, t;
        scanf("%d %d", &f, &t);
        graph[f][t] = 1;
        graph[t][f] = 1;
    }

}

void DFS(int n){
    printf("%d ", n);
    visited[n] = 1;
    for(int i=1; i<=N;++i){
        if(visited[i]) continue;
        if(graph[n][i]) 
            DFS(i);
    }
}

typedef struct node{
    int idx;
    struct node* next;
}node;

node *front=NULL, *rear=NULL;

void q_push(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->idx = data;
    temp->next = NULL;
    if(!rear){
        front = temp;
        rear = temp;
    }else{
        rear->next = temp;
        rear = rear->next;
    }
}

int q_pop(){
    node *temp = front;
    if(front==rear) rear = NULL;
    front = front->next;
    int ans = temp->idx;
    free(temp);
    return ans;
}

void BFS(int n){
    q_push(n);
    memset(visited, 0, sizeof(int)*(N+1));
    visited[n]=1;
    while(front){
        int now = q_pop();
        printf("%d ", now);
        for(int i=1; i<=N; ++i){
            if(!graph[now][i]) continue;
            if(visited[i]) continue;
            q_push(i);
            visited[i] = 1;
        }
    }
}

int main(){
    init();
    DFS(root);
    printf("\n");
    BFS(root);

    return 0;
}
