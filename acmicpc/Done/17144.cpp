#include <iostream> 
#include <vector>

using namespace std;

// R,C<=50, T = 1000
// A -1 ~ 1000. -1 -> 공청기

class p17144{
    int R, C, T;
    int cc[2]={-1, 0};
    vector<vector<int>> A;
    vector<vector<int>> sub;
    int dy[4]={-1, 0, 1, 0};
    int dx[4]={0, 1, 0,-1};
public:
    void init(){
        cin >>R >>C >>T;
        A.resize(R, vector<int>(C));
        sub.resize(R, vector<int>(C, 0));
        for(int i=0; i<R;++i){
            for(int j=0; j<C;++j){
                cin >>A[i][j];
                if(A[i][j]==-1){
                    if(cc[0]==-1) cc[0] = i;
                    else cc[1] = i;
                }
            }
        }
    }
    int calc(){
        for(int t=0; t<T; ++t){
            dust_spread();
            air_move();
        }
        int ans = 0;
        for(int i=0; i<R;++i){
            for(int j=0;j<C;++j){
                if(A[i][j]<1) continue;
                ans += A[i][j]; 
            }
        }
        return ans;
    }
    void prnt(){
        for(int i=0; i<R;++i){
            for(int j=0;j <C;++j){
                cout <<A[i][j] <<" ";
            }
            cout <<"\n";
        }
    }
private:
    void dust_spread(){
        for(int i=0; i<R;++i){
            for(int j=0, div, cnt;j <C;++j){
                if(A[i][j] < 1) continue; // -1, 0 넘어가기
                div = A[i][j]/5;
                cnt = 0;
                for(int d=0; d<4;++d){
                    int ny = i+dy[d];
                    int nx = j+dx[d];
                    if(ny<0||nx<0||ny==R||nx==C) continue;
                    if(ny == cc[0] && nx == 0 ||ny==cc[1] && nx==0) continue;
                    cnt++;
                    sub[ny][nx] += div;
                }
                A[i][j] -= cnt*div;
            }
        }
        for(int i=0; i<R;++i){
            for(int j=0, div, cnt;j <C;++j){
                A[i][j] += sub[i][j];
                sub[i][j] = 0;
            }
        }
    }


    void air_move(){// taking dust move
        // upper
        A[cc[0]-1][0] = 0;
        for(int r=cc[0]-2; r>=0; --r){ // go up
            A[r+1][0] = A[r][0];
        }
        for(int c=1;c<C;++c){ // go right
            A[0][c-1] = A[0][c];
        }
        for(int r=1; r<=cc[0]; ++r){
            A[r-1][C-1] = A[r][C-1];
        }
        for(int c=C-2; c>0; --c){
            A[cc[0]][c+1] = A[cc[0]][c];
        }
        A[cc[0]][1]=0;
        // lower
        for(int r=cc[1]+2; r<R;++r){
            A[r-1][0] = A[r][0];
        }
        for(int c=1;c<C;++c){
            A[R-1][c-1] = A[R-1][c];
        }
        for(int r=R-2; r>=cc[1];--r){
            A[r+1][C-1] = A[r][C-1];
        }
        for(int c=C-2; c > 0 ;--c){
            A[cc[1]][c+1] = A[cc[1]][c];
        }
        A[cc[1]][1]=0;
    }
    
};


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    p17144 task;
    task.init();
    cout << task.calc();

    return 0;
}