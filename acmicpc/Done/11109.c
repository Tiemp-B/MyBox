#include <stdio.h>

int main(){
    int T;
    scanf("%d",&T);

    char ans[3][20]={
        "do not parallelize\n",
        "parallelize\n",
        "does not matter\n"
    };

    for(int tc=0; tc<T; ++tc){
        int d, n, s, p;
        scanf("%d %d %d %d", &d, &n, &s, &p);
        int p_time = d + n*p;
        int s_time = n*s;
        if(p_time > s_time)
            printf("%s", ans[0]);
        else if(p_time<s_time)
            printf("%s", ans[1]);
        else
            printf("%s", ans[2]);
    }

    return 0;
}
