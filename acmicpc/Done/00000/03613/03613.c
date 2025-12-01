#include <stdio.h>
#include <string.h>

char str[101];

int checker(){// -1: err 1 : c++ 0 : java
    int cpp = 0;
    int jav = 0;
    if(str[0] == '_')
        return -1;
    else if(str[0]>='A' &&  str[0] <='Z')
        return -1;
    char before = str[0];
    for(int i=0; i<101;i++){
        if(str[i] == '_'){
            cpp++;
            if(str[i+1]== '\0' || str[i+1]=='_')
                return -1;
        }
        else if(str[i]>='A' &&  str[i] <='Z')
            jav++;
    }

    if(jav&&cpp)
        return -1;
    else if(jav)
        return 0;
    else 
        return 1;

}

void jav2cpp(){
    for(int i=0; i<101 && str[i]!='\0'; i++){
        if(str[i]>='A' && str[i]<='Z')
            printf("_%c", str[i]-'A' + 'a');
        else
            printf("%c", str[i]);
    }
}

void cpp2jav(){
    for(int i=0; i<101 && str[i]!='\0'; i++){
        if(str[i] == '_'){
            printf("%c", str[++i] -'a' +'A');
        }else
            printf("%c", str[i]);
    }
}

int main(){
    scanf("%s", str);

    int mode = checker();
    if(mode < 0)
        printf("Error!");
    else if(mode > 0)
        cpp2jav();
    else 
        jav2cpp();
        

    return 0;
}