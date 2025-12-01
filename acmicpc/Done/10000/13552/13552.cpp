#include <iostream>
#include <vector>
using namespace std;

struct point{
    long long x=0;
    long long y=0;
    long long z=0;
    point() = default;
    point(long long xx, long long yy, long long zz) : x(xx), y(yy), z(zz) {}
};

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >>N;
    vector<point> v(N);
    for(auto &e : v) cin >>e.x >>e.y>>e.z;
    cin >>M;
    while(M-->0){
        long long x, y, z, r;
        cin >> x>> y>> z>> r;
        int ans = 0;
        for(auto &e: v){
            if((x-e.x)*(x-e.x) +(y-e.y)*(y-e.y)+(z-e.z)*(z-e.z) > r*r) continue;
            ans++;
        }
        cout << ans<<"\n";
    }
    return 0;
}