#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main2(){
    int N, K;
    cin >> N >>K;
    
    vector<int> items;
    for(int i=0; i<N; i++){
        int temp;
        cin >>temp;
        items.push_back(temp);
    }

    sort(items.begin(), items.end(), desc);

    unordered_map<int, int> mp = {{K, 0}}; // rest caffeine 

    bool flag = false;

    for(int item : items){
        vector<pair<int, int>> new_log;

        for(auto log : mp){
            int key = log.first - item;
            if(key < 0) continue;
            if(key ==0) flag = true;
            new_log.push_back({key, log.second+1});
        }

        for(auto log : new_log){
            if(mp[log.first] == 0)
                mp[log.first] = log.second;
            else if(mp[log.first] > log.second)
                mp[log.first] = log.second;
        }

        if(flag) break;
    }


    if (mp.find(0) == mp.end())
        cout << -1;
    else
        cout << mp[0];


    return 0;
}

int main(){
    int N, K;
    cin >> N >>K;
    vector<int> dp(K+1, -1);
    vector<int> items;

    for(int i=0, temp; i<N;i++){
        cin >>temp;
        items.push_back(temp);
    }

    sort(items.begin(), items.end(), desc);

    vector<int> logs= {K};

    dp[K] = 0;
    for(int item : items){
        int len = logs.size();
//        cout <<"item: " << item <<endl;
        for(int i=0 ; i<len; i++){
            int log = logs[i];
            if( log - item <0) continue;
            else if( dp[log-item] > dp[log]+1)
                dp[log-item] = dp[log]+1;
            else if( dp[log-item] == -1){
                dp[log-item] = dp[log]+1;
                logs.push_back(log-item);
            }
//            cout <<"    new log: "<< log-item << " value: "<<dp[log-item] << endl;
        }
    }

    cout <<dp[0];

    
    
    return 0;
}



