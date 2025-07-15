#include <iostream>
#include <vector>
using namespace std;

void calc(){
    int R, C;
    cin >>R >> C;
    vector<vector<long long>> field(R+1,vector<long long>(C+1));
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            cin >>field[i][j];
            long long f[5];
            f[0] = field[i][j];
            f[1] = field[i][j]-field[i][j-1];
            f[2] = field[i][j]-field[i-1][j];
            f[3] = field[i][j]-(field[i][j-1]+field[i-1][j])/2;
            f[4] = field[i][j]-(field[i][j-1]+field[i-1][j]-field[i-1][j-1]);
            int f_num=0;
            for(int t=1; t<5;++t) if(abs(f[f_num])>abs(f[t])) f_num=t;
            cout << f_num <<" "<< f[f_num]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int tc;
    cin >>tc;
    for(;tc>0;--tc) calc();
    return 0;
}