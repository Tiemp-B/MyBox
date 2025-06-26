#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back

struct Edge {
    int a, b, c;

    bool operator<(const Edge& o) {
        return c < o.c;
    }
};

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

bool uni(int a, int b) {
    int ap = find(a), bp = find(b);
    if (ap == bp) return false;
    parent[bp] = ap;
    return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> G(N+1);
    vector<Edge> edges(M);
    parent.resize(N+1);
    for (int i = 1; i <= N; i++) parent[i] = i;

    for (Edge& e: edges) cin >> e.a >> e.b >> e.c;

    sort(edges.begin(), edges.end());

    for(auto e : edges) {
        cout <<e.a <<" "<<e.b<<" "<< e.c<<endl;
    }

    int cnt = 0, res = 0, idx = 0;
    while (cnt < N-2) {
        Edge e = edges[idx++];
        if (uni(e.a, e.b)) {
            cnt++; 
            res += e.c;
        }
    }
    cout << res;
}