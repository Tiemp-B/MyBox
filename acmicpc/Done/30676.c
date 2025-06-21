#include <stdio.h>

int main(){
    int v;
    scanf("%d", &v);
    
    char name[7][10]={
        "Red",
        "Orange",
        "Yellow",
        "Green",
        "Blue",
        "Indigo",
        "Violet"
    };

    int ans = 6;

    if(v >= 620)
        ans = 0;
    else if(v>=590)
        ans = 1;
    else if(v>=570)
        ans = 2;
    else if(v>=495)
        ans = 3;
    else if(v>=450)
        ans = 4;
    else if(v>=425)
        ans = 5;

    printf("%s", name[ans]);

    return 0;
}