#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >>N;
    vector<int> arr;

    for(int i=0, temp; i<N;++i){
        cin >>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    int right_idx=arr.size()-1, left_idx=0;

    int gap = 2000000000;
    int ans_l, ans_r;
    while(left_idx < right_idx){
        int temp_gap = abs(arr[right_idx] + arr[left_idx]);
        if(temp_gap < gap){
            gap = temp_gap;
            ans_l = left_idx;
            ans_r = right_idx;
            if(gap == 0) break;
        }
        if(abs(arr[left_idx]) < abs(arr[right_idx])){
            right_idx--;
        }else
            left_idx++;
    }

    cout <<arr[ans_l]<<" "<< arr[ans_r];

    return 0;
}