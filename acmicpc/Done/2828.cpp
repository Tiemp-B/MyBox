#include <iostream>

using namespace std;

int main(){
    int N, M,J, left, right;
    cin >>N >>M >>J;
    left = 1;
    right = M;
    int ans= 0;
    for(int i=0,temp=0; i<J; i++){
        cin >> temp;
        int gap;
        if(left> temp){
            gap = temp - left;
            ans += abs(gap);
        }else if (right <temp){
            gap = temp - right;
            ans += gap;
        }else{
            gap  =0;
        }
        left += gap;
        right += gap;
    }

    cout << ans;

    return 0;
}