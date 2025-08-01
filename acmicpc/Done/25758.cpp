#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >>N;
    map<char, map<char,int>> head, tail;
    set<char> st;
    for(int i=0; i<N;++i){
        string temp;
        cin >>temp;
        head[temp[0]][temp[1]]++;
        tail[temp[1]][temp[0]]++;
    }
    bool ans[26]={};
    int cnt=0;
    for(auto h : head){
        for(auto t : tail){
            bool flag =false;
            flag |= h.second.size()>1 || t.second.size()>1 ;
            flag |= h.second.find(t.first) == h.second.end();
            flag |= h.second[t.first]>1;

            if(!flag ) continue;
            if(h.first<=t.first){
                if(!ans[t.first-'A']) cnt++;
                ans[t.first-'A'] = true;
            }
            else{
                if(!ans[h.first-'A']) cnt++;
                ans[h.first-'A'] = true;
            }
        }
    }
    cout <<cnt<<"\n";
    for(int i=0; i<26;++i){
        if(ans[i]) cout << (char)(i+'A')<<" ";
    }
    return 0;
}