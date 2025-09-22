#include <iostream>
#include <vector>
using namespace std;
int func(){
    return 0;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >>N >>M;
    vector<vector<int>> field(N+1, vector<int>(N+1));
    for(int i=0, temp; i<N;++i){
        for(int j=0;j<N;++j){
            cin >>temp;
            field[i][j+1] = field[i][j] +temp;
        }
    }

    int x1,x2,y1,y2;
    for(int i=0;i<M;++i){
        cin >> x1 >>y1 >>x2 >>y2;
        
    }


    return 0;
}