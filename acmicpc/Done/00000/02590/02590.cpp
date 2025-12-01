#include <iostream>
#include <deque>
using namespace std;

int p[7];
int ans = 0;

int blank[3] = {0};


void init(){
    for(int i=1; i<=6; i++)
        cin >> p[i];
}

void calc(){
    // 6
    ans += p[6];
    // 5
    ans += p[5];
    blank[1] += p[5] * 11;
    // 4
    ans += p[4];
    blank[2] += p[4] * 5;
    // 3
    ans += p[3] / 4;
    p[3] %= 4;
    switch(p[3]){
        case 0:
            break;
        case 1:
            blank[2] += 2;
            blank[1] += 1;
        case 2:
            blank[2] += 2;
            blank[1] += 1;
        case 3:
            blank[2] += 1;
            blank[1] += 5;
        default:
            ans += 1;
    }
    // 2
    if(blank[2] >= p[2]){
        blank[2] -= p[2];
        blank[1] += blank[2] * 4;
    }else{
        p[2] -= blank[2];
        ans += p[2] / 9;
        p[2] %= 9;
        if(p[2] > 0){
            ans++;
            blank[1] += 36 - p[2] * 4;
        }
    }
    // 1
    if(blank[1] < p[1]){
        p[1] -= blank[1];
        ans += p[1] / 36;
        p[1] %= 36;
        if(p[1] > 0)
            ans += 1;
    }
    cout << ans;
}

int main(){
    init();

    calc();

    return 0;
}