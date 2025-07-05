#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v={1};
vector<int> c={1};

void cases(){
    int N;
    cin >>N;
    v.clear();
    v.resize(N+1, 0);
    c.clear();
    c.resize(N+1, 0);
    
    for(int i=1;i<=N;++i) {
        cin >> v[i];
        c[v[i]]++;
    }
    
    int ans = 0;

    queue<int> q;
    for(int i=1;i<N+1;++i){
        if(c[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int t = q.front();
        q.pop();
        ans++;
        c[v[t]]--;
        if(c[v[t]]== 0){
            q.push(v[t]);
        }
    }
    cout <<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >>T;
    for(int i=0;i<T;++i) cases();

    return 0;
}