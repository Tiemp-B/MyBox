#include <iostream>

using namespace std;


unsigned long long int func(long long int n){
    if (n == 0)
        return 0;
    unsigned long long int l = 0, u = 1;
    unsigned long long int ans = 1;
    ans = ans << 40;
    u = 1 + u << 31;
    while(l <= u){
        unsigned long long int mid = (l+u)/2;
        unsigned long long int q = mid * mid;
        
        if (q >= n){
            if( ans > mid)
                ans = mid;
            u = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}

int main(){
    long long int n;

    cin >> n;

    cout << func(n);

    return 0;
}


/*
디버깅 내역
1. 범위 지정. 2^63 이므로 답은 2^32보다 작으므로 상한을 2^32로 한다
2. 범위 지정. 0도 답이 되므로 하한을 0으로 적용한다
3. 무한루프 해소. 0일 시 무한 루프에 빠지게 되므로 예외처리한다 

*/
