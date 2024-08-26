#include <iostream>
#include <vector>
#include <map>

using namespace std;

string card[10][5];
map<vector<int>, double> cache;

bool done(vector<int>&v){ // 참조
    for (int i= 1; i<10;i++)
        if (v[i] != 0) return false;
    return true;
}

double func(vector<int> now){
    if (done(now)) return 1.0;
    if (cache.find(now) != cache.end()) return cache[now];
    
    double& ret = cache[now];
    ret = 0.0;
    vector<pair<int, int>> canSelect;
    for(int i=1; i<10;i++){
        for (int j=i+1; j<10; j++){
            bool cond1 = now[i]!=0;
            bool cond2 = now[j]!=0;
            bool cond3 = card[i][now[i]][0]==card[j][now[j]][0];
            if(cond1&&cond2&&cond3)
                canSelect.push_back(make_pair(i, j));
        }
    }
    if (canSelect.empty()) return ret = 0.0;
    
    for (auto p : canSelect){
        int i = p.first, j = p.second;
        vector<int> next = now;
        next[i]--, next[j]--;
        ret += func(next)*(1.0/(double)canSelect.size());
    }
    return ret;
}

int main(){
    for(int i=1; i<10 ;i++){
        for(int j=0; j<4;j++){
            cin >>card[i][j];
        }
    }
    vector<int> start(10, 4);
    cout << func(start);
    return 0;
}


