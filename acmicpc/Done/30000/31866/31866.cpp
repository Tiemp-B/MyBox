#include <iostream>

using namespace std;


int main(){
    int A, B;
    cin >>A >>B;

    if(A!=0&&A!=2&&A!=5) A = 10;
    if(B!=0&&B!=2&&B!=5) B = 10;
    
    if(A == B){
        cout << "=";
    }else if(A==0 &&B ==5) cout << "<";
    else if(A==5 && B==0) cout <<">";
    else if(A < B) cout <<">";
    else cout <<"<";

    return 0;
}