#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <random>

#define divider 1000000007
#define IMAX 2147483647
using namespace std;

struct node
{
    int sx = 0;
    int ex = 0;
    int sy = 0;
    int ey = 0;
    int cnt = 0;
};

//node* tree;
vector<node> tree;
vector<pair<int, int>> stars;

void calcTree(int h) {//아래에서부터 채우는 함수
    for (int i = h; i < h * 2; i += 2) {
        bool now = (tree[i].cnt != 0);
        bool next = (tree[i + 1].cnt != 0);

        node nw = tree[i];
        node nx = tree[i + 1];
        if (now && next) {
            cout<<"!";
            if (nw.sx < nx.sx) tree[i / 2].sx = nw.sx;
            else tree[i / 2].sx = nx.sx;
            if (nw.ex > nx.ex) tree[i / 2].ex = nw.ex;
            else tree[i / 2].ex = nx.ex;
            if (nw.sy < nx.sy) tree[i / 2].sy = nw.sy;
            else tree[i / 2].sy = nx.sy;
            if (nw.ey > nx.ey) tree[i / 2].ey = nw.ey;
            else tree[i / 2].ey = nx.ey;
            tree[i / 2].cnt = nw.cnt + nx.cnt;
        }
        else if (now && !next) {
            tree[i / 2].sx = nw.sx;
            tree[i / 2].ex = nw.ex;
            tree[i / 2].sy = nw.sy;
            tree[i / 2].ey = nw.ey;
            tree[i / 2].cnt = nw.cnt;
        }
        else if (!now && next) {
            tree[i / 2].sx = nx.sx;
            tree[i / 2].ex = nx.ex;
            tree[i / 2].sy = nx.sy;
            tree[i / 2].ey = nx.ey;
            tree[i / 2].cnt = nx.cnt;
        }
        else {
            tree[i / 2] = { 0,0,0,0,0 };
        }
    }
    if (h > 1) calcTree(h / 2);
}

void printTree(int N) {
    cout << "-----------------\n";
    int c = 1;
    for (int i = 1; i < N; ++i) {
        if (i == c) {
            cout << endl;
            c *= 2;
        }
        cout << tree[i].cnt << " ";
    }
}

int calcLU(int i, int x, int y) {
    int ans = 0;
    if (tree[i].ex < x && tree[i].sy>y) return tree[i].cnt; //전부 좌상에 존재
    if (tree[i].sx >= x || tree[i].ey <= y) return 0; //좌상에 존재하지 않음

    ans += calcLU(i * 2, x, y);
    ans += calcLU(i * 2 + 1, x, y);
    return ans;
}

int calcRU(int i, int x, int y) {
    int ans = 0;
    if (tree[i].sx > x && tree[i].sy > y) return tree[i].cnt;
    if (tree[i].ex <= x || tree[i].ey <= y) return 0; //우상에 존재하지 않음

    ans += calcRU(i * 2, x, y);
    ans += calcRU(i * 2 + 1, x, y);
    return ans;
}

int calcV(int x, int y) {
    return calcLU(1, x, y) * calcRU(1, x, y);
}

void init(int N) {
    for (int i = 0, x, y; i < N; ++i){
        cin >> x >> y;
        stars.push_back(make_pair(x, y));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    
    init(N);
    sort(stars.begin(), stars.end());

    long long int h = 1;

    while (h < N)
        h *= 2;
    
    
    tree.resize(h * 2);

    for (int i = h, s = 0; i < h * 2; ++i){//트리 하단부에 추가하는 코드 O(h) h <= 2^18
        if (s < N / 2){
            tree[i] = { stars[s].first, stars[s].first, stars[s].second, stars[s].second, 1 };
            ++s;
        }
        else{
            if (i < h + h / 2)
                tree[i] = { 0, 0, 0, 0, 0 };
            else{
                if (s < N){
                    tree[i] = { stars[s].first, stars[s].first, stars[s].second, stars[s].second, 1 };
                    ++s;
                }
                else
                    tree[i] = { 0, 0, 0, 0, 0 };
            }
        }
    }

    calcTree(h);
    //printTree(2*h);
    int ans = 0;
    for (auto star : stars) {
        ans += calcV(star.first, star.second);
        while (ans >= divider) ans -= divider;
    }
    cout << ans;
    return 0;
}

/*
한 별에 대해서 그 별보다 x가 작고, y가 큰 별의 수 * x가 크고, y가 더 큰 별의 수
이중 조건 트리?
트리 2개

x 조건
y 조건
?


4*10^10 + 2*10^5

*/