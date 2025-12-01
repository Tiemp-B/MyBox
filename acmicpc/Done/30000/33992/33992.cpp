#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double euclid(double ax, double ay, double bx, double by){
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    double ax, ay, bx, by, px, py, r;
    cin >>ax >>ay>>bx>>by>>px>>py>>r;

    double ap = euclid(ax, ay,px,py)-r;
    if(ap<0) ap = 0;
    double bp = euclid(bx,by,px,py)-r;
    if(bp<0) bp = 0;
    double ans = ap+bp;
    double ans2 = euclid(ax, ay, bx,by);
    if(ans > ans2) ans = ans2;
    
    printf("%.013f", ans);

    return 0;
}