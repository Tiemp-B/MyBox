#include <iostream>

using namespace std;

int main(){
    string P1,P2;
    cin >>P1 >>P2;

    string old, lat;
    for(int i=0; i<8;i++){
        old.push_back(P1[i]);
        old.push_back(P2[i]);
    }

    while(old.length()>2){
        lat.clear();
        for(int i=0; i<old.length()-1;i++){
            int gap = old[i]-'0'+old[i+1]-'0';
            lat.push_back('0'+gap%10);
        }
        old = lat;
    }
    cout << old;

    return 0;
}