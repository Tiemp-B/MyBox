#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> cage= {
    {'0', 4},
    {'1', 2},
    {'2', 3},
    {'3', 3},
    {'4', 3},
    {'5', 3},
    {'6', 3},
    {'7', 3},
    {'8', 3},
    {'9', 3}
};

int main(){
    string N ="1";
    while(true){
        cin >>N;
        if(N[0] == '0') break;
        int ans =1;

        for(char c : N){
            ans += 1 + cage[c];
        }
        cout<<ans<<endl;
    }

    return 0;
}