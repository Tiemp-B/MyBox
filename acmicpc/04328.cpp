#include <iostream>
#include <deque>
#include <string>
#include <cstdio>
using namespace std;

int b;
void calc(){
    string p,m;
    cin >> p>>m;
    long long int mm=0, dec = 1;
    for(int i=m.size()-1; i>=0; --i, dec*=b)
        mm += dec*((long long)(m[i]-'0'));

}



int main(){
    while(true){
        cin >>b;
        if(b == 0) break;
        calc();
    }

    return 0;
}