#include <iostream>
#include <vector>
using namespace std;

int dy[] = {-1, 0, 1, 0};//상, 우, 하, 좌
int dx[] = {0, 1, 0, -1};
int main(){
    // cin.tie(nullptr)->sync_with_stdio(false);
    int N, ny, nx;
    cin >>N;
    vector<string> field(N);
    vector<vector<int>> c(N, vector<int>(N,0));
    pair<int, int> heart={-1, -1};
    int dir=-1;
    for(int i=0; i<N;++i){
        cin >> field[i];
        for(int j=0;j<N && heart.first==-1;++j){
            if(field[i][j]!='*') continue;
            for(int d=0; d<4&&heart.first==-1;++d){
                ny= i+dy[d];
                nx= j+dx[d];
                if(ny<0||nx<0||ny==N||nx==N) continue;
                c[ny][nx]++;
                if(c[ny][nx]==4)
                    heart = {ny, nx};
            }
        }
    }
    cout <<heart.first+1 <<" "<<heart.second+1<<"\n";
    int dd;
    // 머리가 방향일 때, 0 <-> 2, 1<->3
    for(int d=0; d<4 && dir==-1;++d){//상, 우, 하, 좌 
        dd = (d+2)%4;
        ny= heart.first+ dy[dd] +dx[dd] ;
        nx= heart.second+ dx[dd] +dy[dd] ;
        for(; ny<N&&ny>=0&&nx<N&&nx>=0; ny+=dy[dd], nx+=dx[dd]){
            if(field[ny][nx]=='*'){
                dir = d;
                break;
            }
        }
    }
    // 머리 방향은 dir
    // 좌수
    int arm_l=0, arm_r=0, body=0, leg_l=0, leg_r=0;
    dd = (dir+4-1)%4;
    ny=heart.first,nx=heart.second;
    while(true){
        ny += dy[dd];
        nx += dx[dd];
        if(ny<0||nx<0||ny==N||nx==N) break;
        if(field[ny][nx]!='*')break;
        arm_l++;
    }
    // 우수
    dd = (dir+1)%4;
    ny=heart.first,nx=heart.second;
    while(true){
        ny += dy[dd];
        nx += dx[dd];
        if(ny<0||nx<0||ny==N||nx==N) break;
        if(field[ny][nx]!='*')break;
        arm_r++;
    }
    // 허리
    dd = (dir+2)%4;
    ny=heart.first,nx=heart.second;
    while(true){
        ny += dy[dd];
        nx += dx[dd];
        if(ny<0||nx<0||ny==N||nx==N) break;
        if(field[ny][nx]!='*')break;
        body++;
    }

    while(true){
        if(ny<0||nx<0||ny==N||nx==N) break;
        switch(dir){
            case 0:
                if(field[ny][nx+1]=='*')
                    leg_r++;
                if(field[ny][nx-1]=='*')
                    leg_l++;
                break;
            case 1:
                if(field[ny+1][nx]=='*')
                    leg_r++;
                if(field[ny-1][nx]=='*')
                    leg_l++;
                break;
            case 2:
                if(field[ny][nx+1]=='*')
                    leg_l++;
                if(field[ny][nx-1]=='*')
                    leg_r++;
                break;
            case 3:
                if(field[ny+1][nx]=='*')
                    leg_l++;
                if(field[ny-1][nx]=='*')
                    leg_r++;
                break;
        }
        ny += dy[dd];
        nx += dx[dd];
    }

    cout << arm_l<<" "<<arm_r<<" "<<body<<" "<<leg_l<< " "<<leg_r;
    

    return 0;
}

/*
5
--*--
-***-
--*--
-*-*-
-*---

9
____*____
___******
____*____
____*____
____*____
___*_*___
___*_*___
___*_____
_________

5
-*---
-*-*-
***--
-*-**
-----

5
-----
-*-*-
--***
**-*-
---*-

*/