#include <iostream>
#include <cstdio>
using namespace std;

double a, e = 0, b, n;
double a_max= -2e6, a_min=2e6;
double min_sol = 2e6;
double ans = 0;

double err_rate = 1e-9;

double element[5]={};

double pow(double inp, int cnt){
    double ret = 1;
    for(int i=0;i<cnt;++i) ret*= inp;
    return ret;
}

double sum_err(double a_value){
    double ret=0;
    for(int i=0; i<4;++i) ret += element[i]*pow(a_value, i);
    return ret;
}

double dabs(double inp){
    return inp*(inp<0? -1:1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >>b;
    double x, y;
    for(int i=0;i<n;++i){
        cin >> x>> y;
        double temp = (y-b)/x;
        element[0] += 4*x*(b-y)*(b-y)*(b-y);
        element[1] += 12*x*x*(b-y)*(b-y);
        element[2] += 12*x*x*x*(b-y);
        element[3] += 4*x*x*x*x;
        if(a_max < temp) a_max = temp;
        if(a_min > temp) a_min = temp;
    }
    double mid = (a_min+a_max)/2;
    while(dabs(a_max-a_min) > err_rate){
        mid = (a_min+a_max)/2.0;
        double calc = sum_err(mid);
        if(dabs(calc)< err_rate){
            break;
        }else if(calc>err_rate){
            a_max = mid-err_rate;
        }else {
            a_min = mid+err_rate;
        }
    }

    printf("%.10f\n", mid);

    return 0;
}
