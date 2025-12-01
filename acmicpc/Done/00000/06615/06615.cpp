#include <iostream>
#include <deque>
#include <unordered_map>
using namespace std;

unordered_map<long long, deque<long long>> mp;

void processing(long long num){
    if(mp.find(num)!=mp.end()) return;
    long long t=num;
    while(t!=1){
        mp[num].push_front(t);
        if(t%2==0) t/=2;
        else t= t*3+1;
    }
    mp[num].push_front(1);
}

void calc(long long a, long long b){
    processing(a);
    processing(b);
    int same_point=0;
    for(;mp[a][same_point]==mp[b][same_point]&&same_point!=mp[a].size()&&same_point!=mp[b].size();++same_point);
    cout <<a<<" needs "<< mp[a].size()-same_point<<" steps, "
        <<b<<" needs "<< mp[b].size()-same_point<<" steps, they meet at "<<mp[a][same_point-1]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, b;
    while(cin>>a>>b&&a!=0&&b!=0){
        calc(a, b);
    }
    
    return 0;
}