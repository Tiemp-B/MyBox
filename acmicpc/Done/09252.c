#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mem[1002][1002]={};

int main(){
    char str1[1002];
    char str2[1002];
    char temp[1001];

    scanf(" %s", temp);
    sprintf(str1, " %s", temp);
    scanf(" %s", temp);
    sprintf(str2, " %s", temp);
    int l1 = strlen(str1);
    int l2 = strlen(str2);

    int ans =0 ;

    for(int i=1;i<l1; ++i){
        for(int j=1; j<l2; ++j){
            if(str1[i]==str2[j]){
                mem[i][j] = mem[i-1][j-1] + 1;
                if(ans < mem[i][j])
                    ans = mem[i][j];
            }else{
                if(mem[i-1][j] < mem[i][j-1]){
                    mem[i][j] = mem[i][j-1];
                }
                else{
                    mem[i][j] = mem[i-1][j];
                }
            }
        }
    }
    printf("%d\n", ans);
    int c = 1;
    int i=l1-1, j=l2-1;
    char str[1001];
    while(ans>0){
        if(mem[i][j]==mem[i-1][j-1]){
            i-=1;
            j-=1;
        }else if(mem[i][j] == mem[i-1][j]){
            i-=1;
        }else if(mem[i][j] == mem[i][j-1]){
            j-=1;
        }else if(mem[i][j] - 1 == mem[i-1][j-1]){
            str[ans-1] = str1[i];
            i-=1;
            j-=1; 
            ans-=1;
        }
        if(i<0||j<0) break;
    }

    printf("%s", str);

    return 0;
}
