#include <iostream>
#include <vector>
using namespace std;


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >>N;
    vector<int> bx(N);
    vector<int> mx(N);

    for(auto &e : bx) cin >>e;

    mx[N-1] = bx[N-1];
    int mxx = mx[N-1];
    for(int i=N-2; i>=0; --i){
        if(bx[i]>=mxx){
            mx[i] = bx[i];
            mxx = bx[i];
        }else{
            mx[i] = mxx;
        }
    }

    int ans =0;

    for(int i=0; i<N-1;++i){
        ans += mx[i]-bx[i];
    }

    cout <<ans;

    return 0;
}