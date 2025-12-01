#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int N;
    cin >> N;
    unordered_map<int, int> mp;
    int ans = 0;
    for(int i=0, temp; i<N; i++){
        cin >> temp;
        mp[temp]++;
        if(mp[temp] > ans)
            ans = mp[temp];
    }

    cout << ans;

    return 0;
}