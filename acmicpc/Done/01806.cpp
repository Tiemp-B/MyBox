#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N, S;
    cin >>N >>S;
    vector<int> arr = {0};
    vector<int> sums={0};
    for(int i=1, temp; i<=N;++i){
        cin >> temp;
        arr.push_back(temp);
        sums.push_back(sums[i-1] + temp);
    }

    if(sums.back() < S) {
        cout <<0;
        return 0;
    }
    else if(sums.back() == S) {
        cout <<N;
        return 0;
    }
    
    int l = 1, r=1;
    int tot = arr[1];
    int ans = 100001;
    while(l<=N){
        printf("%d %d tot : %d\n", l, r, tot);
        if(tot >= S){
            if(ans > r-l+1){
                ans = r-l+1;
                if(ans == 1) break;
            }
            tot -= arr[l++];
        }else{
            if(r == N) break;
            tot += arr[++r];
        }
    }

    if(ans == 100001)
        cout << 0;
    else
        cout << ans;
    
    return 0;
}