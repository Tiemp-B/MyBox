#include <iostream>
#include <queue>

using namespace std;

struct box{
    int num;
    bool type;
    bool operator<(const box &next) const{
        return num > next.num;
    }
    box(int n, bool t){
        num = n;
        type = t;
    }
};

int main(){
    int cost[4]={};
    cin >> cost[1] >>cost[2]>>cost[3];
    
    priority_queue<box> pq;
    for(int i=0; i<3; i++){
        int s, e;
        cin >>s >>e;
        pq.push(box(s, true));
        pq.push(box(e, false));
    }
    int ans = 0;
    int car = 0;
    int intime = 0;
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        ans += (now.num-intime) * (cost[car]*car);
        if(now.type){// 주차
            if(car!= 0)
                intime = now.num;
            else
                intime = now.num;
            car++;
        }else{ // 빠짐
            car--;
            intime = now.num;
        }
    }

    cout << ans;

    return 0;
}