#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mx = 1000000000;
int mn = 0;

// 변수 선언부
struct xbox{
    ll ybox[12000];
    int y_max = mn;
    int y_min = mx;
    map<int, int> ylog;
    vector<pair<int, int>> ylist; // y값, value
};

struct lg{
    int y, x, v;
    lg(int yy, int xx, int vv) : y(yy), x(xx), v(vv) {}
};

map<int, int> xlog;

int N; // 최대 3000
int xmx=0, xmn=1000000000, ymx=0, ymn=1000000000;
xbox seg[12000];
vector<lg> log_list;

// 함수 선언부
void init();
xbox get(int x1, int y1, int x2, int y2);
xbox push_x(int x, int y, int xidx, int yidx, int xmin, int xmax);
xbox push_y(int x, int y, int xidx, int yidx, int ymin, int ymax);
xbox push(int x_idx, int y_idx, int x_target, int y_target, ll value);

int main(){

    return 0;
}

void init(){
    cin >> N;
    for (int i=0,y, x, v; i<N; i++){
        cin >> y >> x >> v;
        xlog.insert({x,0});
        log_list.push_back(lg(y,x,v));
    }
    int cnt = 0;
    for (auto e : xlog)
        xlog[e.first] = cnt++;
    
    vector<int> x_idx_list;
    int ix= 1;
    for(auto e : log_list){
        // 최하위 위치에 원소 넣기.   
        int y = e.y;
        int x = e.x;
        int v = e.v;
        int x_end = cnt-1;
        int x_stt = 0;

        while(x_stt != x_end){
            int avg = (x_end+x_stt)/2;
            if(avg < x){
                x_stt = avg+1;
                ix = ix*2 +1;
            }
            else{
                x_end = avg;
                ix *= 2;
            }
        }
        seg[ix].ylist.push_back({y, v});
        x_idx_list.push_back(ix);
    }
    sort(x_idx_list.begin(), x_idx_list.end(), less());
    // update
    for(auto now : x_idx_list){
        if(now == 1)
            break;
        // 현재 위치
        for(auto e : seg[now].ylist){
            // 현 노드의 y 리스트 데이터
            
        }

        // 부모 위치
        int parent = now / 2;
        
    }
}

xbox push(int x_idx, int y_idx, int x_target, int y_target, ll value){

}

xbox get(int x1, int y1, int x2, int y2){

}