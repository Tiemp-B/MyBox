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
        }#include <iostream>
#include <vector>
//#include <algorithm>
#include <map>

using namespace std;

string card[10][5];
map<vector<int>, double> cache;

bool done(vector<int>&v){ // 1~9까지 모두 사용 했는가를 파악
    for (int i= 1; i<10 ;i++)
        if (v[i] != 0) return false;
    return true;
}
/*
저장을 할 항목과 뽑을 방법
 */
double f(vector<int> now){
    /*--불가, 이전에 계산한 값 검색 및 반환--*/
    if (done(now)) return 1.0; // 모두 사용했으면 1 반환
    if (cache.find(now) != cache.end()) return cache[now]; //현재 루트가 존재했으면 cache[now]의 확률 반환

    /*--확률 계산--*/
    double& ret = cache[now]; //cache[now] 와 연동
    ret = 0.0;
    vector<pair<int, int>> canSelect;
    for (int i=1; i<10; i++){
        for (int j= i+1 ; j< 10; j++){
            bool cond1 = (now[i] != 0); // i행이 다 썼는가
            bool cond2 = (now[j] != 0); // j행이 다 썼는가
            bool cond3 = (card[i][now[i]][0] == card[j][now[j]][0]); // i행의 now[i]번째의 첫 글자와 j행의 now[j]번째의 첫 글자의 동일;
            if (cond1 && cond2 && cond3)
                canSelect.push_back({i, j});
        }
    }
     
    if (canSelect.empty()) return ret = 0.0; // 짝 만들 수 없음 -> 0 반환

    for (auto p : canSelect) {
        int i = p.first, j = p.second; //  
        vector<int> next = now; // now를 next로 복사 함
        next[i]--, next[j]--; // i, j행의 순서를 바꿈
        ret += f(next)*(1.0 / (double)canSelect.size()); // += (후속)*(1.0/선택지 수)
    }
    return ret;
}

int main(){
    for (int i = 1; i<=9 ; i++)
        for (int j = 1; j<= 4;j++) cin >> card[i][j];
    vector<int> start(10, 4);
    cout << f(start);
}


    }
    vector<int> start(10, 4);
    cout << func(start);
    return 0;
}


