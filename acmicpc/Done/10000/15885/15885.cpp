#include <iostream>

using namespace std;


int main(){
    double a, b;
    cin >> a>> b; // 고장난 시계가 1초에 a/b초만큼 움직인다는 의미 

    double ratio = b/(b-a);

    int n = 1;
    int ans = 0;
    // cout <<"ratio "<< ratio<<endl;
    while(true){
        double a = n++*ratio;
        if (a <=2 && a>=-2){
            // cout << a<<endl;
            ans++;
        }
        else
            break;
    }

    cout <<ans;


    return 0;
}