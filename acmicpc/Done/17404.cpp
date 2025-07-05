#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int N;
vector<vector<int>> arr;
vector<vector<vector<vector<int>>>> DP;
unordered_set<int> st;

void init(){
    int a = st.max_size();
    cin >>N;
    arr.resize(N+1, vector<int>(3));
    DP.resize(3, vector<vector<vector<int>>>(3, vector<vector<int>>(N+1, vector<int>(3, 100000000))));
    for(int i=1; i<=N;++i){
        cin >> arr[i][0] >>arr[i][1] >> arr[i][2];
    }
}
//DP[시작색][끝색][집번호][집색]
void dping(int st, int ed){
    for(int c=0; c<3;++c){
        if(c != st){
            DP[st][ed][1][c] = 100000000;
        }else{
            DP[st][ed][1][c] = arr[1][c] + arr[N][ed];
        }
    }
    for(int i=2; i<N;++i){
        for(int c=0; c<3;++c){
            int e=10000;
            switch(c){
                case 0:
                    e = min(DP[st][ed][i-1][1], DP[st][ed][i-1][2]);
                    break;
                case 1:
                    e = min(DP[st][ed][i-1][0], DP[st][ed][i-1][2]);
                    break;
                case 2:
                    e = min(DP[st][ed][i-1][0], DP[st][ed][i-1][1]);
                    break;
            }
            DP[st][ed][i][c] = e + arr[i][c];
        }
    }

}

void calc(){
    int ans =1000000000;
    for(int stc=0; stc<3;++stc){
        for(int edc=0; edc<3;++edc){
            if(stc==edc) continue;
            dping(stc, edc);
            for(int lc=0; lc<3;++lc){
                if(edc == lc) continue;
                if(ans> DP[stc][edc][N-1][lc]) ans = DP[stc][edc][N-1][lc];
            }
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    init();
    calc();
    return 0;
}