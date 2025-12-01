#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct road{
    int C, F, T;
    road() = default;
    road(int c, int f, int t) : C(c), F(f), T(t) {}
};

vector<pair<int,pair<int,int>>> roads;
vector<vector<int>> house;
vector<bool> visited;
vector<bool> road_used;
int N, M;
// 4차 : 유니온 파인드를 사용하여 pq를 사용하지않으면 최저 속도 가능.
// 3차 : 704ms 도로를 벡터에 넣고 미리 sort를 하고 idx 에 따른 pq 조건을 사용. pq이기에 속도가 상대적으로 느림
int init3(){
    int st=0;
    int mn=1001;
    cin >>N >> M;
    roads.resize(M);
    road_used.resize(M, false);
    visited.resize(N+1, false);
    house.resize(N+1);

    for(int i=0; i<M;++i){
        int C, F, T;
        cin >> F >> T >>C;

        roads[i] = {C,{F, T}};
    }

    sort(roads.begin(), roads.end());
    int i = 0;
    for(auto e : roads){
        // e.first : C
        // e.second : {F, T}    
        if(mn>e.first){
            mn = e.first;
            st =i; 
        }
        house[e.second.first].push_back(i);
        house[e.second.second].push_back(i);
        i++;
    }

    return st;
}

void calc3(int st){
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(st);
    road_used[st] = true;
    int ans =0;
    int mx =0;
    while(!pq.empty()){
        int top = pq.top();
        pq.pop();
        int F = roads[top].second.first;
        int T = roads[top].second.second;
        int C = roads[top].first;
        if(visited[F] && visited[T]) continue;
        if(mx < C)
            mx = C;
        ans += C;
        if(!visited[F]){
            for(int r : house[F]){
                if(road_used[r]) continue;
                pq.push(r);
                road_used[r] = true;
            }
        }
        if(!visited[T]){
            for(int r : house[T]){
                if(road_used[r]) continue;
                pq.push(r);
                road_used[r] = true;
            }
        }
        visited[F] = true;
        visited[T] = true;
    }
    cout <<ans -mx;
}

void calc4(int st){
    int ans = 0;
    int mx = 0;

    for(int r = 0; r<M; ++r){
        if(road_used[r]) continue;
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int st = init3();
    calc3(st);
    return 0;
}

/* 2차 제출. 1196ms. 최저 292*b /
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct road{
    int C = 0;
    int F = 0, T = 0;
    bool used = false;
    road() = default;
    road(int c, int f, int t){
        C = c;
        F = f;
        T = t;
    }
};

struct house{
    bool visited = false;
    vector<int> roads;
};

int N, M;
vector<house> houses;
vector<road> roads;

int init(){
    cin >> N >>M;
    roads.resize(M);
    houses.resize(N+1);
    int mn = 1001;
    int st = 0;
    for(int i=0, C, F, T; i<M;++i){
        cin >> F >> T >> C;
        roads[i] = road(C, F, T);
        if(mn > C){
            mn = C;
            st = i;
        }
    }
    sort(roads.begin(), roads.end());
    int idx=0;
    for(auto r : roads){
        cout << r.F << " "<<r.T<<" "<<r.C<<endl;
        houses[r.F].roads.push_back(idx);
        houses[r.T].roads.push_back(idx++);
    }

    return st;
}

void calc(int st){
    struct cmp{
        bool operator()(int a, int b) {
            return roads[a].C > roads[b].C;
        }
    };
    int ans=0;
    int mx=0;
    priority_queue<int, vector<int>, cmp> pq;
    pq.push(st);

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        // top은 사용할 항목
        int F = roads[top].F;
        int T = roads[top].T;
        if(houses[F].visited && houses[T].visited) continue; // 현 도로의 집들이 이미 연결됨

        ans += roads[top].C;
        if(mx<roads[top].C)
            mx = roads[top].C;

        if(!houses[F].visited){
            for(int e : houses[F].roads){
                if(roads[e].used) continue;
                roads[e].used = true;
                pq.push(e);
            }
        }
        if(!houses[T].visited){
            for(int e : houses[T].roads){
                if(roads[e].used) continue;
                roads[e].used = true;
                pq.push(e);
            }
        }
        houses[F].visited = true;
        houses[T].visited = true;
    }
    cout << ans - mx;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int st = init();
    // calc(st);


    return 0;
}

/* 1차 제출. 1640ms. 최저 292* /
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct road{
    int C = 0;
    int F, T;
    road(int c, int f, int t){
        C=c;
        F=f;
        T=t;
    }
};

int N, M;
vector<bool> v;
vector<bool> used;
vector<road> roads;
vector<vector<int>> cn;

struct idx{
    int n;
    bool operator<(idx nex)const{
        return roads[n].C > roads[nex.n].C;
    }
    idx(int i){
        n = i;
    }
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >>N >>M;
    v.resize(N+1, false);
    cn.resize(N+1);
    used.resize(M, false);
    priority_queue<idx> pq;

    int st=0;
    int mn=1001;
    for(int i=0; i<M;++i){
        int C, F, T;
        cin >> F >> T >> C;
        if(mn>C){
            mn = C;
            st = roads.size();
        }
        cn[F].push_back(roads.size());
        cn[T].push_back(roads.size());
        roads.push_back(road(C, F, T));
    }
    
    int ans = 0;
    int mx = 0;
    pq.push(idx(st));
    used[st] = true;

    while(!pq.empty()){
        auto e = pq.top().n;
        pq.pop();
        int F = roads[e].F;
        int T = roads[e].T;
        if(v[F]&&v[T]) continue;
        if(roads[e].C > mx)
            mx = roads[e].C;
        ans += roads[e].C;
        v[F] = true;
        v[T] = true;

        for(auto r : cn[F]){
            if(v[roads[r].F] && v[roads[r].T]) continue;
            pq.push(r);
        }
        for(auto r : cn[T]){
            if(v[roads[r].F] && v[roads[r].T]) continue;
            pq.push(r);
        }
    } 
    cout << ans - mx;
    return 0;
}

/* */