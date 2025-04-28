
    queue<pair<int, int>> q; //{s, e}
    for(int i=1;i<=N;++i){
        q.push({i,i});
        if(i!=N)
            q.push({i,i+1});
    }

    while(!q.empty()){
        auto now =q.front(); q.pop();
        int s = now.first, e=now.second;
        if(s-1<1||e+1>N) continue;
        else if(s>e) continue;
        if(mem[s][e]==0) { // 미확정 데이터 구조상 없어야 함
            q.push({s+1,e-1});
            continue;
        }
        else if(mem[s][e]==-1) continue; // 불가 데이터
        else {
            if(el[s-1]==el[e+1]){// 대칭성 확인
                mem[s-1][e+1] = 1;
                q.push({s-1,e+1});
            }else // 대칭 불가 기록
                mem[s-1][e+1] = -1;
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cout <<mem[i][j]<<" ";
        }
        cout <<endl;
    }
}
