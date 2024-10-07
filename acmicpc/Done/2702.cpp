#include <iostream>

using namespace std;
int GCD(int a, int b);
int LCM(int a, int b, int GCD);


int main(){
    int T;
    cin >>T;

    for(int t=0,a,b; t<T; t++){
        cin >>a >>b;
        int gcd = GCD(a, b);
        int lcm = LCM(a, b, gcd);

        cout << lcm <<" "<<gcd<<endl;
    }

    return 0;
}

int GCD(int a, int b){
    int ans =1, less = (a>b)? b:a;

    for(int t=2; t<=less; t++){
        if(a%t==0 && b%t==0){
            ans = t;
        }
    }
    return ans;
}


int LCM(int a, int b, int GCD){
    int ans = a/GCD * b/GCD;
    ans *= GCD;
    return ans;
}
