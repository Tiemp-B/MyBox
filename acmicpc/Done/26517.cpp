#include <iostream>

using namespace std;

int main(){
    long long a, b, c, d, k;
    cin >> k >>a >>b >> c >> d;

    if (a*k+b == c*k+d)
        cout << "Yes "<< a*k+b;
    else
        cout << "No";

    return 0;
}