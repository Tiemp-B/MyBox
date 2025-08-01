#include <iostream>
#define endl '\n'
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc=0, n;
    long long arr[50000];
    long long smm[50001];
    long long d;
    cin >> tc;
    while(tc-->0){
        cin >>d >>n;
        for(int i=0;i<n;++i){
            cin>> arr[i];
            smm[i+1] = (smm[i]+arr[i]);
        }
        int ans =0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<=n;++j){
                if((smm[j]-smm[i])%d==0) ans++;
            }
        }
        cout <<ans<<endl;
    }
    return 0;
}