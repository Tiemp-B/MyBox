#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

#ifdef __has_include
#if __has_include("local_header.h")
#define HEADER_EXISTS 1
#else
#define HEADER_EXISTS 0
#endif
#else
#define HEADER_EXISTS 0
#endif

using namespace std;

vector<vector<vector<int>>> dict = {
    {{0}},
    {{1}},
    {{1, 1}, {2}},
    {{1, 1, 1}, {3}},
    {{2, 2}, {4}},
    {{5}},
    {{2, 2, 2}, {3, 3}, {6}},
    {{7}},
    {{4, 4}, {8}},
    {{3, 3, 3}, {9}},
    {{5, 5}, {10}}};

vector<vector<int>> dict2 = {
    {0},
    {1},
    {1, 2},
    {1, 3},
    {1, 2},
    {1},
    {1, 2, 3},
    {1},
    {1, 2},
    {1, 3},
    {1, 2}};

long long int ans = 0;
int N, R, G, B;
vector<int> factList = {1, 1, 2};

long long int fact(int f)
{
    if (factList.size() > f)
        return factList[f];
    else
    {
        for (; factList.size() < f + 2;)
        {
            factList.push_back(factList.back() * (factList.size()));
        }

        return factList[f];
    }
}

long long int coeff(int n, int k) // k종류가 n개씩
{
    long long int under = 1;
    for (int i = 0; i < k; i++)
    {
        under *= fact(n);
    }
    long long int ans = fact(k * n) / under;
    // printf("n: %d, k: %d => %d\n",n ,k, ans);
    return ans;
}

long long int calc1(int lv, int r, int g, int b)
{
    // printf("lv: %d, r: %d, g: %d, b: %d\n", lv, r, g, b);
    long long int cnt = 0;

    for (int i = 0; i < dict[lv].size(); i++)
    {
        if (dict[lv][i].size() == 1)
        {
            int used = dict[lv][i][0];
            if (lv == N)
            {
                if (r >= used)
                    cnt += coeff(used, 1);
                if (g >= used)
                    cnt += coeff(used, 1);
                if (b >= used)
                    cnt += coeff(used, 1);
            }
            else
            {
                if (r >= used)
                    cnt += coeff(used, 1) * calc1(lv + 1, r - used, g, b);
                if (g >= used)
                    cnt += coeff(used, 1) * calc1(lv + 1, r, g - used, b);
                if (b >= used)
                    cnt += coeff(used, 1) * calc1(lv + 1, r, g, b - used);
            }
        }
        else if (dict[lv][i].size() == 2)
        {
            int used = dict[lv][i][0];
            if (lv == N)
            {
                if (r >= used && g >= used)
                    cnt += coeff(used, 2);
                if (g >= used && b >= used)
                    cnt += coeff(used, 2);
                if (b >= used && r >= used)
                    cnt += coeff(used, 2);
            }
            else
            {
                if (r >= used && g >= used)
                    cnt += coeff(used, 2) * calc1(lv + 1, r - used, g - used, b);
                if (g >= used && b >= used)
                    cnt += coeff(used, 2) * calc1(lv + 1, r, g - used, b - used);
                if (b >= used && r >= used)
                    cnt += coeff(used, 2) * calc1(lv + 1, r - used, g, b - used);
            }
        }
        else if (dict[lv][i].size() == 3)
        {
            int used = dict[lv][i][0];
            if (lv == N)
            {
                if (r >= used && g >= used && b >= used)
                    cnt += coeff(used, 3);
            }
            else
            {
                if (r >= used && g >= used && b >= used)
                    cnt += coeff(used, 3) * calc1(lv + 1, r - used, g - used, b - used);
            }
        }
    }
    return cnt;
}

long long int mem[11][56][56][56] = {}; // lv r, g, b
bool flags[11][56][56][56] = {false};

struct cmp {
    bool operator()(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
};

long long int calc2(int lv, int r, int g, int b)
{
    long long int ans = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    // queue<vector<int>> q;
    if (R > 0)
    {
        mem[1][1][0][0] = 1;
        q.push({1, 1, 0, 0});
    }
    if (G > 0)
    {
        mem[1][0][1][0] = 1;
        q.push({1, 0, 1, 0});
    }
    if (B > 0)
    {
        mem[1][0][0][1] = 1;
        q.push({1, 0, 0, 1});
    }

    while (!q.empty())
    {
        auto top = q.top();
        q.pop();
        int top_lv = top[0], top_r = top[1], top_g = top[2], top_b = top[3];
        if (top_lv == N) {
            continue;
        }
        if(flags[top_lv][top_r][top_g][top_b])
            continue;
        flags[top_lv][top_r][top_g][top_b] = true;
        for (int var : dict2[top_lv + 1])
        {
            int cnt = (top_lv + 1 )/ var;
            if (var == 1)
            {
                if (top_r + cnt <= R)
                {
                    mem[top_lv + 1][top_r + cnt][top_g][top_b] += mem[top_lv][top_r][top_g][top_b];
                    q.push({top_lv + 1, top_r + cnt, top_g, top_b});
                }
                if (top_g + cnt <= G)
                {
                    mem[top_lv + 1][top_r][top_g + cnt][top_b] += mem[top_lv][top_r][top_g][top_b];
                    q.push({top_lv + 1, top_r, top_g + cnt, top_b});
                }
                if (top_b + cnt <= B)
                {
                    mem[top_lv + 1][top_r][top_g][top_b + cnt] += mem[top_lv][top_r][top_g][top_b];
                    q.push({top_lv + 1, top_r, top_g, top_b + cnt});
                }
            }
            else if (var == 2)
            {
                if (top_r + cnt <= R && top_g + cnt <= G)
                {
                    mem[top_lv + 1][top_r + cnt][top_g + cnt][top_b] += coeff(cnt, var) * mem[top_lv][top_r][top_g][top_b];
                    q.push({top_lv + 1, top_r + cnt, top_g + cnt, top_b});
                }
                if (top_g + cnt <= G && top_b + cnt <= B)
                {
                    mem[top_lv + 1][top_r][top_g + cnt][top_b + cnt] += coeff(cnt, var) * mem[top_lv][top_r][top_g][top_b];
                    q.push({top_lv + 1, top_r, top_g + cnt, top_b + cnt});
                }
                if (top_b + cnt <= B && top_r + cnt <= R)
                {
                    mem[top_lv + 1][top_r + cnt][top_g][top_b + cnt] += coeff(cnt, var) * mem[top_lv][top_r][top_g][top_b];
                    q.push({top_lv + 1, top_r + cnt, top_g, top_b + cnt});
                }
            }
            else if (var == 3)
            {
                if (top_r + cnt <= R && top_g + cnt <= G && top_b + cnt <= B)
                {
                    mem[top_lv + 1][top_r + cnt][top_g + cnt][top_b + cnt] += coeff(cnt, var) * mem[top_lv][top_r][top_g][top_b];
                    q.push({top_lv+1, top_r+cnt, top_g+cnt, top_b+cnt});
                }
            }
        }
    }

    for(int rr=0; rr<56 ;rr++ ){
        for(int gg=0; gg<56; gg++){
            for(int bb=0; bb<56; bb++){
                ans += mem[N][rr][gg][bb];
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cout << "code start" << endl;
    cin >> N >> R >> G >> B;

    ans = calc2(1, R, G, B);

    cout << ans;

    return 0;
}

/*
64비트. -> 8byte
N <= 10, RGB <=100

1
1 1 : 2
1 1 1 : 3
2 2 : 4
5
2 2 2 : 3 3 : 6
7
4 4 : 8
3 3 3 : 9
5 5 : 10






*/