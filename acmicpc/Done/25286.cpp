#include <iostream>

using namespace std;

int days[] ={-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr)->sync_with_stdio(false);
    int T, y, m;
    cin >>T;
    for(int i=0; i<T; ++i){
        cin >> y >> m;
        switch(m){
            case 1:
                cout << y-1 << " 12 31\n";
                break;
            case 3:
                if((y%100!=0 && y%4==0) || y%400==0){
                    cout <<y <<" 2 29\n";
                }
                else
                    cout <<y <<" 2 28\n";
                break;
            default:
                cout <<y <<" "<< m-1 <<" "<< days[m-1]<<"\n";
        }
    }
    return 0;
}