#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >>n;
    
    for(int t=1; t<=n;++t){
        bool flag = true;
        vector<vector<bool>> cols(10, vector<bool>(10,false));
        vector<vector<bool>> rows(10, vector<bool>(10,false));
        vector<vector<vector<bool>>> sq(3, vector<vector<bool>>(3, vector<bool>(10,false)));

        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                int num;
                cin >>num;
                flag = flag&&(!cols[i][num])&&(!rows[j][num])&&(!sq[i/3][j/3][num]);
                if(!flag) continue;
                cols[i][num]=true;
                rows[j][num]=true;
                sq[i/3][j/3][num]=true;
            }
        }
        if(flag){
            cout <<"Case "<<t<<": CORRECT\n";
        }else
            cout <<"Case "<<t<<": INCORRECT\n";
    }
    
    return 0;
}
