#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char S[101];

    scanf("%s", S);

    int *loc = (int*)malloc(sizeof(int)*26);
    memset(loc, -1, 26*sizeof(int));

    for(int i=0; S[i]!='\0'; ++i){
        if(loc[S[i]-'a'] == -1)
            loc[S[i]-'a'] = i;
    }

    for(int i=0; i<26;++i){
        printf("%d ", loc[i]);
    }

    return 0;
}