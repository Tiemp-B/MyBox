#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> trees(n);
    for(auto &e : trees) cin >> e;
    sort(trees.begin(), trees.end(), greater<int>());
    int ans = 0;
    for(int i=0; i<n; ++i){
        int r = trees[i]+2+i;
        if(ans < r)
            ans = r;
    }
    
    cout <<ans;
    return 0;
}
