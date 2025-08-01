#include <unordered_map>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*
개빡셈. 
사소한 시간 복잡도 계산 필요.
string의 복사 경우 길이만큼의 시간복잡도를 가짐.
그러니 구조를 잘 짜야 함. 
*/

struct team_data{
    int score = 0;
    int high_rank  = 20;
    int low_rank   =  1;
    team_data() = default;
};
vector<pair<string, string>> left_games;
unordered_map<string, int> dict;
unordered_map<int, team_data> mp;


void DFS(int idx){
    if(idx == left_games.size()){
        vector<pair<int, string>> v(mp.size());
        int i =0;
        for(auto &e: mp){
            v[i].first = e.second.score;
            v[i].second = e.first;
        }
        sort(v.begin(), v.end()); // O(n*logn)
        int rank = 0;
        int mx = 10000;
        int dump = 0;
        for(int i=v.size()-1; i>=0;--i){
            if(mx > v[i].first){
                rank += 1 +dump;
                mx = v[i].first;
                dump =0;
            }
            else
                dump++;
            if(mp[v[i].second].high_rank > rank)
                mp[v[i].second].high_rank = rank;
            if(mp[v[i].second].low_rank < rank)
                mp[v[i].second].low_rank = rank;
        }
        return;
    }
    string &A = left_games[idx].first;
    string &B = left_games[idx].second;
    // A팀 승
    mp[A].score += 3;
    DFS(idx+1);
    mp[A].score -= 3;
    // B팀 승
    mp[B].score += 3;
    DFS(idx+1);
    mp[B].score -= 3;
    // 무승부
    mp[A].score += 1;
    mp[B].score += 1;
    DFS(idx+1);
    mp[A].score -= 1;
    mp[B].score -= 1;
}

void init(int n, int m){
    if(!left_games.empty()) left_games.clear();
    if(!mp.empty()) mp.clear();
    vector<string> order(n);
    for(int i=0; i<n;++i){
        char team[31];
        scanf("%s", team);
        string tmp(team);
        dict[string(team)] = i;
        order[i] = string(team);
        mp[order[i]]=team_data();
    }

    for(int i=0;i<m;++i){
        int s1, s2;
        char team1[31], team2[31];
        scanf("%s %*s %s %d %d",team1, team2, &s1, &s2);
        string team1_s(team1), team2_s(team2);
        team2_s.pop_back();
        if(s1==-1){// yet
            left_games.push_back({team1_s, team2_s});
        }else if(s1 < s2){
            mp[team2_s].score += 3;
        }else if(s1 > s2){
            mp[team1_s].score += 3;
        }else{
            mp[team1_s].score += 1;
            mp[team2_s].score += 1;
        }
    }
    DFS(0);
    // 출력부
    for(auto nam : order){
        string high_th="th", low_th="th";
        switch(mp[nam].high_rank%10){
            case 1:
                high_th = "st";
                break;
            case 2:
                high_th = "nd";
                break;
            case 3:
                high_th = "rd";
                break;
        }
        switch(mp[nam].low_rank%10){
            case 1:
                low_th = "st";
                break;
            case 2:
                low_th = "nd";
                break;
            case 3:
                low_th = "rd";
                break;
        }
        printf("Team %s can finish as high as %d%s place and as low as %d%s place.\n", nam.c_str(), mp[nam].high_rank, high_th.c_str(), mp[nam].low_rank, low_th.c_str());
    }
}

int main(){
    int n, m;
    while(true){
        scanf("%d %d", &n, &m);
        if(n==0) break;
        init(n, m);
        printf("\n");
    }

}

/*
3 7
A 
B
C
A vs B: 1 3
A vs B: 1 3
A vs C: 1 3
A vs C: 3 1
A vs C: -1 -1
A vs C: -1 -1
A vs C: -1 -1


Team A can finish as high as 1st place and as low as 3rd place.
Team B can finish as high as 1st place and as low as 3rd place.
Team C can finish as high as 1st place and as low as 3rd place.
*/