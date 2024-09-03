#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
/*--소프티어 출제--*/
int main(){
    int N;
    cin >>N;
    vector<int> S(N), L(N);
    int mx =0;
    for(int i=0; i<N; i++) {
        cin >>S[i];
        if(mx<S[i]) mx=S[i];
    }

    cout<<N-1+mx;

    return 0;
}

