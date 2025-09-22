#include <iostream>
#include <deque>
using namespace std;

deque<int> A;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, L;
    cin >>N >> L;
    A.resize(N);
    deque<int>  D(N), dq;
    for(auto &e : A) cin >>e;
    
    for(int i=0, t; i<N;++i){
        if(i>=L){
            if(dq.front() == A[i-L])
                dq.pop_front();
        }
        if(dq.empty()){
            dq.push_back(A[i]);
        }
        else{
            while(dq.back() > A[i]){
                dq.pop_back();
                if(dq.empty()) break;
            }
            dq.push_back(A[i]);
        }
        D[i] = dq[0];
    }

    for(auto e : D){
        cout <<e <<" ";
    }

    return 0;
}