#include <iostream>
#include <vector>

using namespace std;

int N, M; // N: 2 ~ 20, M: 1 ~ 3

int field[21][21] = {};

int ans = 0;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int now[3][2]= {};

int logs[4][3][2]= {};

void calc(){
    vector<vector<bool>> been(N+1, vector<bool>(N+1, false));
    int value =0;
    for(int l=0; l<4; l++){
        for(int p=0; p<M; p++){
            // cout << "l: " <<l <<"  p: " << p << "  => " << logs[l][p][0] << " " << logs[l][p][1]<<endl;
            if(!been[logs[l][p][0]][logs[l][p][1]])
                value += field[logs[l][p][0]][logs[l][p][1]];
            been[logs[l][p][0]][logs[l][p][1]] =true;
        }
    }
    if(ans <value)
        ans = value;

}
void cur(int level){
    if(level == 3){
        calc();
        return;
    }

    for(int d0=0; d0<4 ;d0++){
        if( logs[level][0][0] + dx[d0]==0 || logs[level][0][0] + dx[d0]>N || logs[level][0][1] +dy[d0] == 0 || logs[level][0][1] +dy[d0] > N)
            continue;
        logs[level+1][0][0] = logs[level][0][0] + dx[d0];
        logs[level+1][0][1] = logs[level][0][1] + dy[d0];
        for(int d1=0; d1<4 ; d1++){
            if(M>1){
                if( logs[level][1][0] + dx[d1]==0 || logs[level][1][0] + dx[d1]>N || logs[level][1][1] +dy[d1] == 0 || logs[level][1][1] +dy[d1] > N)
                    continue;
                logs[level+1][1][0] = logs[level][1][0] + dx[d1];
                logs[level+1][1][1] = logs[level][1][1] + dy[d1];
            }
            for(int d2=0; d2<4;d2++){
                if(M>2){
                    if( logs[level][2][0] + dx[d2]==0 || logs[level][2][0] + dx[d2]>N || logs[level][2][1] +dy[d2] == 0 || logs[level][2][1] +dy[d2] > N)
                        continue;
                    logs[level+1][2][0] = logs[level][2][0] + dx[d2];
                    logs[level+1][2][1] = logs[level][2][1] + dy[d2];
                }
                cur(level +1);
                
                if(M < 2)
                    break;
            }
            if(M<1)
                break;
        }
    }

}

void input(){

    cin >> N >>M;
    
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> field[i][j];

    for(int i=0; i<M; i++)
    {
        cin >> now[i][0] >> now[i][1];
        logs[0][i][0] = now[i][0];
        logs[0][i][1] = now[i][1];
    }
}

void test(){
    N = 4;
    M = 2;

    int temp[21][21]={
        {20, 26, 185, 80},
        {100, 20, 25, 80},
        {20, 20, 88, 99},
        {15, 32, 44, 50}};

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            field[i+1][j+1] = temp[i][j];
    
    logs[0][0][0] = 1;
    logs[0][0][1] = 2;
    logs[0][1][0] = 2;
    logs[0][1][1] = 3;
}

void show_field(){
    cout << "field: " << endl;
    for(int i=1; i<=N; i++){
        for(int j=1;j <=N; j++){
            cout <<field[i][j] << " ";
        }
        cout <<endl;
    }
    
}

int main(){
    //input();
    test();
    //show_field();
    cur(0);

    cout << ans;

    return 0;
}
