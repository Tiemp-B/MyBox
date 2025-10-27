#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int i, j;
    int k;
    int need;
    bool flag=false; // 만족
};

int N, M, K, Q;
vector<int> machine;
vector<int> growing_child;
vector<int> ans;
vector<int> height;
vector<node> query;
vector<vector<int>> wishlist;
vector<int> rights;

bool cmp(const int& a, const int& b){
    if(query[a].flag != query[b].flag) return !query[a].flag && query[b].flag;
    int ra = query[a].need - height[query[a].i] - height[query[a].j];
    int rb = query[b].need - height[query[b].i] - height[query[b].j];
    if(ra != rb) return ra > rb;
    return a < b;
}

void init(){
    cin >>N >>M >>K >>Q;
    machine.resize(M+1);
    growing_child.resize(K+1);
    height.resize(N+1, 0);
    ans.resize(K+1, 0);
    query.resize(Q);
    wishlist.resize(N+1);
    rights.resize(N+1, -1);
    for(int i=1; i<=M; ++i) cin >> machine[i];
    for(int i=1; i<=K; ++i) cin >> growing_child[i];
    for(int q=0,i,j,k; q<Q;++q){ // i, j: 아이 번호, k: 매일 타려는 기구
        cin >>query[q].i >>query[q].j >>query[q].k;
        query[q].need = machine[query[q].k];
        wishlist[query[q].i].push_back(q);
        wishlist[query[q].j].push_back(q);
    }

    for(int i=1; i<=N;++i){// Q log Q
        sort(wishlist[i].begin(), wishlist[i].end(), cmp);
        rights[i] = wishlist[i].size()-1;
    }

}

void calc(){
    int avail = 0;
    for(int i=1; i<=K; ++i){
        if(i<=2)
            height[growing_child[i]]++;
        else{
            if(ans[i-1]>ans[i-2]) height[growing_child[i]]+=2;
            else height[growing_child[i]]++;
        }
        // 키가 자란 아이의 탈것 리스트(q) 정렬. query.flag가 true면 후위로, 필요 값이 작을수록 후위
        sort(wishlist[growing_child[i]].begin(), wishlist[growing_child[i]].end(), cmp);

        if(!wishlist[growing_child[i]].empty()){
            int l=0, r=rights[growing_child[i]], m;
            int f=-1;
            while(l<=r){
                m = (l+r)/2;
                int q = wishlist[growing_child[i]][m];
                if(height[query[q].i] + height[query[q].j] >= query[q].need){
                    f = m;
                    r = m-1;
                }else{
                    l = m+1;
                }
            }
            if(f != -1){
                for(int t=wishlist[growing_child[i]].size()-1; t >= f; --t){
                    if(!query[wishlist[growing_child[i]][t]].flag) query[wishlist[growing_child[i]][t]].flag = true;
                    avail++;
                }
                rights[growing_child[i]] = f-1;
            }
        }

        ans[i] = avail;
    }
    for(int i=1;i<=K;++i){
        cout <<ans[i]<<"\n";
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    calc();

    return 0;
}

/*
3 2 10 3
10 7
1 2 1 2 1 2 1 2 1 2
1 2 1
1 3 2
2 3 2
*/