#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int pow(int n, int p){
    int ret = 1;
    for(int i=0; i<p ;++i) ret *= n;
    return ret;
}

int main(){
    int A, P;
    cin >>A >>P;

    unordered_map<int, int> mp;
    int idx = 1;
    mp[A] = idx++;
    int prev = A;
    for(;true;){
        int nex = 0;
        while(prev>0){
            int r = prev%10;
            nex += pow(r, P);
            prev /= 10;
        }
        if(mp[nex]!=0){
            prev = nex;
            break;
        }
        mp[nex] = idx++;
        prev = nex;
    }
    cout <<  mp[prev] - 1;

    return 0;
}
