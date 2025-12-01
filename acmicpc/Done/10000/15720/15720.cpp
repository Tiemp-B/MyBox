#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int B, C, D;
    cin >> B >>C >>D;

    int mn = min({B, C, D});
    int ans0 =0;
    int ans =0;

    vector<int> BB(B), CC(C), DD(D);

    for(int i=0; i<B;i++) {
        cin >>BB[i];
        ans0 += BB[i];
    }
    for(int i=0; i<C;i++) {
        cin >>CC[i];
        ans0 += CC[i];
    }
    for(int i=0; i<D;i++) {
        cin >>DD[i];
        ans0 += DD[i];
    }

    sort(BB.begin(), BB.end());
    sort(CC.begin(), CC.end());
    sort(DD.begin(), DD.end());

    while(!BB.empty() && !CC.empty() && !DD.empty()){
        ans += BB.back()*0.9; BB.pop_back();
        ans += CC.back()*0.9; CC.pop_back();
        ans += DD.back()*0.9; DD.pop_back();
    }    

    while(!BB.empty()){
        ans += BB.back(); BB.pop_back();
    }
    while(!CC.empty()){
        ans += CC.back(); CC.pop_back();
    }
    while(!DD.empty()){
        ans += DD.back(); DD.pop_back();
    }
    
    cout <<ans0<<endl<<ans;

    return 0;
}

