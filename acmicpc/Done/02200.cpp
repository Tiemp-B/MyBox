#include <iostream>
#include <deque>

using namespace std;

int main(){
    int N;
    cin >> N;

    long long int ans = 0;
    string temp;
    cin >> temp;
    if (temp.size()>2){
        ans += temp.size() +1;
    }else if(temp[0] == '1'){
        ans += 1;
    }else{
        ans += 3;
    }

    for(int i=N-1; i>=0;i--){
        cin >> temp;
        if (temp.size() >1){
            ans += temp.size()+1; // 계수 추가

        }else if(temp[0] == '0'){
        }else{
            ans += 2;
        }
    }

    cout <<ans + (N-1)*2 + 1;
    

    return 0;
}