#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    unordered_set<int> fr;
    vector<int> order;

    for(int i=0, temp; i<N; i++){
        cin >> temp;
        order.push_back(temp);
    }
    for(int i=0, temp; i<M; i++){
        cin >> temp;
        fr.insert(temp);
    }
    int ans = 0;
    for(int i=0; i<M; i++){
        if(fr.find(order[i]) == fr.end())
            ans++;
    }
    cout <<ans;

    return 0;
}