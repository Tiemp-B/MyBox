#include <iostream>
#include <vector>
using namespace std;


int NEW = -1001;

struct rect{
    int x_min=NEW;
    int x_max=NEW;
    int y_min=NEW;
    int y_max=NEW;
};

int main(){
    int N, K;
    cin >>N >>K;
    vector<rect> box(K+1);
    
    for(int i=0,x ,y,c; i<N;i++){
        cin >>x >>y>> c;
        if(box[c].x_min == NEW){
            box[c].x_max = x;
            box[c].x_min = x;
            box[c].y_max = y;
            box[c].y_min = y;
            continue;
        }
        if(box[c].x_min>x) box[c].x_min = x;
        if(box[c].x_max<x) box[c].x_max = x;
        if(box[c].y_min>y) box[c].y_min = y;
        if(box[c].y_max<y) box[c].y_max = y;
    }
    int ans = 2147483647;
    for(int i=1; i<=K; ++i){
        int temp = (box[i].x_max - box[i].x_min+1)*(box[i].y_max - box[i].y_min + 1);
        if (ans > temp) ans = temp;
    }
    
    cout <<ans;

    return 0;
}