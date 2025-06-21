#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int N;
    cin >> N;
    if(N == 1){
        cout << 0;
        return 0;
    }
    priority_queue<int> pq;
    int st, get;
    cin >>st;
    get = st;

    for(int i=1; i<N;++i){
        int temp;
        cin >>temp;
        if(st>temp) continue;
        pq.push(temp);
    }

    while(!pq.empty()){
        int e = pq.top();
        pq.pop();
        if(e< get) continue;
        e--;
        get++;
        if(e >= get)
            pq.push(e);
    }
    
    cout<< get-st;

    return 0;
}