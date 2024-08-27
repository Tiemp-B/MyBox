#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> field(N);
    vector<vector<int>> move(N, vector<int> (M, 0));
    vector<vector<int>> canGo(N, vector<int>(M, 0));
    vector<vector<bool>> onTray(N, vector<bool>(M, 0));
    
    for (int i = 0; i < N; i++)
    {
        cin >> field[i];
    }

    queue<pair<int, int>> tray;
    tray.push(make_pair(0, 0));
    int ans = 0;
    while (!tray.empty())
    {
        auto now = tray.front();
        tray.pop();

        int mv = field[now.first][now.second] - '0';
        for (int d = 0; d < 4; d++)
        {
            int ny = dy[d] * mv + now.first;
            int nx = dx[d] * mv + now.second;
            if (ny >= N || nx >= M || ny < 0 || nx < 0)
                continue;
            if (field[ny][nx] == 'H')
                continue;
            if (canGo[ny][nx] > 0)
            {
                cout << -1;
                return 0;
            }
            canGo[now.first][now.second]++;
            if (move[ny][nx] < move[now.first][now.second]+1)move[ny][nx] = move[now.first][now.second]+1;
            if (onTray[ny][nx])
                continue;
            tray.push(make_pair(ny, nx));
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(move[i][j] > ans) ans = move[i][j];
        }
    }
    cout << ans+1;
    return 0;
}
