// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <ctime>
#include <random>
#include <chrono>

using namespace std;

#define SEG_MIN -100000000

// 금광 세그 문제

//http://colorscripter.com/s/aNT178n
/*---변수 선언---*/
struct seg_item
{
    int total; // 구간합
    int mid;   // 최대 부분합
    int left;  // 가장 왼쪽의 수를 포함하는 최대 부분합
    int right; // 가장 우측의 수를 포함하는 최대 부분합
    seg_item() : total(0), left(SEG_MIN), right(SEG_MIN), mid(SEG_MIN) {}
    seg_item(int d) : total(d), left(d), right(d), mid(d) {}
    seg_item(int t, int l, int r, int m) : total(t), left(l), right(r), mid(m) {}
};

int N;
vector<seg_item> seg(400000, seg_item());
int items[100001] ={};

/*---함수 선언---*/
// 세그먼트 트리에 삽입하는 코드
seg_item seg_push(pair<int, int> panel, int idx, int target, int value);
// 세그먼트 트리에서 데이터를 가져오는 코드
seg_item seg_get(int a, int b, int idx, int s, int e);
// 세그먼트 트리 업데이트
seg_item seg_update(int idx, int s, int e);
// 수열 입력
void init();
// 쿼리 입력
void query();
// 랜덤한 n개의 수열과 랜덤 범위의 100000개 쿼리 질의. print 로 결과 출력 가능
void tester(int n, bool print);

void test_init(){
    N = 100000;
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(-1000, 1000);
    for (int i = 1, temp; i <= N; i++)
    {
        items[i] = dist(gen);
        // seg_push({1, N}, 1, i, nodes[i]);
    }
    seg_update(1, 1, N);
}

void test_query(){
    for(int i=1; i < N; i++){
        int out = seg_get(i, i+1, 1, 1, N).mid;
        int ans = max(items[i]+items[i+1], max(items[i], items[i+1]));
        if(out != ans)
            cout << "err!"<<endl;
    }
    cout <<"done";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // init();
    // query();
    test_init();
    test_query();
    // for (int i = 100000; i <= 100000; i++)
    // {
    //     if (i % 10000 == 0)
    //         cout << "pop" << endl;
    //     tester(i, true);
    // }
    // tester(100000, true);
    return 0;
}

seg_item seg_push(pair<int, int> panel, int idx, int target, int value)
{ // panel: 현재 구간, idx: seg배열 idx, target: 목표 위치, value: 값
    if (panel.first == panel.second && panel.first == target)
    {
        // cout << "pop1 "<< idx << " " << panel.first << " "<<panel.second<<endl;
        return seg[idx] = {value, value, value, value};
    }
    if (panel.first > target || panel.second < target)
        return seg[idx];

    int avg = (panel.first + panel.second) / 2;
    seg_item left = seg_push({panel.first, avg}, idx * 2, target, value);
    seg_item right = seg_push({avg + 1, panel.second}, idx * 2 + 1, target, value);

    seg[idx].left = max(left.left, left.total + right.left);
    seg[idx].right = max(right.right, right.total + left.right);
    seg[idx].mid = max(left.right + right.left, max(left.mid, right.mid));
    seg[idx].total = left.total + right.total;

    return seg[idx];
}

seg_item seg_update(int idx, int s, int e){
    if(s == e)
        return seg[idx] = seg_item(items[s]);
    
    int mid = (s+e)/2;
    seg_item left = seg_update(idx*2, s, mid);
    seg_item right = seg_update(idx*2+1, mid+1, e);
    
    seg[idx].left = max(left.left, left.total + right.total);
    seg[idx].right = max(right.right, right.total + left.right);
    seg[idx].mid = max(left.right+right.left, max(left.mid, right.mid));
    seg[idx].total = left.total + right.total;

    return seg[idx];
}

seg_item seg_get(int a, int b, int idx, int s, int e)
{ // a,b : 목표 범위, s, e: 구간 범위
    if (b < s || a > e)
        return seg_item(0, SEG_MIN, SEG_MIN, SEG_MIN);
    if (s == a && b == e)
    {
        return seg[idx];
    }
    int avg = (s + e) / 2;
    seg_item left_child = seg_get(a, (avg < b) ? avg : b, idx * 2, s, avg);
    seg_item right_child = seg_get((avg + 1 > a) ? avg + 1 : a, b, idx * 2 + 1, avg + 1, e);

    seg_item ans;
    ans.left = max(left_child.left, left_child.total + right_child.left);                     // 최 좌측을 보유한 구간 중 최대
    ans.right = max(left_child.right + right_child.total, right_child.right);                 // 최 우측을 보유한 구간 중 최대
    ans.mid = max(left_child.right + right_child.left, max(right_child.mid, left_child.mid)); // 중간 지역 최대
    ans.total = left_child.total + right_child.total;

    return ans;
}

void init()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> items[i];
        // seg_push({1, N}, 1, i, temp);
    }
    seg_update(1, 1, N);

}

void query()
{
    int Q;
    cin >> Q;
    vector<pair<int, int>> q;

    for (int i = 0, a, b; i < Q; i++)
    {
        cin >> a >> b;
        auto out = seg_get(a, b, 1, 1, N);
        cout << out.mid << endl;
    }
}

void tester(int n, bool print)
{// n: 수열의 길이. print: 걸린 시간 출력 및 중간 결과 출력
    int l = 5; // 검증 부분의 부분 수열 길이

    N = n;
    clock_t stt, fin, cen;
    stt = clock();

    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(-1000, 1000);
    if (print) cout << "push start"<<endl;
    for (int i = 1, temp; i <= N; i++)
    {
        items[i] = dist(gen);
        // seg_push({1, N}, 1, i, nodes[i]);
    }
    seg_update(1, 1, N);
    cen = clock();
    double m = (double)(cen - stt) / CLOCKS_PER_SEC;
    if(!print){
        for(int i=1, c=2; c!=N*4; i++){
            if(i == c){
                cout << endl;
                c *=2;
            }
            printf("|%d %d %d %d|", seg[i].total, seg[i].left, seg[i].right, seg[i].mid);
        }
    }

    if (print) cout << "push done " << m * 1000 << " ms" << endl;

    int Q = 100000;
    vector<int> ans; // 출력 벡터
    for (int i = 0; i < Q; i++)
    {
        uniform_int_distribution<int> dist1(1, N);
        int s = dist1(gen);
        uniform_int_distribution<int> dist2(s, N);
        int e = dist1(gen);
        seg_item tt = seg_get(s, e, 1, 1, N);
        ans.push_back(tt.mid);
    }
    if (print)
        cout <<"query out count :" << ans.size() << endl;
    fin = clock();
    double m2 = (double)(fin - cen) / CLOCKS_PER_SEC;
    double du = (double)(fin - stt) / CLOCKS_PER_SEC;
    if (print) cout << "query done : " << m2 * 1000 << " ms" << endl;
    if (print) cout << "duration : " << du * 1000 << " ms" << endl;

    if (print)
        cout << "--qualifying--" << endl;

    for (int i = 1; i <= N - l && print; i++)
    {
        int out = seg_get(i, i + l - 1, 1, 1, N).mid;
        if (i % 10000 == 0 )
        {
            cout << i << " : ";
            for (int t = 0; t < l; t++)
            {
                cout << items[i + t] << " ";
            }
            cout << "=> " << out << endl;
        }
        // if(temp != out)
        //     cout <<"err!"<<endl;
    }
}
