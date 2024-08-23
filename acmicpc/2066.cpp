#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int idx[9]={};

char box[9] = {'6','7','8','9','T','J','Q','K','A'};
string field[9][4];

float ans=0;

map<string, pair<int, int>> loc;
map<char, int> mp;
set<int> st[9];

map<char, pair<int, int>> stage[9]; 

void calc(float per){
    int cnt=0;
    bool end = true;
    for(int i=0; i<9; i++){
        if(stage[i].size() > 1){
            cnt += stage[i].size()*(stage[i].size()-1)/2;
        }
        if(stage[i].size()>0){
            end  = false;
        }
    }

    for(int i=0; i<9; i++){
        for(auto e1 = stage[i].begin(); e1 !=stage[i].end(); ++e1){
            for(auto e2 = next(e1); e2 != stage[i].end(); ++e2){
                auto ee1 = *e1;
                auto ee2 = *e2;
                stage[i].erase(ee1.first);
                stage[i].erase(ee2.first);
                if(ee1.second.second<4){
                    stage[box[field[ee1.second.first][ee1.second.second+1][0]]].insert({})
                }
            }
        }
    }

}




int main(){
    for(int i=0; i<9; i++){
        mp.insert({box[i], i});
    }
    for(int i=0; i<9; i++){
        for(int j=0; j<4; j++){
            cin >>field[i][j];
            if(j==0) st[box[field[i][j][0]]].insert(i);
        }
    }

    


    cout <<ans;

    return 0;
}