#include <stdio.h>

int main(){
    long long int n;
    scanf("%d", &n);
    printf("%lld\n%lld", n*(n-1)/2, 2);
    return 0;
}