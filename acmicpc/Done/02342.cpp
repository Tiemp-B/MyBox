#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int INF = 400001;
int pow[5][5]={
    {0, 2, 2, 2, 2}, // 0 ->
    {0, 1, 3, 4, 3}, //1 ->
    {0, 3, 1, 3, 4}, // 2 ->
    {0, 4, 3, 1, 3}, // 3 ->
    {0, 3, 4, 3, 1}// 4->
};

struct node{
    int mem[5][5];
    node(){
        for(int i=0;i<5;++i) for(int j=0;j<5;++j) mem[i][j] = INF;
    }
};

void method1(){ // 실시간 할당 -> 24ms
    vector<node> v={node()};
    v.back().mem[0][0] = 0;
    int nex=-1;
    while(cin>>nex && nex!=0){
        node next_node = node();
        // l move
        for(int l=0; l<5;++l){
            for(int r=0; r<5;++r){
                if(l==r&&(l!=0)) continue;
                if(v.back().mem[l][r]==INF) continue;
                if(nex!=r) // 좌족을 nex로
                    next_node.mem[nex][r] = min(v.back().mem[l][r] + pow[l][nex], next_node.mem[nex][r]);
                if(nex!=l) // 우족을 nex로
                    next_node.mem[l][nex] =  min(v.back().mem[l][r] + pow[r][nex], next_node.mem[l][nex]);
            }
        }
        v.push_back(next_node);
    }

    int ans = INF;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            if(ans > v.back().mem[i][j]) ans = v.back().mem[i][j];
        }
    }
    cout << ans;
}

void method2(){ // 사전 공간 할당 16ms
    vector<node> v(100001);
    v[0].mem[0][0] = 0;
    int nex=-1, turn = 0;
    while(cin>>nex && nex!=0){
        ++turn;
        for(int l=0; l<5;++l){
            for(int r=0; r<5;++r){
                if(l==r&&(l!=0)) continue;
                if(v[turn-1].mem[l][r]==INF) continue;
                if(nex!=r) // 좌족을 nex로
                    v[turn].mem[nex][r] = min(v[turn-1].mem[l][r] + pow[l][nex], v[turn].mem[nex][r]);
                if(nex!=l) // 우족을 nex로
                    v[turn].mem[l][nex] =  min(v[turn-1].mem[l][r] + pow[r][nex], v[turn].mem[l][nex]);
            }
        }
    }
    int ans = INF;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            if(ans > v[turn].mem[i][j]) ans = v[turn].mem[i][j];
        }
    }
    cout << ans;
}

void method3(){ // 이전 항목까지만 저장, 최신화. 12ms
    node prev = node();
    prev.mem[0][0]=0;
    node next = node();
    int nex=-1;
    while(cin>>nex && nex!=0){
        node next_node = next;
        // l move
        for(int l=0; l<5;++l){
            for(int r=0; r<5;++r){
                if(l==r&&(l!=0)) continue;
                if(prev.mem[l][r]==INF) continue; //INF면 불가능한 경우
                if(nex!=r) // 좌족을 nex로
                    next_node.mem[nex][r] = min(prev.mem[l][r] + pow[l][nex], next_node.mem[nex][r]);
                if(nex!=l) // 우족을 nex로
                    next_node.mem[l][nex] =  min(prev.mem[l][r] + pow[r][nex], next_node.mem[l][nex]);
            }
        }
        prev = next_node;
    }

    int ans = INF;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            if(ans > prev.mem[i][j]) ans = prev.mem[i][j];
        }
    }
    cout << ans;
}

void method4(){ // 사전 공간 할당 112ms. if문이 많아짐에 따라 복잡도가 상승한 것으로 추정
    vector<vector<vector<int>>> v(100001, vector<vector<int>>(5, vector<int>(5,0)));
    // int  v[100001][5][5]={};
    vector<vector<vector<bool>>> b(100001, vector<vector<bool>>(5, vector<bool>(5,false)));
    b[0][0][0]=true;

    int nex=-1, turn = 0;
    while(cin>>nex && nex!=0){
        ++turn;
        for(int l=0; l<5;++l){
            for(int r=0; r<5;++r){
                if(l==r&&(l!=0)) continue;
                if(!b[turn-1][l][r]) continue;
                if(nex!=r){ // 좌족을 nex로
                    if(b[turn][nex][r])
                        v[turn][nex][r] = min(v[turn-1][l][r] + pow[l][nex], v[turn][nex][r]);
                    else{
                        v[turn][nex][r] = v[turn-1][l][r] + pow[l][nex];
                        b[turn][nex][r] = true;
                    }
                }
                if(nex!=l){ // 우족을 nex로
                    if(b[turn][l][nex])
                        v[turn][l][nex] =  min(v[turn-1][l][r] + pow[r][nex], v[turn][l][nex]);
                    else{
                        v[turn][l][nex] = v[turn-1][l][r] + pow[r][nex];
                        b[turn][l][nex] = true;
                    }
                }
            }
        }

        // cout <<"-----\n";
        // for(int i=0;i<5;++i){
        //     for(int j=0;j<5;++j){
        //         if(!b[turn][i][j])cout <<"INF ";
        //         else cout <<v[turn][i][j]<<" ";
        //     }
        //     cout <<endl;
        // }
    }
    int ans = INF;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            if(!b[turn][i][j]) continue;
            if(ans > v[turn][i][j]) ans = v[turn][i][j];
        }
    }
    cout << ans;
}

void method1_2(){ // 실시간 할당 emplace_back으로 변경 -> 24ms : 속도 영향 없음
    vector<node> v={node()};
    v.back().mem[0][0] = 0;
    int nex=-1;
    while(cin>>nex && nex!=0){
        node next_node = node();
        // l move
        for(int l=0; l<5;++l){
            for(int r=0; r<5;++r){
                if(l==r&&(l!=0)) continue;
                if(v.back().mem[l][r]==INF) continue;
                if(nex!=r) // 좌족을 nex로
                    next_node.mem[nex][r] = min(v.back().mem[l][r] + pow[l][nex], next_node.mem[nex][r]);
                if(nex!=l) // 우족을 nex로
                    next_node.mem[l][nex] =  min(v.back().mem[l][r] + pow[r][nex], next_node.mem[l][nex]);
            }
        }
        v.emplace_back(next_node);
    }

    int ans = INF;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            if(ans > v.back().mem[i][j]) ans = v.back().mem[i][j];
        }
    }
    cout << ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    method1_2();
    return 0;
}