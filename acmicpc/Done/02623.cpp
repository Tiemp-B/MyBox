#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int N, M;

vector<unordered_set<int>> nex; 
vector<unordered_set<int>> entry;
bool flag = false;

void init(){
    cin >> N >> M;
    nex.resize(N+1);
    entry.resize(N+1);
    for(int i=0; i<M;++i){
        int L;
        cin >> L;
        vector<int> t;
        for(int j=0; j<L ;++j){
            int temp;
            cin >> temp;
            t.push_back(temp);
        }
        for(int j=1; j<L;++j){
            int f = t[j-1];
            int s = t[j];
            nex[f].insert(s); // f 다음에 올 s들
            entry[s].insert(f); // s 앞에 와야할 f들
            if(nex[s].empty()) continue;// s 다음에 올 애들이 없으면 continue
            if(nex[s].find(f) != nex[s].end()){// s다음에 올 애들 중 f가 있으면
                flag = true;
            }
        }
    }
}

void calc(){
    if(flag){
        cout << 0;
        return;
    }
    queue<int> q;
    for(int i=1; i <=N ;++i){
        if(entry[i].size() == 0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int e = q.front();
        q.pop();
        ans.push_back(e);
        for(auto n : nex[e]){
            entry[n].erase(e);
            if(entry[n].size()==0){
                q.push(n);
            }
        }
    }
    if(ans.size()!=N){
        cout <<0;
        return;
    }
    for(auto e : ans)
        cout << e<<endl;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    init();
    calc();
    return 0;
}