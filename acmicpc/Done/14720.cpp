#include <iostream>

using namespace std;

int main(){
    int ans = 0, N;
    cin >> N;
    int now = 0;
    for(int i=0, temp; i<N; i++){
        cin >> temp;
        if(now == temp){
            ans++;
            now++;
            if(now >2) now = 0;
        }
    }

    cout <<ans;

    return 0;
}