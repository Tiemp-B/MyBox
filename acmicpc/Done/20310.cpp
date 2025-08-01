#include <iostream>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n1=0, n0=0;
    string str;
    cin >> str;
    for(int i=0; i<str.size();++i){
        if(str[i]=='0') n0++;
        else n1++;
    }
    n1/=2;
    n0/=2;
    for(int i=0;i<str.size();++i){
        if(str[i]=='0'){
            if(--n0<0) 
                continue;
        }else if(str[i]=='1'){
            if(--n1>=0) 
                continue;
        }
        cout <<str[i];
    }

    return 0;
}