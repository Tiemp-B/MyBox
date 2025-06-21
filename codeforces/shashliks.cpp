#include <iostream>

using namespace std;

int main(){
    ios_base:: sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    // type 1
    // start when temperature >= a
    // after end temperature -= x
    // type 2
    // start when temperature >= b
    // after end temperature -= y
    // initial temperature : k
    int t, k, a, b,x, y;
    cin>> t;
    for(int tc=0; tc<t; ++tc){
        cin >> k >> a>> b>>x>>y;
        int ans =0;
        while(k>=a||k>=b){
            int type =0, cnt1, cnt2;
            if(k>=a && k<b){
                type = 1;
            }else if(k>=b && k<a){
                type = 2;
            }else{
                if(x>y)
                    type = 2;
                else
                    type = 1;
            }
            int cnt=0;
            if(type==1){
                cnt = (k-a)/x;
                k -= cnt*x;
                if(k>=a){
                    cnt++;
                    k -= x;
                }
            }else{
                cnt = (k-b)/y;
                k -= cnt*y;
                if(k>=b){
                    cnt++;
                    k -= y;
                }
            }
            ans += cnt;
        }
        cout <<ans<<endl;
    }

    return 0;
}