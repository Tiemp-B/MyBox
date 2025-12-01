#include <iostream>
#include <vector>
using namespace std;

int w, n;
vector<int> el;
pair<int, int> num[400'001];

void init(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >>w >>n;
    el.resize(n);
    for(auto &e: el) cin >> e;
}

inline bool same(pair<int, int> p){
    return p.first == p.second; 
}

inline bool cmp(pair<int, int> p, int a, int b){
    return p.first==a||p.second==a||p.first==b||p.second==b;
}

bool calc(){
    for(int i=0, s; i<n;++i){
        for(int j=i+1;j<n;++j){
            s=el[i]+el[j];
            if(!same(num[s])) continue; // 이미 기록됨
            num[s]={i, j};
        }
    }
    for(int i=n-1, s; i>=0; --i){
        for(int j=i-1; j>=0; --j){
            s=el[i]+el[j];
            s=w-s;
            if(s>400'000) continue; // 필요한 두 수의 합이 가능 범위 밖인 경우
            if(s<=0) continue; // 필요 값이 음수인 경우
            if(same(num[s])) continue; // 생성된 적 없음
            if(cmp(num[s], i, j)) continue; // i혹은 j가 중복사용됨
            return true;
        }
    }
    return false;
}

int main(){
    init();
    if(calc()) cout <<"YES";
    else cout <<"NO";
    return 0;
}