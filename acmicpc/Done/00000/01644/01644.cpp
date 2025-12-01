#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> num;
vector<int> p;

void prime(){
    for(int i=2; i<=N;++i){
        if(!num[i]) continue;
        p.push_back(i);
        int t = i+i;
        while(t<=N){
            num[t] = false;
            t += i;
        }
    }
}

void init(){
    cin >> N;
    num.resize(N+1, true);
    prime();
}

void calc(){
    if(N==1){
        cout << 0;
        return;
    }
    int s=0, t=0;
    int interval = p[0];
    int ans=0;
    while(true){
        if(interval == N){
            ans++;
            if(t+1 == p.size()) break;
            interval += p[++t];
        }else if(interval > N){
            interval -= p[s++];
        }else{ // if(interval <N){
            if(t+1 == p.size()) break;
            interval += p[++t];
        }
    }
    cout <<ans;
}

int main(){
    init();
    calc();
    return 0;
}