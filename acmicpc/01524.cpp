#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >>T;
    while(T-->0){
        int N, M;
        cin >> N>>M;
        int S=0, B=0, temp;
        while(N-->0){
            cin >> temp;
            if(S<temp)
                S = temp;
        }
        while(M-->0){
            cin >> temp;
            if(B<temp)
                B = temp;
        }
        if(S>=B)
            cout << "S\n";
        else
            cout <<"B\n";
    }
    return 0;
}