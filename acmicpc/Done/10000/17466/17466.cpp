#include <iostream>

using namespace std;

int main(){
    int N, P;
    cin >> N >> P;
    
    long long int ans= 1;

    for(int i=1; i<=N; i++){
        ans = ans* i ;
        if (ans >P)
            ans = ans%P;
    }
    
    cout << ans;
    
    return 0;
}