#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n';
using namespace std;

long long d = 1000000007;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int TC, N;
    long long ans, value, temp, e1, e2;
    cin >>TC;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    while(TC-->0){
        cin >>N;
        while(N-->0){
            cin >>temp;
            pq.push(temp);
        }
        ans = 1;
        while(pq.size()!=1){
            e1 = pq.top(); pq.pop();
            e2 = pq.top(); pq.pop();
            pq.push(e1*e2);
            ans *= (e1*e2)%d;
            ans %=d;
        }
        pq.pop();
        cout << ans%d<<endl;
    }
    return 0;
}