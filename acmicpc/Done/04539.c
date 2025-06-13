#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    for(int tc=0,x; tc<T; ++tc){
        scanf("%d", &x);
        int bound = 10;
        while(x > bound){
            int l = (x%bound)/(bound/10);
            x -= l * (bound/10);
            if(l>4)
                x += bound;
            bound *= 10;
        }
        printf("%d\n",x);
    }
    return 0;
}