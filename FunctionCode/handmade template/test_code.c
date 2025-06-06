#include <stdio.h>
#include "myHash.c"

int cond = 1;

void hash_test(){
    int count = 0;
    Node** hash_table = hash_Init();
    
    char keys[5][100] ={
        "apple",
        "pear",
        "melon",
        "kiwi",
        "tomato"
    };
    int values[5]= {3, 4, 5, 2, 1};
    printf("----insert test----\n");
    for(int i=0; i<5; ++i){
        hash_Insert(hash_table, keys[i], values[i], &count);
        Node* temp = hash_Find(hash_table, keys[i]);
        printf("key: %6s value: %d count: %d\n", keys[i], temp->value, count);
    }

    if(cond){
        cond = 0;
        printf("----multi----\n");
        hash_test();
        printf("----multi end----\n");
    }

    printf("----modify test----\n");
    hash_Insert(hash_table, keys[3], 45, &count);
    printf("key:%s value: %d -> %d\n", keys[3], values[3], hash_Find(hash_table, keys[3])->value);
    
    printf("----remove test----\n");
    hash_Remove(hash_table, keys[3], &count);
    printf("count: %d\n", count);
    
    printf("----clear test----\n");
    hash_Clear(hash_table, &count);
    printf("count: %d\n", count);
}


int main(){
    printf("hello\n");
    hash_test();
    return 0;
}
