#include <iostream>

using namespace std;

int main(){
    int N;
    float P;
    cin >>N >>P;
    float ans = P;

    switch(N/5){
        case(0):
            break;
        default:
            //cout <<"default\n";
            if(ans> P*0.75)
                ans = P*0.75;
        case(3):
            //cout <<"case 3\n";
            if(ans > P-2000)
                ans = P-2000;
        case(2):
            //cout <<"case 2\n";
            if(ans > P*0.9)
                ans = P*0.9;
        case(1):
            //cout << "case 1\n";
            if(ans > P-500)
                ans = P-500;
    }
    if(ans<0) ans = 0;
    cout <<ans;

    return 0;
}
