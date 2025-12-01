// #include<stdio.h>

// int main(){
//     int N;
//     scanf("%d", &N);
//     long long int W=0, H=0, a, b;
//     for(int i=0; i<N;++i){
//         scanf(" %lld %lld", &a, &b);
//         if(a<b){
//             if(W < b){
//                 W = b;
//             }
//             if(H < a){
//                 H = a;
//             }
//         }else{
//             if(W <a){
//                 W = a;
//             }
//             if(H <b){
//                 H = b;
//             }
//         }
//     }
//     printf("%lld", W*H);

//     return 0;
// }


#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N;
    cin >>N;
    long long int W=0, H=0, a, b;
    for(int i=0; i<N;++i){
        cin >> a >> b;
        if(a<b){
            if(W < b){
                W = b;
            }
            if(H < a){
                H = a;
            }
        }else{
            if(W <a){
                W = a;
            }
            if(H <b){
                H = b;
            }
        }
    }
    cout << W*H;
    return 0;
}
