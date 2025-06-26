#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int parent;
    int cnt = 1;
    vector<int> child;
};

vector<node> v;
int Q, R, N;

int calc(int n){
    for(int e : v[n].child){
        if(e == v[n].parent) continue;
        v[n].cnt += calc(e);
    }
    return v[n].cnt;
}

void setParent(int p, int n){
    v[n].parent = p;
    for(int e : v[n].child){
        if(e == v[n].parent) continue;
        if(v[e].parent!=0) continue;
        setParent(n, e);
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >>N >>R >>Q;
    v.resize(N+1);
    queue<pair<int, int>> q;
    
    for(int i=0; i<N-1; ++i){
        int U, V;
        cin >> U >>V;
        
        if(v[U].parent!=0){
            v[U].child.push_back(V);
            setParent(U, V);
        }else if(v[V].parent!=0){
            v[V].child.push_back(U);
            setParent(V, U);
        }else if(U==R){
            v[U].child.push_back(V);
            setParent(U, V);
        }else if(V==R){
            v[V].child.push_back(U);
            setParent(V, U);
        }else{
            v[U].child.push_back(V);
            v[V].child.push_back(U);
        }
    }

    calc(R);

    for(int i=0; i<Q;++i){
        int U;
        cin >> U;
        cout <<v[U].cnt<<"\n";
    }


    return 0;
}