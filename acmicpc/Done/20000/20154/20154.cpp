#include <iostream>
#include <queue>
using namespace std;

int dict[]={3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};

queue<int> calc(queue<int> q){
    queue<int> ret;
    while(q.size()!=1&&q.size()!=0){
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();
        a += b;
        a %= 10;
        ret.push(a);
    }
    if(q.size()==1)
        ret.push(q.front());
    return ret;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    queue<int> q;
    for(char c : str) q.push(dict[c-'A']);
    
    while(q.size()!=1){
        q = calc(q);
    }
    int res = q.front();
    
    if(res%2==0)
       cout << "You're the winner?";
    else
        cout << "I'm a winner!";
    return 0;
}