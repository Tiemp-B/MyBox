#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N;
    cin >>N;
    vector<long long> v(N);
    for(auto &e : v) cin >>e;

    if(N==1){
        cout <<"YES\n"<< -5 <<"\n"<< v[0] +5;
        return 0;
    }
    
    int Ar = v[1]-v[0];

    for(int i=0; i<N-1;++i){
        if(Ar != v[i+1]-v[i]){
            cout <<"NO";
            return 0;
        }
    }

    int Br = 3;
    int Cr = Ar-Br;
    int B0 = 2;
    int C0 = v[0] - B0;
    cout <<"YES\n";
    for(int i=0; i<N;++i){
        cout << B0 + Br*i<<" ";
    }
    cout <<endl;
    for(int i=0; i<N;++i){
        cout << C0 + Cr*i<<" ";
    }
    
    return 0;
}