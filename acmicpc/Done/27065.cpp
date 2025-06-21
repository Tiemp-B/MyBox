#include <iostream>
#include <vector>

using namespace std;

struct datas{
    bool type=false; // 
    int under_sum = 0;
    vector<int> under;
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    datas mem[5001];

    for(int i=1; i<=5000; ++i){
        int t = i;
        while(t<=5000){
            if(t != i) {
                mem[t].under_sum += i;
                mem[t].under.push_back(i);
            }
            t += i;
        }
        if(mem[i].under_sum > i) mem[i].type = true; // 과잉수 true
        
    }

    for(int tc=0,inp; tc<T;++tc){
        cin >> inp;
        if(!mem[inp].type) {
            cout << "BOJ 2022\n";
            continue;
        } 
        bool flag = false;
        for(int e : mem[inp].under){
            flag |= mem[e].type;
            if(flag) break;
        }
        if(flag) cout <<"BOJ 2022\n";
        else cout <<"Good Bye\n";
    }

    return 0;
}