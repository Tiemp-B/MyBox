#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, K;
    cin >>N >>K;
    queue<int>q;
    for(int i=2; i<=N;++i)
        q.push(i);
    int ans = 0;
    
    while(K!=0){
        int front = q.front(); q.pop(); --K;
        ans = front;
        int s = q.size();
        for(int i=0; i<s&&K!=0; ++i){
            int t = q.front(); q.pop();
            if(t%front==0){
                --K;
                ans =t;
                continue;
            }
            q.push(t);
        }
    }
    cout << ans;


    return 0;
}
