#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int N, M;

unordered_map<string, pair<int, int>> mp; // CPTI , {owner, close} 
vector<string> list;

void func(int i){
    string str = list[i];

    // 0 diff
    if (mp.find(str) == mp.end())
        mp[str] = {1, 0};
    else{
        mp[str].first++; // owner increase
    }

    // 2 diff
    for(int i=0; i<M; i++){
        // 1 diff

        string new_str = str;

        if (new_str[i] == '0')
            new_str[i] = '1';
        else
            new_str[i] = '0';
        
        if (mp.find(new_str) != mp.end())    
            mp[new_str].second++; // 1 step closer increase
        

        // 2 diff
        for(int j=i+1; j<M; j++){
            string new_str2 = new_str;

            if (new_str2[j] == '0')
                new_str2[j] = '1';
            else
                new_str2[j] = '0';
            
            if (mp.find(new_str2) != mp.end())
                mp[new_str2].second++; // 2 step closer increase
            
        }
    }
}



int main(){
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        string temp;
        cin >>temp;
        mp[temp] = {0,0};
        list.push_back(temp);
    }

    for(int i=0; i<N; i++)
        func(i);

    int ans = 0, ans2 = 0;

    for( auto item : mp){
        auto data = item.second;
        cout << item.first <<" "<< data.first << " "<< data.second <<endl;
        ans2 += data.first * data.second; // doubled data
        ans += data.first * (data.first-1)/2;
    }
    cout <<ans + ans2/2;

    return 0;
}
