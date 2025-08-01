#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int t1=0, t2=0, s1=0, s2=0, tim=0;
    for(int i=0;i<n;++i){
        int t, mm, ss;
        scanf("%d %d:%d",&t, &mm, &ss);
        int tt= mm*60+ss;
        if(s1<s2){
            t2 += tt-tim;
        }else if(s1>s2){
            t1 += tt-tim;
        }
        if(t==1) s1++;
        else s2++;
        tim = tt;
    }
    int end_time = 48*60;
    if(s1<s2)
        t2 += end_time-tim;
    else if(s1>s2)
        t1 += end_time-tim;
    printf("%02d:%002d\n%02d:%02d",t1/60,t1%60, t2/60,t2%60);
    return 0;
}
