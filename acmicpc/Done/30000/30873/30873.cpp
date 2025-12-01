#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >>N;
    int X=0;
    for(int i=0, P,C;i<N;i++){
        cin >>P>>C;
        if(abs(P-X) > C)continue;
        X++;
    }

    cout <<X;
    

    return 0;
}