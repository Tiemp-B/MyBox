#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

double calc(double x1, double y1, double x2, double y2, double x3, double y3){
    return fabs(x1*y2+x2*y3+x3*y1 - (x3*y2+x2*y1+x1*y3))/2;
}

int main(){
    int N;
    cin >>N; 
    vector<pair<double, double>> pos;
    for(int i=0; i<N; i++){
        double x, y;
        cin >>x >>y;
        pos.push_back(make_pair(x, y));
    }
    double ans = 0;
    for(int i=0; i<pos.size(); i++){
        for(int j=i+1; j<pos.size(); j++ ){
            for(int k=j+1; k<pos.size();k++){
                double face = calc(pos[i].first, pos[i].second, pos[j].first, pos[j].second, pos[k].first, pos[k].second);
                if (face > ans)
                    ans = face;
            }
        }
    }
    printf("%.1f", ans);


    return 0;
}