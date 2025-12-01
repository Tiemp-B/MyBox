#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll N, P, Q;

unordered_map<ll, ll> mp;

/*
점화식은 주어졌으니 이를 응용할 함수의 제작이 중점
N이 10^12의 크기를 가지므로 int 이상의 범위를 챙겨야 하므로 long long 사용
P, Q가 2 이상이며 나누기 특성상 모든 구간의 값을 구할 필요도 없으며, 기록할 공간을 할당할 이유도 없다
따라서 map을 사용하여 데이터를 저장, 호출하도록 한다

분할 정복의 형태를 따라간다
10^12 2 2의 경우에서도 재호출이 100회도 안되므로 사용이 가능함
*/

ll func(ll i){
    if(mp[i]!=0) return mp[i];

    ll ip = i/P;
    ll iq = i/Q;
    func(ip);
    func(iq);
    
    mp[i]=mp[ip]+mp[iq];
    return mp[i]; 
}

int main(){
    cin >>N >>P >>Q;
    mp[0] = 1;
    cout << func(N);
    return 0;
}