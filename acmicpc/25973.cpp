#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class MyTree{
    struct node{
        int parent=0;
        int s=0;
        int tin=0, tout=0;
        int depth=0;
        unordered_map<int, int> cc;// connection-count
    };
public:
    MyTree(int n){
        // 생성
        N = n;
        v.resize(N+1);
        selfLCA.resize(N+1);
        up.resize(19,vector<int>(N+1, 0));
    }
    void insert(int a, int b){ 
        // 노드 추가
        v[a].cc.insert({b, 0});
        v[b].cc.insert({a, 0});
    }

    void init(){
        // 초기화
        recur(0, 1); // O(N)
        for(int i=1; i<=N;++i){ // O(N)
            if(v[i].cc.find(v[i].parent)==v[i].cc.end()) continue;
            v[i].cc[v[i].parent] = N-1-v[i].s;
        }
        for (int i = 1; i <= N; ++i) { // O(N)
            long long total = 0, sq_sum = 0;
            for (auto &e : v[i].cc) {
                long long sz = e.second;
                total += sz;
                sq_sum += 1LL * sz * sz;
            }
            long long s = (total * total - sq_sum) / 2;
            selfLCA[i] = (N - 1) + s;
        }
    }

    long long find(int x){
        // 새 방법
        if(x == root) return selfLCA[x];
        int nex = next_on_path(x, root);
        if (is_ancestor(nex, root)) {
            long long sub = v[x].cc[nex];
            return selfLCA[x] - sub * (N - sub);
        } else {
            return selfLCA[x];
        }
    }

    void chage_root(int r){
        root = r;
    }

private:
    vector<node> v;
    vector<long long> selfLCA;
    int timer=0;
    long long N;
    int root=1;
    vector<vector<int>> up;

    int recur(int from, int idx){// idx 하위를 호출
        v[idx].tin = ++timer;
        v[idx].parent = from;
        up[0][idx] = from;
        for(int k=1; k<19;++k){
            up[k][idx] = up[k-1][idx] ? up[k-1][up[k-1][idx]]: 0;
        }
        for(auto &e : v[idx].cc){ 
            if(e.first == v[idx].parent) continue;
            v[idx].depth = v[from].depth+1;
            e.second = recur(idx, e.first);
            v[idx].s += e.second;
        }
        v[idx].tout = ++timer;
        return v[idx].s+1;
    }

    void parent_update(int from, int idx){
        v[idx].parent = from;
        if(v[idx].cc.size()==1) return;
        for(auto &e : v[idx].cc){
            if(e.first == v[idx].parent) continue;
            parent_update(idx, e.first);
        }
    }

    bool is_ancestor(int A, int B){
        return v[A].tin <= v[B].tin && v[B].tout <= v[A].tout;
    }

    int jump(int idx, int k){
        for(int i=0; i<19; ++i)
            if(k & (1<<i)) idx = up[i][idx];
        return idx;
    }

    int next_on_path(int A, int B){
        if(is_ancestor(A, B)){
            int dist = v[B].depth - v[A].depth -1;
            return jump(B, dist);
        }else{
            return up[0][A];
        }
    }
};


void init(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, Q, a, b, q, x;
    cin >>N >>Q;
    MyTree t(N--);
    while(N-->0){
        cin >>a >>b;
        t.insert(a, b);
    }
    t.init();
    while(Q-- > 0){
        cin >> q>> x;
        if(q == 1)
            t.chage_root(x);
        else
            cout << t.find(x)<<"\n";
    }
}


int main(){
    init();
    return 0;
}


/*
6 11
1 2
2 3
1 4
5 2
4 6
2 2
2 1
2 4
1 4
2 1
2 3
2 4
2 6
2 1
2 2
2 5

ans:
3
11
1
3
0
9
0
3
3
0


*/