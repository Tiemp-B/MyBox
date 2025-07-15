#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int num;
    int dic=0;
    bool fortune=true;
    node(int n, int d, bool b){
        num = n;
        dic = d;
        fortune = b;
    }
};

vector<bool> defa(10, false);
vector<bool> use_name(5001, false);
queue<node> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<10;++i)
        q.push(node(i, 1<<i, true));
    
    while(!q.empty()){
        auto e = q.front(); q.pop();
        use_name[e.num] = e.fortune; 
        if(e.num==0) continue;
        for(int i=0;i<10;++i){
            int nex = e.num*10 + i;
            if(nex>5000) continue;
            bool flag = ((1 << i)&(e.dic))!=0;// 둘 다 1이면 중복수, flag가 true
            q.push(node(nex, (1<<i)|e.dic, (!flag) && e.fortune)); // e.fortune가 트루고 flag는 false여야 함
        }
    }
    
    int N, M;
    while(cin >>N>>M){
        int ans = 0;
        for(int s=N; s<=M;++s){
            if(use_name[s])
                ans++;
        }
        cout <<ans<<endl;
    }
    return 0;
}