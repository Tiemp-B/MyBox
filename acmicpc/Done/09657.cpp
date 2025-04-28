#include <iostream>
#include <cstdio>
using namespace std;

int choice[3] = {1, 3, 4};
int mem[1001] ={};
string name[] ={"", "SK\n", "CY\n"};

int main(){
    int N;
    cin >>N;

    mem[1] = 1;
    mem[2] = 2;
    mem[3] = 1;
    mem[4] = 1;

    for(int i=5;i<=N;++i){
        mem[i] = 2;
        for(int d= 0; d<3;++d){
            if(mem[i-choice[d]] ==2){
                mem[i] = 1;
                break;
            }
        }
    }
    cout << name[mem[N]];

    return 0;
}