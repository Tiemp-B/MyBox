#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M;
int people[101];
int box[101][101];// i-1날 청소를 하였음 j날 청소를 할 예정
int dirtBox[102];
int cache[11][101];
bool bin [11][101];
void fill(){
    int now = 0;
    int dirt = 0;
    for(int i=1; i < N+1; i++){
        for(int j = i ; j < N+1 ; j++){
            box[i][j] += box[i][j-1] + (dirtBox[j]-dirtBox[i]) * people[j];
        }
    }
}

map<int, vector<int>> mp;

vector<int> ans;
queue<int> as;

void calc1(int i, int j){ // i일부터 j일 까지 누적 불쾌지수
}

int calc2(int n, int fr, int v){ // fr일부터 종료일까지 n회 남았을 때의 계산 
    if (bin [n][fr]) return cache[n][fr];
    if(n == 0) {
        mp[v] = ans;
        return cache[fr][N] = box[fr][N];
    }

    bin[n][fr] = true;

    int& ret = cache[n][fr];
    int mn = 2147483647;
    for(int i = fr; i<N; i++){
        ans[M-n] = i-1;
        int temp = box[fr][i] + calc2(n-1, i+1, v + ret);//fr부터 i일까지의 누적 불쾌지수 + i일 청소 이후의 최소 불쾌지수;
        if(mn > temp) {
            mn = temp;
            ret = mn;
        }
    }
    return ret;
}


// 하루에 쌓이는 불쾌지수 = (전날 오염도) * 방문객수
// 어떤 날의 오염도 = (마지막 청소일 ~ 전날 방문객 수 의 총합)
// 

int main(){
    cin >>N >>M;

    for(int i=1, temp; i<=N; i++){
        cin >> people[i];
        dirtBox[i+1] += dirtBox[i] + people[i];
    }
    fill();
    for(int i = 0; i<=M+1; i++) ans.push_back(i);

    
    int ret = calc2( M, 1, 0 );
    cout << ret <<endl;
    auto aa = mp[ret];
    
    return 0;
}