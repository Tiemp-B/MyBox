#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mp;
int n, m;

/*
점화식
if (map[i][j] == 1)
    f(i, j) = min(f(i-1,j-1), f(i-1, i), f(i, j-1)) + 1;
설명:
f(i, j) : i, j에서 만들 수 있는 가장 큰 사각형의 변의 길이
0인 경우 0값이 들어가게 되고 해당 위치 다음에 나오는 1이 최대 크기 1을 가지게 됨

f(i, j)가 정사각형을 만족하기 위해선 min 내의 3가지 위치에서 동일한 값을 가질 경우 연장이 된다
*/

int MIN(int A, int B, int C){
    int ans;
    if(A>B) ans = B;
    else ans = A;
    if(ans>C) return C;
    return ans;
}

void init(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >>n >> m;
    mp.resize(n+2, vector<int>(m+2));
    for(int i=1;i<=n;++i){
        string temp;
        cin >> temp;
        for(int j=1, row_cnt=0;j<=m;++j){
            mp[i][j] = temp[j-1]-'0';
        }
    }
}

void calc(){
    int ans = 0;
    for(int i=1;i<=n;++i){
        for(int j=1; j<=m;++j){
            if(mp[i][j]==0) continue;
            mp[i][j] = MIN(mp[i-1][j-1], mp[i-1][j],mp[i][j-1]) + 1;
            if(ans < mp[i][j]) ans = mp[i][j];
        }
    }
    cout << ans * ans;
}

int main(){
    init();
    calc();
    return 0;
}