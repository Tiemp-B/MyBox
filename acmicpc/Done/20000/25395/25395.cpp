#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>

#define Hbound 1000000000
#define Lbound 0

using namespace std;

struct car{
    int stt;
    int fuel;
    int car_num;
    bool connected=false;
};

struct node{
    vector<int> car_list;
    int now;
    int min_pos=Hbound+1;
    int max_pos=Lbound-1;
    void update(int fuel){
        max_pos = max(max_pos, now + fuel);
        min_pos = min(min_pos, now - fuel);
    }
};

int N, S; //
vector<car> cars; //{start loc, fuel}
map<int, node> mp;

void init(){
    cin >>N >>S;
    cars.resize(N+2);    
    for(int i=1, t; i<=N;++i){
        cin >> cars[i].stt;
    }
    
    for(int i=1, h; i<=N;++i){
        cin >> cars[i].fuel;
    }
}

void calc(){
    int l=S, r=S;
    int mn=cars[S].stt - cars[S].fuel;
    int mx=cars[S].stt + cars[S].fuel;

    bool changed = true;
    while(changed){
        changed = false;
        if(cars[l].stt >= mn && l!=0){
            cars[l].connected=true;
            mn = min(mn, cars[l].stt-cars[l].fuel);
            mx = max(mx, cars[l].stt+cars[l].fuel);
            changed =true;
            l--;
        }
        if(cars[r].stt <=mx && r !=N+1){
            cars[r].connected=true;
            mn =min(mn, cars[r].stt-cars[r].fuel);
            mx =max(mx, cars[r].stt+cars[r].fuel);
            changed =true;
            r++;
        }
    }
    for(int i=1;i<=N;++i){
        if(cars[i].connected) cout <<i<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    init();
    calc();

    return 0;
}