#include <iostream>
#include <vector>
using namespace std;

vector<string> v={"1", "1", "3", "5"};

string ladd(string a, string b){
    string ret((a.size()>b.size())? (a.size()+2):(b.size()+2),'\0');
    int i, j, k;
    for(i=a.size()-1, j=b.size()-1, k=ret.size()-1; i>=0||j>=0 ; --i,--j,--k){
        if(i<0)
            ret[k]+=b[j];
        else if(j<0)
            ret[k]+=a[i];
        else
            ret[k] += a[i]+b[j]-'0';
        
        if(ret[k]>'9'){
            ret[k-1]++;
            ret[k] -=10;
        }else if(ret[k]<'0'){
            ret[k-1]--;
            ret[k] += 10;
        }
    }
    ret[k] +='0';

    for(i=0; i<ret.size()&&(ret[i]==0||ret[i]=='0'); ++i);
    if(i>0)
        ret = ret.substr(i);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    while(cin>>t&&!cin.eof()){

        if(v.size()<t+1){
            for(int tt=v.size();tt<=t;++tt){
                string a = v[tt-2];
                a = ladd(a, a);
                a = ladd(a, v[tt-1]);
                v.push_back(a);
            }
        }
        cout << v[t]<<"\n";
    }

    return 0;
}