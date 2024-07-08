#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct node{
    int s;
    int e;
    int layer;

    bool operator<(const node next) const{
        if(e-s == next.e-next.s) return s > next.s;
        return e-s < next.e-next.s;
    }
};

int main(){
    int N, M;
    cin >>N >>M;

    vector<int> A;
    for(int i=0, temp; i<N; i++){
        cin >>temp;
        A.push_back(temp);
    }

    sort(A.begin(), A.end());

    priority_queue<node> box;
    for(int i=0, s, e; i<M; i++){
        cin >>s >>e;
        box.push(node{s, e, 1});
    }

    unordered_map<int, int> boxx;
    boxx.insert(3,3);
    boxx.

    vector<node> arr;
    while(!box.empty()){
        auto now = box.top(); box.pop();

        

    }

    



    return 0;
}