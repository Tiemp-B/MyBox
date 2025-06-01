#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

struct dat{
    int rank = 0;
    set<string> ances;
    set<string> desce;
    set<string> child;
};

int N, M;

map<string, dat> mp;
vector<string> ances_cnt[1001];

void init(){
    cin >>N;
    string temp, temp2;
    for(int i=0; i<N;++i){ // O(N)
        cin >>temp;
        mp[temp];
    }
    cin >>M;
    for(int i=0;i<M;++i){ // O(N^2)
        cin >>temp >> temp2;
        mp[temp].ances.insert(temp2);
        mp[temp2].desce.insert(temp);
    }
}

void calc(){
}

void output(){
    /*
    조상 수
    조상 이름 (사전순)
    이름 자식수 자식이름 (사전순)
    */
    for(auto item : mp)
        ances_cnt[item.second.ances.size()].push_back(item.first);

    for(int i=1; !ances_cnt[i].empty(); ++i){
        for(auto name : ances_cnt[i]){
            for(auto upper_name : ances_cnt[i-1]){
                if(mp[name].ances.find(upper_name) != mp[name].ances.end()){
                    mp[upper_name].child.insert(name);
                }
            }
        }
    }

    cout << ances_cnt[0].size() <<"\n";
    for(auto item : ances_cnt[0])
        cout << item <<" ";
    cout <<"\n";

    for(auto item : mp){
        cout << item.first<<" " << item.second.child.size()<<" ";

        for(auto name : item.second.child) 
            cout << name<<" ";
        cout <<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    init();
    output();
    return 0;
}