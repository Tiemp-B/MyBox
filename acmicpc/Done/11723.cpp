#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int *S = new int[21]();
    int N;
    cin >>N;
            int T;
    for(int i=0; i<N; i++){
        string temp;
        cin >>temp;
        if(temp[1] == 'd'){
            cin >>T;
            S[T] = 1;
        }else if(temp[1] == 'e'){
            cin >>T;
            S[T] = 0;
        }else if(temp[1] == 'h'){
            cin >>T;
            printf("%d\n", S[T]);
        }else if(temp[1] == 'o'){
            cin >>T;
            if(S[T]==1){
                S[T] = 0;
            }else{
                S[T] = 1;
            }
        }else if(temp[1] == 'l'){//all
            for(int j=1; j<21; j++){
                S[j] = 1;
            }
        }else if(temp[1] == 'm'){//empty
            delete S;
            S = new int[21](); 
        }
    }
    int a; //a : 000000000 00000000 a>>1 (a>>2) n  (a>>n)&1  (a>>3)&1

    return 0;
}

/*
비트 마스킹 문제였음!
존재여부는 비트마스킹.... 갯수도 적으니 가능함



*/