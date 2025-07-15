#include <iostream>
using namespace std;

int stair[305];
int *been;

int ans =0;
int N;

void calc(int now, int prev, int score){
    if(now<=0){
        if(ans <score) ans =score;
        return ;
    }
    int new_score = score + stair[now];

    if(now +1 != prev)
        calc(now-1, now, new_score);
    calc(now-2, now, new_score);
}

int mat[305]={};
int vis[305]={};

void calc2(){
    mat[N] = stair[N];
    vis[N] = vis[N];

    for(int i=N; i>0; --i){
        cout <<"from: "<<i<<"  ";
        if(vis[i]==i+1){// i+1 -> i :  i-2로 넘어가야함
            if(i-2>0){
                int score = mat[i] + stair[i-2];
                if(mat[i-2]< score){
                    mat[i-2] = score;
                    vis[i-2] = i;
                }
            }else{//0보다 내려감
                if(mat[0] < mat[i]){
                    mat[0] = mat[i];
                }
            }
        }else{  //  i+2 -> i:  i-1, i-2 둘 다 가능함
            //i-1로
            if(i-1>0){
                int score = mat[i] + stair[i-1];
                if(mat[i-1]< score){
                    mat[i-1] = score;
                    vis[i-1] = i;
                }
            }else{
                if(mat[0] < mat[i]) mat[0] = mat[i];
            }

            // i-2로
            if(i-2>0){
                int score = mat[i] + stair[i-2];
                if(mat[i-2]< score){
                    mat[i-2] = score;
                    vis[i-2] = i;
                }
            }else{
                if(mat[0] < mat[i]) mat[0] = mat[i];
            }
        }
    }

    for(int i=0; i<=N; i++){
        cout<< mat[i] <<" ";
    }
    cout <<endl;
}

void calc3(){
    mat[1] = stair[1];
    mat[2] = stair[1]+stair[2];
    mat[3] = (stair[1] > stair[2]) ? stair[1]+stair[3]: stair[2]+stair[3];
    
    for(int i=3; i<=N ; i++){
        int p1 = mat[i-3]+stair[i-1]+stair[i];
        int p2 = mat[i-2]+stair[i];
        if(p1<p2) mat[i] = p2;
        else mat[i] = p1;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >>N;
    for(int i=1; i<=N; i++){
        cin >>stair[i];
    }

    // calc(N, N, 0);
    // cout << ans;

    // calc2();
    // cout <<mat[0];

    calc3();
    cout <<mat[N];
    return 0;
}

