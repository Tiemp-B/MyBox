#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct q_node{
    int value;
    q_node* next;
} q_node;

typedef struct Node{
    int value;
    int parent;
    q_node* front; // 연결 항목
    q_node* rear;
} Node;

int N; // <= 10000
Node *nodeList;
int* order;

void q_insert(int idx, int value){
    q_node* temp = (q_node*)malloc(sizeof(q_node));
    temp->value = value;
    temp->next = NULL;
    if(!nodeList[idx].rear){
        nodeList[idx].front = temp;
        nodeList[idx].rear = temp;
        return;
    }
    nodeList[idx].rear->next = temp;
    nodeList[idx].rear = temp;
}

int q_pop(int idx){

    return -1;
}


void init(){
    scanf("%d", &N);
    nodeList = (Node*)malloc(sizeof(Node) *(N+1));
    for(int i=1; i<=N;++i){
        scanf("%d", &nodeList[i].value);
        nodeList[i].parent = 0;
        nodeList[i].front = NULL;
        nodeList[i].rear = NULL;
    }

    for(int i=1, from, to; i<N;++i){
        scanf("%d %d", &from, &to);
        q_insert(from, to);
        q_insert(to, from);
    }
}

void BFS(){
    
}


int main(){
    init();

    return 0;
}