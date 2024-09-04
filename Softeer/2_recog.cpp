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
    int ans = 0;
    
    cout <<ans;

    return 0;
}