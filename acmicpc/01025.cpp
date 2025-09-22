#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int mxx=9,N, M;

int table[9][9];
unordered_set<int> m;

void init(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >>N >>M;
    for(int i=0; i<N||i<M;++i){
        mxx = mxx*10+9;
    }

    char temp;
    for(int i=0; i<N;++i){
        for(int j=0;j <M;++j){
            cin >>temp;
            table[i][j] = temp-'0';
        }
    }

    for(int i=0, ii=0; ii<=mxx;++i,ii=i*i){
        m.insert(ii);
    }
    
}

void calc(){
    int value=0, ans=-1, ny, nx; 
    for(int i=0; i<N; ++i){
        for(int j=0;j <M;++j){
            for(int ay=-N+1; ay<=N-1; ++ay){
                for(int ax=-M+1; ax<=M-1;++ax){
                    value = table[i][j];        
                    if(ay==0 && ax==0){
                        if(m.find(value)!=m.end()&&value>ans)
                            ans = value;
                    }else{
                        ny = i+ay;
                        nx = j+ax;
                        while(ny>=0&&ny<N && nx>=0 &&nx<M){
                            value = value*10 + table[ny][nx];
                            if(m.find(value)!=m.end() &&value>ans)
                                ans = value;
                            ny+=ay;
                            nx+=ax;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}

int main(){
    init();
    calc();
    return 0;
}
