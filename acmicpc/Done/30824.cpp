#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

unordered_set<long long> st[4];

long long l1=1, l2=2;

void st_update(){
    long long x= 10000000000000000;
    long long temp;
    while(x > l2){
        temp = l1 + l2;
        if(temp > x) break;
        st[1].insert(temp);
        l1 = l2;
        l2 = temp;
    }

    for(auto e1:st[1]){ 
        for(auto e:st[1]){
            st[2].insert(e+e1);
        }
    }

    for(auto e2:st[2]){
        for(auto e1:st[1]){
            st[3].insert(e1+e2);
        }
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >>T;
    st[1].insert(1);
    st[1].insert(2);

    long long k, x;

    st_update();

    while(T-->0){
        cin >> k >> x;
        if(st[k].find(x)!=st[k].end())
            cout <<"YES\n";
        else
            cout <<"NO\n";
    }

    return 0;
}