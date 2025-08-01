#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> v;
string sen;
void calc(){
    if(v.size()==1) return;
    for(int i=1; i<=v.size();++i)
        v[i-1]=(v[i]-v[i-1]);
    v.pop_back();
}
int main(){
    // cin.tie(nullptr)->sync_with_stdio(false);
    int N, K; cin >>N>>K;
     cin>>sen;
    while(sen.size()>0){
        int l =0;
        for(;sen[l]!=','&&sen.size()!=l;++l);
        int num=0;
        int neg=1;
        for(int i=0;i<l;++i){
            if(sen[i]=='-'){
                neg = -1;
                continue;
            }
            num = num*10+(sen[i]-'0');
        }
        v.push_back(num*neg);
        if(l==sen.size()) break;
        sen = sen.substr(l+1);
    }
    while(K-->0) calc();
    for(int i=0;i<v.size();++i){
        cout <<v[i];
        if(i!=v.size()-1) cout <<",";
    }
    return 0;
}