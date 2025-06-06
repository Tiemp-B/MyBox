#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

/*
* map을 통해서 문자열이 정렬되는 시간 복잡도는 O(n log n)
* 배열에 넣은 후 문자열이 정렬되는 시간 복잡도 역시 O(n log n)
* 그러나 넣는 과정이 및 정렬 과정이 vector가 더 빠름
* 1. 삽입속도 자체가 빠름
* 2. map의 경우 넣는 즉시 위치가 정렬되나 vector의 경우 sort를 통한 일괄 정렬을 함

* 그 외 것들.
* 정렬시 비교하는 것은 문자열보단 숫자가 빠름. 즉 처음부터 가중치를 부여한다면 속도는 더 빨라질 것.
*/

struct dat{
    string parent = "";
    set<string> child;
    int ances=0;
};

int N, M;

unordered_map<string, dat> mp;
vector<pair<string, string>> cmd;
set<string> name_set;

void init(){
    cin >>N;
    string temp, temp2;
    for(int i=0; i<N;++i){ // O(N)
        cin >>temp;
        mp[temp];
        name_set.insert(temp);
    }
    cin >>M;
    for(int i=0;i<M;++i){ // O(N^2)
        cin >>temp >> temp2;
        cmd.push_back({temp, temp2});
        mp[temp].ances++;
    }
}

void calc(){ //1차 476ms. 2차(map ->u_map) 392ms. 3차(struct경량화) 192ms 최저 답안: 120ms
    vector<string> first_gen;

    for(auto name : name_set){
        if(mp[name].ances == 0)
            first_gen.push_back(name);
    }

    cout << first_gen.size() <<"\n";

    for(string name : first_gen){
        cout <<name <<" ";
    }
    cout <<"\n";

    for(auto item : cmd){
        if(mp[item.first].parent != "")continue;
        if((mp[item.first].ances-mp[item.second].ances) != 1)continue;
        mp[item.first].parent = item.second;
        mp[item.second].child.insert(item.first);
    }

    for(auto item : name_set){
        cout << item <<" " << mp[item].child.size() <<" ";
        for(auto name : mp[item].child){
            cout <<name <<" ";
        }
        cout <<endl;
    }   

}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    init();
    calc();
    return 0;
}