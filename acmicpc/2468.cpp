#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> arr;
    int first_plus=-1;
    bool all_minus= true;
    bool all_plus= true;
    for(int i=0,temp; i<N;++i){
        cin >>temp;
        arr.push_back(temp);
        if(temp<0)
            all_plus = false;
        else if(temp > 0){
            all_minus = false;
            if(first_plus<0)
                first_plus = i;
        }
        
    }

    // 가장 유사한 페어
    int gap = 2000000000;
    int ans1, ans2;
    if(all_plus)
        cout << arr[0] <<" "<<arr[1];
    else if(all_minus)
        cout << arr.back() <<" "<< arr[N-2];
    else{
        for(int m = 0; m<first_plus; ++m){
            int ub= N-1, lb= first_plus;
            
            while( lb<= ub){
                int mid = (lb+ub)/2;
                
                if(abs(arr[m]+arr[mid]) < gap){
                    
                }

            }
            

        }
    }


    return 0;
}