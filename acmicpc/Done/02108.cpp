#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> mp;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N;
    cin >>N;
    double tot =0;
    int cnt = 0, mx= -4001, mn=4001;
    vector<int> v_cnt;
    vector<int> v;
    for(int i=0, inp; i<N;++i){
        cin >>inp;
        tot += inp;

        if(mx<inp)
            mx = inp;
        if(mn>inp)
            mn = inp;

        v.push_back(inp);

        mp[inp]++;
        if(mp[inp]>cnt){
            v_cnt.clear();
            v_cnt.push_back(inp);
            cnt = mp[inp];
        }else if(mp[inp] == cnt){
            v_cnt.push_back(inp);
        }
    }
    sort(v.begin(), v.end());
    sort(v_cnt.begin(), v_cnt.end());
    tot /= N;
    bool neg = tot<0;
    if(neg) tot *= -1;
    if((int)((tot - (int)tot)*10)>4 ) tot = int(tot) + 1;
    else tot = int(tot);
    if(neg) tot *= -1;

    cout << (int)tot<<endl;
    cout <<v[(N/2)]<<endl;
    if(v_cnt.size()>1) cout <<v_cnt[1];
    else cout <<v_cnt[0];
    cout <<endl<<mx-mn;

    return 0;
}