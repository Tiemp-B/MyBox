#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, Q;
// Univ : A, B, C, D, E
// N: nodes : ~ 50000
// M: directionless roads : ~ 100000
// Q: univ's costing : ~20000
// 관리 비용 변동

// quick sort : nlogn

// 간선: E, 노드 V
// kruskal : E log E <= 100000 * 5
// Prim : E log V <= 100000 * 4log2


struct road{
    int cost_idx;
    int A;
    int B;
};

vector<vector<int>> nodes_roads; //
vector<road> roads;
vector<vector<pair<int, int>>> cost_road;
vector<bool> road_flag;
vector<bool> node_flag;
int cost[6];

void init(){
    cin >>N >>M >>Q;
    nodes_roads.resize(N+1);
    roads.resize(M);
    road_flag.resize(M);
    node_flag.resize(N+1);
    char c;
    for(int i=0,a, b; i<M;++i){
        cin >>a >>b >>c;
        roads[i].A = a;
        roads[i].B = b;
        roads[i].cost_idx = c-'A';
        nodes_roads[a].push_back(i);
        nodes_roads[b].push_back(i);
    }
}

struct cmp{
    bool operator()(const int A, const int B){
        return cost[roads[A].cost_idx] > cost[roads[B].cost_idx];
    }
};

int calc(){
    // cout <<"--------------\n";
    priority_queue<int, vector<int>, cmp> pq;
    int ans=0;
    int length=N-1;
    for(int i=0; i<M; ++i) road_flag[i] = false;
    for(int i=1; i<N+1;++i) node_flag[i] = false;

    for(int i=0; i<5;++i) cin >> cost[i]; // 비용 최신화

    for(int road_idx : nodes_roads[1]) {
        pq.push(road_idx);
        road_flag[road_idx] = true;
    }
    node_flag[1] = true;

    while(length > 0){ 
        auto top_road = roads[pq.top()]; 
        int ii = pq.top();
        pq.pop();
        if(node_flag[top_road.A] && node_flag[top_road.B]) continue; // 두 지점 모두 사용됨
        // 현 간선을 사용
        length--;
        ans += cost[top_road.cost_idx];
        int idx = top_road.A*(int)(!node_flag[top_road.A]) + top_road.B*(int)(!node_flag[top_road.B]); // idx : 사용되지 않은 노드 번호
        node_flag[idx] = true;

        for(int road_idx : nodes_roads[idx]){
            if(node_flag[roads[road_idx].A] && node_flag[roads[road_idx].B] || road_flag[road_idx]) continue; // 이미 사용된 노드 or 큐에 올라간 도로
            pq.push(road_idx);
            road_flag[road_idx] = true; 
        }
    }

    return ans;
}


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    while(Q-->0){
        cout << calc()<<"\n";
    }

    return 0;
}