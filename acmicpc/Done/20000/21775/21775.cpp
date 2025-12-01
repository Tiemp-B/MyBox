#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int N, T;// N: 유저 수, T: 턴 길이

struct action_card{
    int id, action, n=-1;
};
struct player{
    int card_id=0;
};
unordered_map<int, int> loc; //{자원번호, 소유자} key: 1 ~ 2e9
// map<int, int> loc;
vector<int> turn_player;
unordered_map<int, action_card> actions; // {액션id, 액션 정보} key: 1~ 5e5
vector<player> players; //{유저 정보}
queue<int> deck;

void init(){
    cin >>N >>T;
    turn_player.resize(T);
    players.resize(N+1);
    for(int i=1; i<=T;++i){
        cin >> turn_player[i-1];
    }
    for(int i=0; i<T;++i){
        int id;
        string action;
        cin >> id >> action;
        actions[id].id = id;
        deck.push(id);
        switch (action[0])
        {
        case 'n':
            actions[id].action = 0;
            break;
        case 'a':
            actions[id].action = 1;
            cin >> actions[id].n;
            break;
        case 'r':
            actions[id].action = 2;
            cin >> actions[id].n;
            break;
        }
    }
}

void action(int pid, int aid){
    cout <<aid<<"\n";
    int n = actions[aid].n;
    int a = actions[aid].action;
    switch (a)
    {
    case 0:// next
        players[pid].card_id =0;
        break;
    case 1: // acquire
        if(loc[n] == 0){
            loc[n] = pid;
            players[pid].card_id = 0;
        }else{// 누가 가지고 있음
            players[pid].card_id = aid;
        }
        break;
    case 2: // release
        players[pid].card_id =0;
        loc[n] = 0;
        break;
    }
}

void simul(){
    for(int player : turn_player){ // T 
        if(players[player].card_id!=0){ //카드 소지시
            action(player, players[player].card_id);
        }else{// 카드 미소지시
            int now_action_card = deck.front(); deck.pop();
            action(player, now_action_card);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    simul();
    return 0;
}
