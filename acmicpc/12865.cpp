#include <iostream>

using namespace std;

int N, K;
int ans = 0;

int *W;
int *V;

int **mat;

int main(){
    W= new int[N];
    V= new int[N];

    cin >>N >>K;

    for(int i=0; i<N; ++i){
        cin >>W[i] >>V[i];
    }

    mat = new int*[N];
    for(int i=0; i<N; ++i) mat[i] = new int[K+1]();

    for(int k=1; k<=K; k++){


    }
    cout <<ans;

    return 0;
}