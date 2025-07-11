#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;

int main(){
    int N;
    cin >>N;
    unordered_map<string, int> mp;

    for(int i=0; i<N;++i){
        string str;
        cin >>str;
        string key="";
        for(int i=str.size()-1;i>=0; --i){
            key = str[i] + key;
            mp[key]++;
        }
    }
    int ans =0;
    for(auto e : mp){
        if(e.second==1) ans++;
    }
    cout <<ans;
    return 0;
}