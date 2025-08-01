#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting{
    int st=0;
    int ed=0;
    int hu=0;
    meeting() = default;
    meeting(int s, int e, int h){
        st = s;
        ed = e;
        hu = h;
    }
};

vector<meeting> v;
int ans = 0;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >>N;
    int s, e, h;
    vector<vector<int>> sc(N, vector<int>(2,0));
    for(int i=0; i<N;++i){
        cin >> s >> e >> h;
        v.push_back(meeting(s, e, h));
    }
    if(N==1){
        cout << v[0].hu;
        return 0;
    }
    sc[0][0] = 0;
    sc[0][1] = v[0].hu;
    sc[1][0] = sc[0][1];
    sc[1][1] = v[1].hu;
    for(int i=2;i<N;++i){
        sc[i][0] = max(max(sc[i-1][1], sc[i-1][0]), max(sc[i-2][0], sc[i-2][1]));
        sc[i][1] = max(sc[i-1][0], max(sc[i-2][0], sc[i-2][1])) + v[i].hu;
    }
    cout <<max(sc[N-1][0], sc[N-1][1]);

    return 0;
}