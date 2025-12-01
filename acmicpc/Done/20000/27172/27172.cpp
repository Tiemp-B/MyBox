#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct num{
    int score=0;
    bool pl = false;
    num() = default;
    num(int s) : score(s) {} 
};

int N;

vector<int> v;
vector<int> sc(1000001);
vector<bool>  ap(1000001, false);
void init(){
    cin >>N;
    for(int i=0, temp; i<N;++i){
        cin >> temp;
        v.push_back(temp);
        ap[temp] = true;
    }
}

void calc(){
    for(auto e : v){
        int t = e + e;
        while(t<=1000000){
            sc[t]--;
            if(ap[t]) sc[e]++;
            t += e;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    init();
    calc();
    
    for(auto e : v) cout <<sc[e]<<" ";

    return 0;
}