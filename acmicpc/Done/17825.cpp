#include <iostream>
#include <vector>

using namespace std;

struct spot{
    int score;
    int horse=0;
    bool color=true; // true: red
    spot* red_direction;
    spot* blue_direction; 
    spot(int s,spot* red_d=NULL, bool c=true, spot* blud_d=NULL){
        score = s;
        color = c;
        red_direction = red_d;
        blue_direction = blud_d;
    }
};

struct piece{
    vector<spot*> locate;
};

int dice[10];
int ans =0;

piece pieces[4];
spot *start_point;
spot *end_point = new spot(0);

void init(){
    for(int i=0;i<10;++i) cin >>dice[i];
    spot* point_40 = new spot(40, end_point);
    
    // 40 -> 30
    spot* temp2= new spot(38, point_40);
    temp2 = new spot(36, temp2);
    temp2 = new spot(34, temp2);
    temp2 = new spot(32, temp2);

    // 40 -> 25
    spot* temp = new spot(35, point_40);
    temp = new spot(30, temp);
    spot* center = new spot(25, temp);

    // 중앙 -> 30
    temp = new spot(26, center);
    temp = new spot(27, temp);
    temp = new spot(28, temp);
    spot* point_30 = new spot(30, temp2, false, temp);

    // 중앙 -> 20
    temp = new spot(24, center);
    temp = new spot(22, temp);
    
    // 30 -> 20
    temp2 = new spot(28, point_30);
    temp2 = new spot(26, temp2);
    temp2 = new spot(24, temp2);
    temp2 = new spot(22, temp2);
    spot* point_20 = new spot(20, temp2, false, temp);

    // 중앙 -> 10
    temp = new spot(19, center);
    temp = new spot(16, temp);
    temp = new spot(13, temp);

    // 20 -> 10
    temp2 = new spot(18, point_20);
    temp2 = new spot(16, temp2);
    temp2 = new spot(14, temp2);
    temp2 = new spot(12, temp2);
    spot* point_10 = new spot(10, temp2, false, temp);

    temp = new spot(8, point_10);
    temp = new spot(6, temp);
    temp = new spot(4, temp);
    temp = new spot(2, temp);
    start_point = new spot(0, temp);
    start_point->horse = 4;

    for(int i=0;i<4;++i)
        pieces[i].locate.push_back(start_point);
}

bool flag = true;

void recur(int turn, int score){
    if(turn == 10){
        if(ans < score) ans = score;
        if(ans == 245 && flag){
            flag = false;
            cout <<"------------\n";
            for(int p=0; p<4;++p){
                cout << p<<" : ";
                for(auto e : pieces[p].locate){
                    cout <<e->score<<" ";
                }
                cout <<endl;
            }
        }
        return;
    }
    int end_piece=0;
    for(int p=0; p<4;++p){
        if(pieces[p].locate.back() == end_point) {
            end_piece++;
            continue; // 도착점
        }
        int move = dice[turn];
        spot* now = pieces[p].locate.back();

        if(now->color)//red
            now = now->red_direction;
        else // blue
            now = now->blue_direction;
        move--;

        while(move>0){
            move--;
            if(now==end_point) break;
            now = now->red_direction;
        }

        if(now->horse > 0 && now!=end_point) continue; // 도착점이 아니며 해당 위치에 말이 있음

        pieces[p].locate.back()->horse--;
        now->horse++;
        pieces[p].locate.push_back(now);
        recur(turn+1, score+now->score);
        pieces[p].locate.pop_back();
        now->horse--;
        pieces[p].locate.back()->horse++;
    }
    if(end_piece == 4)
        if(ans < score) ans = score;
}


int main(){
    init();
    recur(0,0);

    cout << ans;
    return 0;
}