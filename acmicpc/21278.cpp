#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, M;// N: 건물(<=100), M: 도로
    // 건물 2개 지정. 작은 번호가 더 작을 수록, 작은번호가 동일하다면 큰 번호가 작을 수록

    cin >>N >>M;
    vector<int> A(N+1), B(N+1);

    for(int i=1; i<=N;++i){
        cin >>A[i] >>B[i];
    }
    int ans = 2147483647;
    
    for(int p1=1; p1<=N-1; ++p1){
        for(int p2=p1+1; p2<=N; ++p2){
            queue<int> q;
            q.push(p1);
            q.push(p2);
        }
    }
    


    return 0;
}