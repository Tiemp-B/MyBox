#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

struct node{
    vector<long long> cnt;
    long long total=0;
};

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int T,n;
    cin >> T;
    vector<node> v(65);
    
    v[1].cnt.resize(10,1);
    v[1].total = 10;

    for(int i=2;i<65;++i){
        v[i].cnt.resize(10, 0);
        for(int d=0; d<10;++d){
            for(int j=d; j<10;++j){
                v[i].cnt[d]+=v[i-1].cnt[j];
            }
            v[i].total += v[i].cnt[d];
        }
    }

    while(T-->0){
        cin >> n;
        cout <<v[n].total<<endl;
    }
    
    return 0;
}