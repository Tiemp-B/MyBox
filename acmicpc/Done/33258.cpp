#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, E;
    cin >>N >> E;
    
    vector<int> w(N);

    for(int &i : w) cin >> i;

    sort(w.begin(), w.end());

    int prev = -102020, cnt =0;
    for(int e : w){
        if(e-prev >= E)
            cnt++;
        prev = e;
    }

    cout << cnt;
    return 0;
}