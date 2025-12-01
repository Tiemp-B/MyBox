#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[5001];
int mem[5001][2]={};// 한자릿수인 가짓수, 두자릿 수인 가짓수
// 세부 분기 조절 필수!!
int main(){
    // init
    scanf("%s", str);
    mem[0][0]=0;
    mem[0][1]=1;
    int cond = 1;
    int idx;
    for(idx=1; str[idx-1]!='\0'&& cond; ++idx){
        if(idx==1){
            if(str[idx-1] == '0'){// 오류 케이스
                cond = 0;
                break;
            }
            mem[idx][0] = 1;
            mem[idx][1] = 0;
        }else{
            int pre = str[idx-2] -'0';
            int now = str[idx-1] -'0';
            if(pre*10 + now ==0){
                cond = 0;
                break;
            }else if(now == 0){// 두자릿수 강제
                if(pre*10+now>26){
                    cond = 0;
                    break;
                }
                mem[idx][0] = 0;
                mem[idx][1] = mem[idx-2][0] + mem[idx-2][1];
            }else if(pre==0 || pre*10+now>26){// 한자릿수 강제
                mem[idx][1] = 0;
                mem[idx][0] = mem[idx-1][0] + mem[idx-1][1];
            }else if(pre*10 + now ==0){
                cond = 0;
                break;
            }else{// 두자리, 한자리 둘 다 가능
                mem[idx][0] = mem[idx-1][0] + mem[idx-1][1];
                mem[idx][1] = mem[idx-2][0] + mem[idx-2][1];
            }
        }
        mem[idx][0] %= 1000000;
        mem[idx][1] %= 1000000;
    }
    

    if(0==cond)
        printf("0");
    else
        printf("%d", (mem[idx-1][0] + mem[idx-1][1])%1000000);

    return 0;
}