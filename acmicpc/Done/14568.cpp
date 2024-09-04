#include <iostream>

using namespace std;


int main(){
    int N;
    cin >>N;
    //N개를 셋이, 남>= 영+2,  모두 >0, 택희 %2 = 0
    // 택희 = 2, 4, 6, 8, 10 ....
    // (남,영) = (3,1), (4,2)

    if(N<6){
        cout <<0;
        return 0;
    }

    int ans = 0;

    for(int t = 2; t<N; t+=2){
        int lef = N- t;
        if (lef < 4) break; 
        ans += lef/2 - 1;
    }

    cout <<ans;


    return 0;
}