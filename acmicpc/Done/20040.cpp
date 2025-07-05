#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int find(int idx){
    if(v[idx] == idx) return v[idx];
    return v[idx] =find(v[idx]);
};

void update(int idx, int value){
    // cout <<"   - "<< idx<<" "<<value<<endl;
    if(v[idx]==idx) {
        v[idx] = value;
        return;
    }
    update(v[idx], value);
    v[idx] = value;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, m;
    cin >>n >> m;
    v.resize(n);
    for(int i=0; i<n;++i) v[i] = i;

    for(int t=1,a ,b; t<=m;++t){
        cin >> a>>b;
        int aa = find(a);
        int bb = find(b);
        if(aa == bb){
            cout << t;
            return 0;
        }
        else if(aa>bb){
            update(aa, bb);
        }else{
            update(bb, aa);
        }
    }
    cout << 0;
    return 0;
}