#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


struct soldier{
    int mID;
    int mTeam;

    int prevID;
    int nextID;

};

soldier *sol_list = NULL;

int **head =NULL;//팀별 점수 첫병사 배열
int **tail =NULL;//팀별 마지막 병사

void init(){
    if(sol_list) delete sol_list;
    if(head){
        for(int i=0; i<6; i++){
            if(head[i]) delete head[i];
            if(tail[i]) delete tail[i];
        }
    }
    
    sol_list = new soldier[100001];
    head = new int*[6];
    tail = new int*[6];
    for(int i=0; i<6;i++){
        head[i] = new int{-1};
        tail[i] = new int{-1};
    }
}

void hire(int mID, int mTeam, int mScore){
    if(head[mTeam][mScore] <= 0){// 아무도 없음
        head[mTeam][mScore] = mID;
        tail[mTeam][mScore] = mID; 
        sol_list[mID] = {mID, mTeam, -1, -1};
    }
    else{//있음
        sol_list[mID] = {mID, mTeam, -1, head[mTeam][mScore]};
        sol_list[head[mTeam][mScore]].prevID = mID;
        head[mTeam][mScore] = mID;
    }
}

void fire(int mID){
    int pv = sol_list[mID].prevID;
    int nx = sol_list[mID].nextID;
    if(pv>0) sol_list[pv].nextID = nx;
    if(nx>0) sol_list[nx].prevID = pv;

    for(int i=1; i<6; i++){
        if(head[sol_list[mID].mTeam][i] == mID){
            head[sol_list[mID].mTeam][i] = nx;
        }
    }

    sol_list[mID] = {-1, -1, -1, -1};
}

void updateSoldier(int mID, int mScore){
    int pv = sol_list[mID].prevID;
    int nx = sol_list[mID].nextID;
    if(pv>0) sol_list[pv].nextID = nx;
    if(nx>0) sol_list[nx].prevID = pv;
    
    for(int i=1; i<6; i++){// head, tail일 경우 변경
        if(head[sol_list[mID].mTeam][i] == mID){
            head[sol_list[mID].mTeam][i] = nx;
        }
        if(tail[sol_list[mID].mTeam][i] == mID){
            tail[sol_list[mID].mTeam][i] =pv;
        }
    }

    if(head[sol_list[mID].mTeam][mScore] <= 0){// 아무도 없음
        head[sol_list[mID].mTeam][mScore] = mID;
        tail[sol_list[mID].mTeam][mScore] = mID;
        sol_list[mID].prevID = -1;
        sol_list[mID].nextID = -1;
    }
    else{//있음
        sol_list[mID].prevID = -1;
        sol_list[mID].nextID = head[sol_list[mID].mTeam][mScore];
        sol_list[sol_list[mID].mTeam].prevID = mID;
        head[sol_list[mID].mTeam][mScore] = mID;
    }

}

void updateTeam(int mTeam, int mChangeScore){
    int temp_head[6]={-1,-1,-1,-1,-1,-1};
    int temp_tail[6]={-1,-1,-1,-1,-1,-1};
    for(int i=1; i<6; i++){
        int new_score = i+mChangeScore;
        if(new_score <1) new_score = 1;
        else if(new_score > 5 ) new_score = 5;

        if(temp_head[new_score]<=0){ //temp의 newscore가 비어있음?
            temp_head[new_score] = head[mTeam][i];
            temp_tail[new_score] = tail[mTeam][i];
        }else{
            sol_list[temp_head[new_score]].prevID = tail[mTeam][i];//newscore 선두가 i점의 마지막 친구를 이전으로
            sol_list[tail[mTeam][i]].nextID = temp_head[new_score];//i점의 마지막 친구가 newscore 선두를 가르키게
            temp_head[new_score] = head[mTeam][i];//newscore의 첫 친구는 i점의 첫 친구로
        }
    }

    for(int i=1; i<6; i++){
        head[mTeam][i] = temp_head[i];
        tail[mTeam][i] = temp_tail[i];
    }

}

int bestSoldier(int mTeam){
    int ans=0;
    for(int i=5; i>0 ;--i){
        int idx = head[mTeam][i];
        if(idx <=0) continue;
        while(idx > 0){
            if(ans < sol_list[idx].mID) ans = sol_list[idx].mID;
            idx = sol_list[idx].nextID;
        }
        break;
    }
    return ans;
}
