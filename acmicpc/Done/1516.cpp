#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct bd
{
    int cond = 0;
    vector<int> sub;
    int readytime = 0;
    int bdTime = 0;
    int doneTime = -1;
};
bd buildings[501];

int calcCnt = 0;
/**/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) //------------------- 상수시간
    {
        int temp = 0;
        cin >> buildings[i].bdTime;
        while (true)
        {
            cin >> temp;
            if (temp == -1) break;
            buildings[temp].sub.push_back(i);
            buildings[i].cond++;
        }
    }
    
    queue<int> tray;
    for (int i = 1; i <= N; i++) //--------------------------- O(N)
    {
        if (buildings[i].cond == 0){
            tray.push(i);
            buildings[i].doneTime = buildings[i].bdTime;
        }
    }

    while (!tray.empty())
    {
        int f = tray.front();
        tray.pop();
        for(int i= 0; i< buildings[f].sub.size(); i++){ 
            int temp = buildings[f].doneTime+buildings[buildings[f].sub[i]].bdTime;
            if(buildings[buildings[f].sub[i]].doneTime < temp) buildings[buildings[f].sub[i]].doneTime = temp;
            if(--buildings[buildings[f].sub[i]].cond == 0) tray.push(buildings[f].sub[i]);
        }
    }

    for(int i=1;i<=N;i++){
        cout<<buildings[i].doneTime<<endl;
    }
    return 0;
}
/**/

/* 내 코드는 16ms가 나왔음

다른 사람의 4ms 코드를 분석한 것을 아래에 기록하겠다. 
    if(buildings[buildings[f].sub[i]].doneTime < temp) buildings[buildings[f].sub[i]].doneTime = temp; 

    int next = vec[now][i];
    result[next] = max(result[next], result[now] + cost[next]);
* /
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> vec(n);
    vector<int> cost(n);
    vector<int> arr(n,0);
    for(int i = 0;i<n;++i){   // ------------------------- 상수시간
        cin>>cost[i];
        int num = 0;
        while(true){
            calcCnt++;
            cin>>num;
            if(num == -1) break;
            vec[num-1].push_back(i);
            arr[i]++;
        }
    }
    cout<<"mid1 : "<<calcCnt<<endl;
    vector<int> result(n,0);
    queue<int> myqueue;
    for(int i = 0;i<n;++i){
        calcCnt++;
        if(arr[i] == 0){
            myqueue.push(i);
            result[i] = cost[i];
        }
    }
    cout<<"mid2 : "<<calcCnt<<endl;
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();
        for(int i = 0;i<vec[now].size();++i){
            calcCnt++;
            int next = vec[now][i];
            //건물 여러개가 완공되고 나서 짓기 시작해야할 경우
            //가장 시간이 긴 건물을 기준으로 시간을 누적시키면 된다.
            result[next] = max(result[next], result[now] + cost[next]);
            --arr[next];
            if(arr[next] == 0){
                myqueue.push(next);
            }
        }
    }
    for(int i = 0;i<result.size();++i){
        cout<<result[i]<<"\n";
    }
    cout<<"calcCnt: "<< calcCnt;
}

/**/