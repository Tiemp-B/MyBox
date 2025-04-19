#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>output;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

struct pos {
    int y;
    int x;
    int dist;

    bool operator<(const pos next) const {
        return dist > next.dist;
    }
};

bool* visit;
int ans = 2147483647;

void DFS(const int graph[11][11], int lv, int now, int far, const int len) {
    if (len-1 == lv) {
        if (ans > far) ans = far;
        return;
    }

    for (int i = 0; i < len; i++) {
        if (visit[i]) continue;
        visit[i] = true;
        DFS(graph, lv + 1, i, far + graph[now][i], len);
        visit[i] = false;
    }
}


void calc(int w, int h) {
    int sy, sx;
    vector<pair<int, int>> dust;
    int mat[20][20] = {};
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if (c == 'o') {
                sy = i;
                sx = j;
            }
            else if (c == '*') {
                // cout<<"["<<i<<", "<<j<<"]\n";
                dust.push_back(make_pair(i, j));
            }
            else if (c == 'x') {
                mat[i][j] = -1;
            }
        }
    }

    int idx_s = dust.size() - 1;

    dust.push_back({ sy, sx });

    int spot_dist[11][11] = {};

    for (int i = 0; i < dust.size(); i++) {
        auto p = dust[i];

        queue<pair<int, int>> q;
        q.push(p);

        int dist[20][20] = {};

        while (!q.empty()) { //BFS
            int y_now = q.front().first;
            int x_now = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int y_new = y_now + dy[d];
                int x_new = x_now + dx[d];
                if (y_new < 0 || y_new >= h || x_new < 0 || x_new >= w)continue;
                if (mat[y_new][x_new] == -1)continue;
                if (y_new == p.first && x_new == p.second) continue;
                if (dist[y_new][x_new] == 0 || dist[y_new][x_new] > dist[y_now][x_now] + 1) {
                    dist[y_new][x_new] = dist[y_now][x_now] + 1;
                    q.push({ y_new, x_new });
                }
            }
        }

        for (int j = 0; j < dust.size(); j++) {
            spot_dist[i][j] = dist[dust[j].first][dust[j].second];
        }
    }

    for (int i = 0; i < dust.size()-1; i++) {
        if (spot_dist[dust.size() - 1][i] == 0) {
            cout << -1 << endl;
            //output.push_back(-1);
            return;
        }
    }

    visit = new bool[11]();
    ans = 2147483647;

    for (int i = 0; i < dust.size() - 1; i++) {
        visit[i] = true;
        DFS(spot_dist, 0, i, spot_dist[dust.size() - 1][i], dust.size() - 1);
        visit[i] = false;
    }
    //output.push_back(ans);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        calc(w, h);
    }

    return 0;
}

/*
DFS를 비트 마스킹으로 했으면 더 쉬웠을듯;


*/