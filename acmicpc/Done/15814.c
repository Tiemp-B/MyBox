#include <stdio.h>

int main(){
    char str[101];
    scanf("%s", str);

    int T;
    scanf("%d", &T);
    for(int tc = 0; tc<T;++tc){
        int a, b;
        scanf("%d %d", &a, &b);
        char temp = str[a];
        str[a] = str[b];
        str[b] = temp;
    }

    printf("%s", str);

    return 0;
}