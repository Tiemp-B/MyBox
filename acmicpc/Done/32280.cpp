#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    N++;
    vector<int> t;
    int TT;
    for(int i=0; i<N;++i){
        char buff[10]="";
        int HH, MM;
        scanf("%d:%d %s", &HH, &MM, buff);
        if(buff[0] == 't'){
            TT = HH*60 +MM;
        }else{
            t.push_back(HH*60 + MM);
        }
    }
    int EH, EM, E;
    scanf(" %d:%d", &EH, &EM);
    E = EH*60 + EM;
    int ans =0;
    for(int i=0; i<t.size();++i){
        if(t[i] >= TT){// 선생과 동시 도착 혹은 이후 도착
            if(t[i] >= E) ans++; //정해진 시각 이후인가?
        }
    }
    cout <<ans;

    return 0;
}