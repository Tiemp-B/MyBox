#include <iostream>
#include <vector>
using namespace std;

vector<string> shape;


/*
  1
0   2
  3
4   6
  5
*/

vector<bool> on[10]={
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 0, 1}, // 1
    {0, 1, 1, 1, 1, 1, 0}, // 2
    {0, 1, 1, 1, 0, 1, 1}, // 3
    {1, 0, 1, 1, 0, 0, 1}, // 4
    {1, 1, 0, 1, 0, 1, 1}, // 5
    {1, 1, 0, 1, 1, 1, 1}, // 6
    {0, 1, 1, 0, 0, 0, 1}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

int main(){
    int s;
    string n;
    cin >>s >>n;
    
    vector<pair<int, int>> dir={// {a, b} r+a, c+b 위치서  
        {1, 0},     // 0
        {0, 1},     // 1
        {1, s+1},   // 2
        {s+1, 1},   // 3
        {s+2, 0},   // 4
        {2*s+2, 1}, // 5
        {s+2, s+1}  // 6
    };

    shape.resize(3+2*s, string(n.size()-1 +(s+2)*n.size(), ' '));
    vector<int> idx={0};
    for(int i=0; i<n.size(); ++i){
        idx.push_back(idx[i]+s+3);
    }
    int sr=0, sc=0;
    for(int i=0; i<n.size();++i, sc+=s+3){
        int num = n[i]-'0';
        for(int seg=0; seg<7;++seg){
            if(!on[num][seg]) continue;
            int rr=0+dir[seg].first, cc=sc+dir[seg].second;
            for(int cnt=0;cnt<s; ++cnt){
                if(seg%2==0){
                    shape[rr++][cc]='|';
                }else
                    shape[rr][cc++]='-';
            }
        }
    }
    
    for(auto str : shape)
        cout <<str<<endl;
    return 0;
}