#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 131071

typedef struct Node{
    char *key;
    struct  Node* next;
} Node;

Node** table;
int count=0;

unsigned int hashing(const char* key){
    unsigned int hash = 0;
    while(*key) hash = (hash*31 + *key++)%KEY;
    return hash;
}

void inserting(const char* key){
    unsigned int idx = hashing(key);
    Node* cur = table[idx];
    while(cur){
        if(strcmp(cur->key, key)==0) return; // 이미 존재함
        cur = cur->next;
    }

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = strdup(key);
    temp->next = table[idx];

    table[idx] = temp;
    count++;
}

int deleting(const char* key){ // 성공시 0, 실패시 -1
    unsigned int idx = hashing(key);
    Node* cur = table[idx];
    Node* prev = NULL;

    while(cur){
        if(strcmp(cur->key, key)==0) {
            if(prev) prev->next = cur->next;
            else table[idx] = cur->next;

            free(cur->key);
            free(cur);
            
            count--;
            return 0;
        }
        prev = cur;
        cur = cur->next;
    }

    return -1;
}

void clearing(){
    for(int i=0; i<KEY; ++i){
        Node* cur = table[i];
        while(cur){
            Node* next = cur->next;
            free(cur->key);
            free(cur);
            cur = next;
        }
        table[i] = NULL;
    }
}

int main(){
    table = (Node**)calloc(KEY, sizeof(Node*));

    int N, M;
    scanf("%d %d", &N, &M);

    char buff[11];
    for(int i=0; i<N; ++i){
        scanf("%s ", buff);
        inserting(buff);
    }

    for(int i=0;i<M;++i){
        char c;
        int flag = 1, idx=0;
        while(flag){
            c = getc(stdin);
            switch(c){
                case ',': // 쉼표 확인
                    buff[idx]='\0';
                    deleting(buff);
                    idx=0;
                    break;
                case 10: // 엔터 입력 감지
                    buff[idx]='\0';
                    deleting(buff);
                    idx=0;
                    flag = 0;
                    break;
                default:
                    buff[idx++] = c;
            }
        }
        printf("%d\n", count);
    }
    clearing();
    free(table);

    return 0;
}