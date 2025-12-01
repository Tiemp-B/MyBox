#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> p(246913, true);
    p[0] = false;
    for(int i=2; i<=246913; ++i){
        if(!p[i]) continue;
        for(int j=i+i; j<=246913;j+=i){
            p[j] = false;
        }
    }
    

    do {
        cin >> n;
        if(n==0) break;
        int ans = 0;
        for(int i=n+1; i<=n*2;++i){
            if(p[i]) ans++;
        }
        cout << ans << endl;
    } while(true);

    return 0;
}