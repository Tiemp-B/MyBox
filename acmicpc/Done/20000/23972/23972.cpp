#include <iostream>

using namespace std;

int main(){

    long long int K, N;
    cin >>K >>N;
    long long int ans =0;
    if (N == 1){
        cout <<-1;
        return 0;
    }
    if (K*N %(N-1) == 0){
        ans = K*N/(N-1);
    }else{

        ans = K*N/(N-1)+1;
    }

    // (X-K)*N >= X
    // X(N-1) >= K*N
    // X >= K*N/(N-1)
    cout <<ans;

    return 0;
}