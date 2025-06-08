#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(31, 0);


int main(){
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    int N;

    cin >>N;
    if(N%2 !=0){
        cout << 0;
        return 0;
    }
    if(N==2){
        cout <<dp[N];
        return 0;
    }

    for(int i=4; i<=N;i+=2){
        for(int j=2; j<=i-2;j+=2)
            dp[i] += (j==2? 3: 2) * dp[i-j];
        dp[i] +=2;
    }

    cout << dp[N];

    return 0;
}