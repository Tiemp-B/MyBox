#include <iostream>

using namespace std;

int main(){
    long long int N;
    cin >> N;
    //N개의 교실, N/2개의 반, 반에 홀수학생 짝수 학생이 서로 다른 교실에 자습.
    //N>=2 
    long long int ans[31];
    ans[2] = 1;

    for(int i=3; i<=N;++i){
        if(i%2==0)
            ans[i] = ans[i-1];
        else
            ans[i] = ans[i-1]*i;
    }
    cout <<ans[N];
    
    return 0;
}