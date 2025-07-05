#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long int N;
    cin >>N;
    if(N==0){
        cout << 0;
        return 0;
    }
    vector<pair<long long int, pair<long long int, long long int>>> v = {{}, {1,{1,1}}};
    long long int r = -2;
    long long int pos =1, neg = 0;
    long long int mn = 0, mx = 1;
    while(mn>N || mx <N){
        v.push_back({r, {r+neg, r+pos}});
        if(r+neg <mn)mn = r+neg;
        if(r+pos >mx)mx = r+pos;
        if(r<0) neg += r;
        else pos += r;
        r *= -2;
    }

    for(int i=0 ;i<v.size()-1 ;++i){
        int l = v.size()-1-i;// 
        if(v[l].second.first>N || v[l].second.second<N) {
            cout << "0";
            continue;
        }
        cout <<"1";
        N -= v[l].first;
    }
    

    return 0;
}
