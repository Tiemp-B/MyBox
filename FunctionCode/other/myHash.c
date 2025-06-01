#include <stdlib.h>
#include <string.h>

/* <string, int> 해시맵
recommand prime number for KEY
101, 103, 127
1009 1031 1061
10007 12289 16381
131071 262147
1048573 2097143
*/

#define KEY 131071

typedef struct Node{
    char *key;
    int value;
    struct Node *next;
} Node;

Node** hash_Init();
unsigned int simple_hash(const char*);
void hash_Insert(Node**, const char*, int, int*);   // 테이블주소, 키, 값, 크기 담을 int
Node* hash_Find(Node**, const char*);               // 테이블 주소, 키
int hash_Remove(Node**, const char*, int*);         // 테이블주소, 키, 테이블크기 
void hash_Clear(Node**, int *);                            // hash 초기화
void hash_Delete(Node**, int *);                           // hash 제거

Node** hash_Init(){
    return (Node**)calloc(KEY, sizeof(Node*));
}

unsigned int simple_hash(const char* key){
    unsigned int hash = 0;
    while(*key) hash = (hash*31 + *key++)%KEY;
    return hash;
}

void hash_Insert(Node** table, const char* key, const int value, int* count){
    unsigned int idx = simple_hash(key);
    Node* cur = table[idx];

    while(cur){
        if(strcmp(cur->key, key)==0) {
        cur->value = value;
        return;
        }
        cur = cur->next;
    }

    Node* temp =(Node*)malloc(sizeof(Node));
    temp->key = strdup(key); // key 문자열 내용 복사
    temp->value = value;
    temp->next = table[idx];
    
    table[idx] = temp;
    (*count)++;
}

Node* hash_Find(Node** table, const char* key){
    unsigned int idx = simple_hash(key);
    Node* cur = table[idx];

    while(cur){
        if(strcmp(cur->key, key)==0) return cur;
        cur = cur->next;
    }

    return NULL;
}

int hash_Remove(Node** table, const char* key, int* count){
    unsigned int idx = simple_hash(key);
    Node* cur = table[idx];
    Node* prev = NULL;
    while(cur){
        if(strcmp(cur->key, key)==0){
            if(prev) prev->next = cur->next;
            else table[idx] = cur->next;

            free(cur->key);
            free(cur);
            (*count)--;
            return 0;
        }
        prev = cur;
        cur = cur->next;
    }
    return -1;
}

void hash_Clear(Node** table, int *count){
    for(int i=0; i<KEY; ++i){
        Node* cur = table[i];
        while(cur){
            Node* next = cur->next;
            (*count)--;
            free(cur->key);
            free(cur);
            cur = next;
        }
        table[i] = NULL;
    }
}

void hash_Delete(Node** table, int* count){
    hash_Clear(table, count);
    free(table);
}
