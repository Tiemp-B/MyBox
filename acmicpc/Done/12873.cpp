#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    int N, people;
    cin >> N;
    int stt_idx = 0;
    ll t = 1;

    vector<int> list;
    for(int i=1; i<=N; i++){
        list.push_back(i);
    }

    while(list.size() > 1){
        ll  target = stt_idx + t*t*t -1;
        target = target % list.size();
        list.erase(list.begin() + target);
        stt_idx = target;
        t++;
    }
    cout << list[0];

    return 0;
}