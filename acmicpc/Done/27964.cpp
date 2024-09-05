#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int N;
    cin >>N;
    vector<string> topping(N);
    string cheese = "Cheese";
    set<string> st;
    for(int i=0; i<N; i++){
        cin >>topping[i];
        if(topping[i].size() < 6) continue;
        bool check = true;
        for(int t=0; t<6; t++){
            if(topping[i][topping[i].size()-1-t] != cheese[5-t]){
                check = false;
                break;
            }
        }
        if(check) st.insert(topping[i]);
    }
    if(st.size()>=4) cout <<"yummy";
    else cout <<"sad";

    return 0;
}