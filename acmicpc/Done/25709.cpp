#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
        return a.first > b.first;
    }
};

int main(){
    int N;
    cin >>N;

    priority_queue<pair<int, int>, vector<pair<int, int>>,cmp> pq;

    pq.push(make_pair(N, 0));

    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        // cout <<top.first <<endl;

        if(top.first == 0){
            cout <<top.second;
            break;    
        }
        pq.push(make_pair(top.first-1, top.second+1));

        string str = to_string(top.first);

        for(int i=0; i<str.size(); i++){
            if(str[i] == '1'){
                string temp = str;
                temp.erase(i, 1);
                int a;
                if (temp.size()>0)
                    a = stoi(temp);
                else 
                    a = 0;
                pq.push(make_pair(a, top.second+1));
            }
        }
        

    }

    return 0;
}

// 1001000 -> 2번
//