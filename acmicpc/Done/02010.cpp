#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int ans = 0;

    for(int i=0, temp; i<N; i++){
        cin >> temp;
        ans += temp;
    }
    ans -= N;

    cout << ans+1;

    return 0;
}