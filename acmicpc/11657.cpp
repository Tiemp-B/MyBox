#include <iostream>
#include <vector>
#define INF 2147483647 
using namespace std;

struct road{
    int from;
    int to;
    int value;
};
int N, M;
vector<road> roads;
 
void init(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >>N >>M;
    roads.resize(M);
    for(auto &e : roads) cin >>e.from >>e.to >> e.value;
}

void calc(){
    vector<long long> far(N+1, INF);
    far[1] = 0;
    bool flag =false;
    long long c;
    for(int n=1; n<=N;++n){
        for(auto &r : roads){
            c = far[r.from] + r.value;
            if(far[r.from] != INF && far[r.to] > c){ // far[r.from]==INF 면 출발지서 오지 못한 곳.
                far[r.to] = c;
                if(n == N) {
                    cout << -1;
                    return;
                }// 마지막 단계에서도 갱신되면 감소 루프 형성
            }
        }
    }
    if(flag) cout <<-1;
    else{
        for(int i=2; i<=N;++i){
            if(far[i] == INF)
                cout << "-1\n";
            else
                cout <<far[i]<<"\n";
        }
    }
}

int main(){
    init();
    calc();

    return 0;
}