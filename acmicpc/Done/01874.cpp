#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >>n;

    vector<int> v1(1);
    v1[0] = 0;
    vector<bool> log;
    vector<int> v;
    int mx = 1;
    for(int i=0, temp; i<n;++i){
        cin >> temp;
        if(v1.back() < temp){
            for(int now=mx; now<=temp; ++now){
                v1.push_back(now);
                log.push_back(true);
            }
            v1.pop_back();
            log.push_back(false);
            mx = temp+1;
        }else if(v1.back()== temp){
            v1.pop_back();
            log.push_back(false);
        }else{
            cout <<"NO";
            return 0;
        }
    }

    for(auto e : log){
        if(e) cout <<"+\n";
        else cout <<"-\n";
    }

    return 0;
}