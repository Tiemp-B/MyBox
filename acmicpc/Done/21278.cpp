#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N, M;// N: 건물(<=100), M: 도로
    // 건물 2개 지정. 작은 번호가 더 작을 수록, 작은번호가 동일하다면 큰 번호가 작을 수록

    cin >>N >>M;
    vector<vector<int>> roads(N+1);

    for(int i=1; i<=M;++i){
        int a, b;
        cin >>a >>b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    int ans = 2147483647;
    pair<int, int> ans_pos;
    
    for(int p1=1; p1<=N-1; ++p1){
        for(int p2=p1+1; p2<=N; ++p2){
            queue<int> q;
            q.push(p1);
            q.push(p2);
            vector<bool> onQ(N+1, false);
            vector<int> far(N+1, 2147483647);
            far[0] = 0;
            far[p1] = 0;
            far[p2] = 0;
            while(!q.empty()){ // 40ms 최저는 0ms. 나는 BFS를 했으나 최소 시간은 DP를 사용하여 모든 포인트간 최소 거리를 기록함.
                int n = q.front();
                q.pop();
                onQ[n] = false;
                for(auto target : roads[n]){
                    if(far[target] > far[n] + 1){
                        far[target] = far[n] + 1;
                        if(!onQ[target]){
                            onQ[target] = true;
                            q.push(target);
                        }
                    }
                }
            }
            int temp_sum = 0;
            for(auto e : far)
                temp_sum += e;
            
            if(ans>temp_sum){
                ans = temp_sum;
                ans_pos = {p1, p2};
            }
        }
    }
    
    printf("%d %d %d", ans_pos.first, ans_pos.second, ans*2);

    return 0;
}