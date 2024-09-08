#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<char> li[5];
    for(int t =0 ; t<5; ++t){
        string word;
        cin >>word;
        li[t].resize(word.size());

        for(int i=0; i<word.size(); ++i) li[t][i] = word[i];
    }

    bool flag = true;

    while(flag){
        flag = false;
        for(int i=0; i<5; i++){
            if(li[i].empty()) continue;
            flag = true;
            cout << li[i][0];
            li[i].pop_front();
        }
    }

    return 0;
}