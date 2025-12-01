#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H, W, C, D, temp;
    cin >>H>>W>>C>>D;
    bool flag=true;

    // W에서 표현 가능한 합의 종류 = W+1. 즉 H가 W+1 보다 커지면 표현 불가하다
    if(W+1<H) flag = false;
    //
    temp = (H-1)*H/2; // 최소 갯수. 
    if(D<temp) flag = false;
    if(C<temp) flag = false;
    if(!flag) {
        cout << -1;
        return 0;
    }

    vector<vector<int>> v(H);
    for(int i=0, t=0; i<H;++i,++t){
        for(int j=0;j<t;++j){
            v[i].push_back(9);
            D--;
        }
    }
    for(int i=H-1, t=0; i>=0;--i, ++t){
        for(int j=0;j<t;++j){
            v[i].push_back(1);
            C--;
        }
    }
    for(int i=0;i<H;++i){
        while(v[i].size()<W){
            if(C-->0) {
                v[i].push_back(1);
            }else{
                v[i].push_back(9);
            }
        }
    }

    for(auto &r: v){
        for(auto &e : r){
            cout <<e<<" ";
        }
        cout <<"\n";
    }

    return 0;
}