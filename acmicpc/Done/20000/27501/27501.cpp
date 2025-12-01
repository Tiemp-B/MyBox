#include <iostream>
#include <vector> 
#include <queue>

#define UNDEBUG

using namespace std;

int N;
vector<vector<int>> mem;
vector<vector<int>> connection;
vector<vector<int>> score;
vector<int> parent; // 부모 노드
vector<vector<int>> children;
vector<int> order;
queue<int> q; // BFS 용 큐


void init(){
    cin >>N;
    mem.resize(N+1, vector<int>(3, 0)); // 3N 4
    score.resize(N+1, vector<int>(3,0)); // 3N 4
    children.resize(N+1);
    connection.resize(N+1); // N 4
    parent.resize(N+1, 0);

    for(int i=1,a,b;i<N;++i){ // N-1 개; O(N)
        cin >>a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }

    for(int i=1;i<=N;++i) // 색상별 점수 받기
        cin >> score[i][0] >> score[i][1] >> score[i][2];
}

void calc(){
    // BFS 트리 순회 경로 설정. order: 경로 배열, 루트: 1. 
    // 루트에서 한 단계씩 아래로 내려가는 구조
    q.push(1);
    parent[1] = 1;
    while(!q.empty()){
        int now = q.front(); q.pop();
        order.push_back(now);               // 현 노드 order에 등록
        for(int e : connection[now]){       // 모든 연결된 노드에 대하여
            if(parent[e] != 0) continue;    // 부모가 설정된 노드 제외 (방문 노드는 부모 노드임)
            children[now].push_back(e);     // 현 노드의 자식으로 연결 노드 등록
            parent[e] = now;                // 연결 노드들의 부모로 현 노드 등록
            q.push(e);                     
        }
    }

    // order의 뒷 순서부터 (즉, 자식 노드가 없는 항목부터)
    // mem[now][now_color] = SUM(max(mem[child][child_color != now_color]))
    for(int i=order.size()-1; i>=0; --i){
        int now = order[i];
        for(int now_color=0; now_color<3; ++now_color){             // 현재 노드의 색
            int sum_child = 0;
            for(int child : children[now]){                         // 자식 노드
                int mx = 0; 
                for(int child_color=0; child_color<3;++child_color){
                    if(now_color == child_color) continue;          // child_color != now_color
                    if(mx < mem[child][child_color])
                        mx = mem[child][child_color];               // 조건에 부합하며 가장 큰 가치를 지니는 색
                }
                sum_child += mx;
            }

            mem[now][now_color] = score[now][now_color] + sum_child;
        }
    }

    vector<int> ans(N+1); // 정답 색 배열
    ans[1] = 0;

    if(mem[1][ans[1]]< mem[1][1]) ans[1] = 1;
    if(mem[1][ans[1]]< mem[1][2]) ans[1] = 2;
    
    // order를 순서대로 따라가며 색 지정
    // ans[now] = select_max_idx( mem[now][!ans[parent[now]]] )
    for(int i=1 ; i<N; ++i){
        int mx = 0, now = order[i];
        for(int color=0; color<3; ++color){             // 부모의 정답 색과 다른 색 중 최고 가치 색을 정답 색으로 지정
            if(ans[parent[now]] == color) continue;    
            if(mx < mem[now][color]){ 
                mx = mem[now][color];
                ans[now] = color;
            }
        }
    }
    
    char c[3]= {'R', 'G', 'B'};
    cout << mem[1][ans[1]]<<endl;

    for(int i=1; i<=N;++i){
        cout << c[ans[i]];
    }

}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    init();
    calc();
    return 0;
}

/*
교훈. cin과 scanf를 혼용하면 백준에선 오작동한다.
이 코드 기록 : 111924kb, 800ms


백준 최고 기록: 46396kb, 384ms

*/