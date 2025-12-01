#include <iostream>
#include <cstdio>

int main(){
    int A, B, N;

    std::cin >>N;

    for(int i=1;i <= N; i++){
        std::cin >>A >>B;
        printf("Case #%d: %d\n", i, A+B);
    }

    return 0;
}