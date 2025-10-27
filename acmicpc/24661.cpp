#include <iostream>
#include <vector>

using namespace std;

struct node{
    long long int P=0;
    long long int A=0;
    long long int C=0;
    bool avail=true;
    long long int tot_C=0;
    long long int tot_A=0;
    vector<int> child;
};

int N, Q;
vector<node> arr;

void init_recur(int idx){// 가능여부, totA, totC
    for(auto e: arr[idx].child){
        init_recur(e);
        arr[idx].avail &= arr[e].avail;
        arr[idx].tot_A += arr[e].tot_A;
        arr[idx].tot_C += arr[e].tot_C;
    }
    arr[idx].avail &= (arr[idx].tot_A >= arr[idx].tot_C);
}

void init(){
    cin >>N;
    arr.resize(N+1);

    for(int i=2;i<=N;++i) {
        cin >>arr[i].P;
        arr[arr[i].P].child.push_back(i);
    }
    for(int i=1;i<=N;++i) {
        cin >>arr[i].A;
        arr[i].tot_A = arr[i].A;
    }
    for(int i=1;i<=N;++i) {
        cin >>arr[i].C;
        arr[i].tot_C = arr[i].C;
    }

    init_recur(1);
    if(arr[1].avail) cout <<"Yes\n";
    else cout <<"No\n";

}

int mode, ix, val;

bool update(int idx){
    switch(mode){
    case 1:
        arr[idx].tot_A -= arr[idx].A;
        arr[idx].tot_A += val;
        break;
    case 2:
        arr[idx].tot_C -= arr[idx].C;
        arr[idx].tot_C += val;
        break;
    }

    arr[idx].avail = (arr[idx].tot_A >= arr[idx].tot_C);
    
    for(auto c : arr[idx].child){
        arr[idx].avail &= arr[c].avail;
    }

    if(!arr[idx].avail) return false;
    
    if(arr[idx].P == 0) arr[idx].avail;
    update(arr[idx].P);
}

void query(){
    cin >>Q;
    for(int j=0; j<Q;++j){
        cin >>mode >>ix >>val;//mode, index, value;
        bool ans = update(ix);
        switch (mode)
        {
        case 1:
            arr[ix].A = val;
            break;
        case 2:
            arr[ix].C = val;
            break;
        }
        
        if(ans) cout <<"Yes\n";
        else cout <<"No\n";
    }
}


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    query();
    return 0;
}


/*
30
1 1 2 2 2 3 3 3 4 4 4 5 5 6 6 7 7 8 8 9 9 10 10 11 11 12 12 13 13
3 2 4 2 3 1 2 2 3 1 2 2 1 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
3 2 3 2 3 1 2 2 3 1 2 2 1 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
10
1 1 2
2 2 3
1 5 4
2 1 2
1 3 5
2 3 2
1 1 4
2 4 3
1 11 2
2 5 4

*/