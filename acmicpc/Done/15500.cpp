#include <iostream>
#include <vector>

using namespace std;

int loc [123];
int depth [124];
int poles[4];
int N;


void init(){
    cin >>N;
    for(int i=0, t;i<N;++i){
        cin >> depth[i];
        loc[depth[i]] = 1;
    }
}

void calc(){
    vector<pair<int, int>> logs(12345);
    int idx= N-1;
    int log_idx=0;
    for(int r=N; r>0 &&log_idx<12345; --r){
        if(loc[r]==1){
            while(loc[depth[idx]]!=1) idx--;

            while(depth[idx]!=r){
                switch(loc[depth[idx]]){
                    case 1:
                        logs[log_idx++]={1, 2};
                        loc[depth[idx]]=2;
                        idx--;
                        if(log_idx==12345) break;   
                        break;
                    case 3:
                        idx--;  
                        break;
                }
            }
            if(log_idx==12345) break;  
            logs[log_idx++]={1, 3};
            loc[r]=3;
        }else if(loc[r]==2){
            while(loc[depth[idx]]!=2) idx++;

            while(depth[idx]!=r){
                switch(loc[depth[idx]]){
                    case 2:
                        logs[log_idx++]={2, 1};
                        loc[depth[idx]]=1;
                        idx++;
                        if(log_idx==12345) break;  
                        break;
                    case 3:
                        idx++;
                        break;
                }
            }
            if(log_idx==12345) break;  
            logs[log_idx++]={2, 3};
            loc[r]=3;
        }
    }

    cout <<log_idx<<"\n";

    for(int i=0; i<log_idx;++i){
        cout << logs[i].first<<" "<<logs[i].second<<"\n";
    }

}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    calc();


    return 0;
}