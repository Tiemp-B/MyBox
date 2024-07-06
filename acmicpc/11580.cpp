// https://www.acmicpc.net/problem/11580
// Footprint

#include <iostream>

using namespace std;

bool foot[2001][2001]={};
//E S W N
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int main(){
    int cnt =1;
    int N;
    cin >>N;
    int y = 1000;
    int x = 1000;
    foot[y][x] = true;
    for(int i=0; i<N; i++){
        char temp;
        cin >>temp;
        switch(temp){
            case 'E':
                x++;
                break;
            case 'S':
                y--;
                break;
            case 'W':
                x--;
                break;
            case 'N':
                y++;
                break;
        }
        if(!foot[y][x]){
            cnt++;
            foot[y][x]= true;
        }
    }

    cout<<cnt;
    return 0;
}