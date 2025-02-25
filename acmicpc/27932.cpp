#include <iostream>
#include <vector>

using namespace std;


void binSearch(int n, int k){
    vector<int> tall(n, 0);
    int left = 0, right=0;
    for(int i=0; i<n ;i++){
        cin >> tall[i];
        if(right < tall[i])
            right = tall[i];
    }
    int ans = 2147483647;

    while(left <= right){ // O(logN)
        int now = (left + right)/2;
        vector<bool> tired(n, false);
        int cnt = 0;
        for(int i=0; i<n-1; i++){ // O(N)
            if(abs(tall[i+1]-tall[i]) > now){
                tired[i+1] = true;
                tired[i] = true;
            }
            if(tired[i])
                cnt++;
        }
        if(tired[n-1])
            cnt++;

        if(cnt <= k){
            if(ans > now)
                ans = now;
            right = now-1;
        }else
            left = now+1;
    }

    cout << ans;
}


void binSearch2(int n, int k){
    
}

int main(){
    int n, k;
    cin >> n >>k;

    binSearch(n,k);

    return 0;
}