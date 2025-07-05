#include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >>M;
    long long int mod = 1000000007;
    long long int ans = 1, gap = 1;
    for(int i=0; i<N;++i) {
        ans *= M;
        ans %= mod;
    }
    for(int i=0; i<N; ++i) {
        gap *= M-1;
        gap %= mod;
    };
    //ans가 gap보다 작을 수도 있다. -> mod를 더해서 보정.
    //
    cout << (ans-gap + mod)%mod;

    return 0;
}