#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int C;
    cin >>C;
    for(int i=1, x, y; i<=C; i++){
        cin >>x >>y;
        printf("Case #%d: %d + %d = %d\n", i, x, y, x+y);
    }
}
