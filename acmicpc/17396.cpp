#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> avail;
vector<vector<pair<int, long long>>> road; // {경로, 비용}

void init(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >>N >>M;
    avail.resize(N);
    road.resize(N);
    for(auto &e : avail) cin >> e;
    for(int i=0, s, e, t; i<M; ++i){
        cin >>s >>e >>t;
        if((s!=N-1 && avail[s]==1) ||(e!=N-1&&avail[e]==1)) continue; // 도착점이 아닌 시야가 보이는 지점은 스킵
        road[s].push_back({e, t});
        road[e].push_back({s, t});
    }
}

void calc(){
    long long mxx=30000000001;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {cost, now}
    vector<long long> total(N, mxx);// i 지점까지의 비용
    pq.push({0, 0});
    total[0]=0;
    while(!pq.empty()){
        long long cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(cost > total[now]) continue;
        for(auto nx : road[now]){
            int nex = nx.first;
            long long tim = nx.second;
            if(total[nex] > total[now] + tim){
                total[nex] = total[now] + tim;
                pq.push({total[nex], nex});
            }
        }
    }
    if(total[N-1] == mxx) cout <<-1;
    else cout <<total[N-1];
}
void calc_old(){
    long long mxx=30000000001;
    long long ans=mxx;
    priority_queue<pair<long long, int>> pq; // {cost, now}
    pq.push({0, 0});
    vector<long long> total(N, mxx);
    total[0]=0;
    int cnt=0;
    while(!pq.empty()){
        auto e = pq.top();
        long long cost = e.first;
        int now = e.second;
        pq.pop();
        for(auto nx : road[now]){
            cnt++;
            int nex = nx.first;
            long long tim = nx.second;
            if(nex == N-1){ // 도착지
                ans = min(ans, cost+tim);
            }else if(avail[nex] == 1){
                continue;
            }else{ // 경유지
                if(total[nex] > cost+tim){
                    total[nex] = cost+tim;
                    pq.push({cost+tim, nex});
                }
            }
        }
    }
    if(ans == mxx) cout <<-1;
    else cout <<ans;
    cout <<"\nold : "<< cnt;
}

void A_star(){



}

int main(){
    init();
    calc();
    calc_old();
    return 0;
}