#include <iostream>
#include <vector>

using namespace std;

int main(){
    int k, s;
    cin >>k >>s;
    char *inp = new char[s+1];
    cin.getline(inp, 1, '\n');
    cin.getline(inp, s+1, '\n');

    for(int i =0; i<s; i++){
        char c = inp[i];
        if(c ==' '||c=='.'||c==',') c = c;
        else if(c>='a') {
            c = 'a'+(c-'a' + k) % 26;
        }else{
            c = 'A'+(c-'A'+ k) %26;
        }
        cout <<c;
    }

    return 0;
}