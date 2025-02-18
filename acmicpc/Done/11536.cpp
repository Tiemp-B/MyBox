#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> name_list;
    set<string> name_set;
    
    for(int i=0; i<N;i++){
        string temp;
        cin >> temp;
        name_list.push_back(temp);
        name_set.insert(temp);
    }

    bool inc = true;
    bool dec = true;
    int i= 0;
    for(auto name : name_set){
        if(inc)
            if(name != name_list[i])
                inc = false;
        if(dec)
            if(name != name_list[N-1 -i])
                dec = false;
        i++;
    }

    if(inc)
        cout << "INCREASING";
    else if(dec)
        cout << "DECREASING";
    else
        cout << "NEITHER";

    return 0;
}