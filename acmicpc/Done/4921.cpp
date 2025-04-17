#include <iostream>
#include <set>
using namespace std;

set<int> valid_piece[9];

int main(){
    // 시작: 1 -> 4, 5
    valid_piece[1].insert(4);
    valid_piece[1].insert(5);
    // 종단: 2 -> 1
    // 3 -> 4, 5
    valid_piece[3].insert(4);
    valid_piece[3].insert(5);
    // 4 -> 2, 3
    valid_piece[4].insert(2);
    valid_piece[4].insert(3);
    // 5 -> 8
    valid_piece[5].insert(8);
    // 6 -> 2, 3
    valid_piece[6].insert(2);
    valid_piece[6].insert(3);
    // 7 -> 8
    valid_piece[7].insert(8);
    // 8 -> 6, 7
    valid_piece[8].insert(6);
    valid_piece[8].insert(7);

    string inp="stt";
    cin >> inp;
    int t = 0;
    while(inp != "0"){
        t++;
        bool flag = false;
        for(int i=0; i<inp.size()-1;i++){
            if(valid_piece[inp[i]-'0'].find(inp[i+1]-'0') == valid_piece[inp[i]-'0'].end()){
                flag = true;
                break;
            }
        }
        if(inp[0] !='1' ||inp.back() !='2')
            flag = true;

        if(flag)
            cout << t<< ". NOT"<<endl;
        else 
            cout << t << ". VALID"<<endl;
        cin >> inp;
    }

    return 0;
}