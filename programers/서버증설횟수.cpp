#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int server = 0;
    queue<int> q;
    for(int i=0; i<24; i++){
        while(q.front() == i){
            q.pop();
            server--;
        }
        int e = players[i];
        int need = e/m;
        if(need > server){
            int inc = need - server;
            answer += inc;
            server = need;
            for(int t=0; t< inc; t++) 
                q.push(i + k);
        }
    }

    return answer;
}

int sol2(vector<int> players, int m, int k){
    int answer = 0;
    
    queue<int> q;
    for(int i=0; i<players.size();i++){
        int cnt = players[i]/m;

        if(cnt > q.size()){
            answer += cnt - q.size();
            for(int j=0; j<cnt-q.size(); j++)
                q.push(k);
        }

        for(int j=0; j<q.size(); j++){
            int e = q.front()-1;
            q.pop();
            if(e>0) q.push(e);
        }
    }

}

int main(){

    return 0;
}

/*
가위바위보가 있음

스테이지에서 하루 평일:25, 주말: 50개의 가위바위보 템을 얻는다  -> 최대 900개.
NPC와 대결

NPC는 5장의 카드를 가지고 대결에 임함 다 쓰면 리필
한 기물이 나올 최대 수는 3개 -> 3개 1개 1개, 3개 2개


300개 300개 300개

20연승: 빅 보너스


*/