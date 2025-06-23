#include <stdio.h>

int main(){
    int a=1, b=1, c=1;

    while(1){
        scanf(" %d %d %d", &a, &b, &c);
        if(a == 0) break;
        int aa = a*a;
        int bb = b*b;
        int cc = c*c;
        int flag = 0;
        if(aa + bb == cc)
            flag =1;
        else if(aa + cc == bb)
            flag = 1;
        else if(aa == bb+cc)
            flag = 1;
        if(flag) printf("right\n");
        else printf("wrong\n");
    }

    return 0;
}