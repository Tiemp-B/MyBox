#include <stdio.h>
#include <stdlib.h>

int main2(){
    int N, A, D;
    scanf("%d %d %d", &N, &A, &D);
    int ans =0;
    int An = A;
    int* e = (int*)malloc(sizeof(int)*N);

    for(int i=0; i<N;++i){
        scanf(" %d", &e[i]);
    }
    for(int i=0;i<N;++i){
        if(e[i] == An){
            An += D;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}

int main(){
    
}

/*c++

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N, A, D;
    cin >> N >> A >> D;
    int ans=0, An=A;
    vector<int> e(N);
    for(int i=0, temp; i<N;++i)
        cin >> e[i];

    for(int i=0;i<N;++i){
        if(e[i]==An){
            ans++;
            An += D;
        }
    }
    cout << ans;
}

*/