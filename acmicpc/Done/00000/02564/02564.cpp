#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int w, h;
    cin >> w >> h;
    int n, ans=0;
    cin >> n;

    pair<int,int> market[101];
    int clock_path[100];
    int anti_clock_path[100];

    for(int i=0,s, l; i<=n;i++){
        cin>> s >> l;
        switch(s){
            case 1:
                clock_path[i] = h + l;
                anti_clock_path[i] = w + h + w-l;
                break;
            case 2:
                clock_path[i] = 2*h + w + w-l;
                anti_clock_path[i] = l;
                break;
            case 3:
                clock_path[i] = h-l;
                anti_clock_path[i] = 2*w + h + l;
                break;
            case 4:
                clock_path[i] = w + h + l;
                anti_clock_path[i] = w + h-l;
                break;
        }
    }

    for(int i=0;i<n;i++){
        int A_idx, B_idx;
        if(clock_path[i] < clock_path[n]){
            A_idx = i;
            B_idx = n;
        }else{
            A_idx = n;
            B_idx = i;
        }
        vector<int> li = {
            clock_path[B_idx] - clock_path[A_idx],
            clock_path[A_idx] + anti_clock_path[B_idx],
            anti_clock_path[A_idx] - anti_clock_path[B_idx],
            anti_clock_path[A_idx] + clock_path[B_idx] - 2*w-2*h
        };

        ans += *min_element(li.begin(), li.end());

    }

    cout << ans;

    return 0;
}