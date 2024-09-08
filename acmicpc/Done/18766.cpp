#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> table1, table2;
    int Q;
    cin >>Q;
    for(;Q>0; --Q){
        int C;
        cin >>C;
        for(int i=0; i<C; ++i){
            string temp;
            cin >>temp;
            table1[temp]++;
        }
        for(int i=0; i<C; ++i){
            string temp;
            cin >>temp;
            table2[temp]++;
        }
        bool flag = false;
        for(auto e : table1){
            if(table1[e.first] == table2[e.first]) continue;
            flag = true;
            break;
        }
        if(flag) cout <<"CHEATER\n";
        else cout <<"NOT CHEATER\n";
        table1.clear(); table2.clear();
    }


    return 0;
}